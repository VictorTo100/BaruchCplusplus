// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//

#include "OptionData.h" 
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include <cmath>
#include <iostream>
#include<vector>
#include<boost/tuple/tuple.hpp>
#include<boost/tuple/tuple_io.hpp>
#include<map>

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors

	std::cout << std::endl << "Size of vector is " << myList.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	typename std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
		std::cout << *i << ",";

	}

	std::cout << "]\n";
}


// Definition for function to calculate Standard deviation and Standard Error

vector<double> CalcSDSE(const std::vector<double>& price, const double& r, const double& T)
{  

	double sumPriceSquare = 0.0;
	double sumPrice = 0.0;
	vector<double> sdse_result(2);

	for(int i = 0; i<price.size(); i++)
	{
		sumPriceSquare += price[i]*price[i];
		sumPrice += price[i];
	}

	int M = price.size();
	double SD = (sqrt(sumPriceSquare - (1.0 / M) * sumPrice * sumPrice) * exp(-2 * r * T)) / (M - 1);
	double SE = SD / sqrt(M);

	sdse_result[0] = SD;
	sdse_result[1] = SE;

	return sdse_result;
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term

		return (data->r) * X; // r - D
	}


	double diffusion(double t, double X)
	{ // Diffusion term

		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);

	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method

		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV)*pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace


int main()
{
	std::cout << "1 factor MC with explicit Euler\n";
	
	// Create a vector of a vector for batch_1 and batch_2 data 
	std::vector<std::map<std::string, double>> batch_data(2);
	std::map<string, double> batch_1;
	std::map<string, double> batch_2;
	batch_1["K"] = 65; batch_1["T"] = 0.25; batch_1["r"] = 0.08; batch_1["sig"] = 0.30; batch_1["S"] = 60;
	batch_2["K"] = 100; batch_2["T"] = 1.0; batch_2["r"] = 0.0; batch_2["sig"] = 0.2; batch_2["S"] = 100;

	batch_data[0] = batch_1;
	batch_data[1] = batch_2;

	OptionData myOption;

	long N = 100;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;

	long NSim = 50000;
	std::cout << "Number of simulations: ";
	std::cin >> NSim;

	for (int j = 0; j < batch_data.size(); j++)
	{
		myOption.K = batch_data[j]["K"];
		myOption.T = batch_data[j]["T"];
		myOption.r = batch_data[j]["r"];
		myOption.sig = batch_data[j]["sig"];
		double S_0 = batch_data[j]["S"];

		
		// Create the basic SDE (Context class)
		Range<double> range(0.0, myOption.T);
		double VOld = S_0;
		double VNew;

		std::vector<double> x = range.mesh(N);

		std::vector<double> callPriceVector;
		std::vector<double> putPriceVector;
		// V2 mediator stuff
		
		double k = myOption.T / double(N);
		double sqrk = sqrt(k);

		// Normal random number
		double dW;
		double price_call = 0.0;	// Option price
		double price_put  = 0.0;

		// NormalGenerator is a base class
		NormalGenerator* myNormal = new BoostNormal();

		using namespace SDEDefinition;
		SDEDefinition::data = &myOption;

		std::vector<double> res;
		int coun = 0; // Number of times S hits origin

		// A.
		for (long i = 1; i <= NSim; ++i)
		{ // Calculate a path at each iteration

			if ((i / 10000) * 10000 == i)
			{// Give status after each 1000th iteration

				std::cout << i << std::endl;
			}

			VOld = S_0;

			for (unsigned long index = 1; index < x.size(); ++index)
			{

				// Create a random number
				dW = myNormal->getNormal();

				// The FDM (in this case explicit Euler)
				VNew = VOld + (k * drift(x[index - 1], VOld))
					+ (sqrk * diffusion(x[index - 1], VOld) * dW);

				VOld = VNew;

				// Spurious values
				if (VNew <= 0.0) coun++;
			}
			// Calculation for Call Option
			myOption.type = 1;	// Put -1, Call +1
			double tmp_1 = myOption.myPayOffFunction(VNew);
			price_call += (tmp_1) / double(NSim); // Average price => sum(price/nsim)
			callPriceVector.push_back(price_call);

			// Calculation for the Put Option
			myOption.type = -1;	// Put -1, Call +1
			double tmp_2 = myOption.myPayOffFunction(VNew);
			price_put += (tmp_2) / double(NSim); // Average price => sum(price/nsim)
			putPriceVector.push_back(price_put);
		}

		// D. Finally, discounting the average price
		price_call *= exp(-myOption.r * myOption.T);
		price_put *= exp(-myOption.r * myOption.T);

		// Cleanup; V2 use scoped pointer
		delete myNormal;

		std::cout << "Price of Call, after discounting: " << price_call << "\n" << std::endl;
		std::cout << "Price of Put, after discounting: " << price_put << "\n" << std::endl;
		std::cout << "Number of times origin is hit: " << coun << endl;

		// Calculate SD and SE for call price for a particular run parameter of NT and NSim

		vector<double> callSDSE = CalcSDSE(callPriceVector, myOption.r, myOption.T);
		vector<double> putSDSE = CalcSDSE(putPriceVector, myOption.r, myOption.T);

		std::cout << "The value of SD and SE of Call for batch: " << j+1 <<" for the parameters: NSim: " << NSim << " and NT: " << N << " is , SD: " << callSDSE[0] << " SE: " << callSDSE[1] << "\n" << endl;
		std::cout << "The value of SD and SE of Put for batch: " << j+1 << " for the parameters: NSim: " << NSim << " and NT: " << N << " is , SD: " << putSDSE[0] << " SE: " << putSDSE[1] << "\n" << endl;

	}
	return 0;
}

/*
Reference
https://quantnet.com/threads/typo-in-testmc-cpp.45623/
https://quantnet.com/threads/question-about-creating-a-generic-function-with-vector-input.38611/
https://quantnet.com/threads/generic-functions-are-necessary.31746/
https://quantnet.com/threads/implementation-of-sd-and-se.21184/
https://quantnet.com/threads/sd-and-se-results.43782/
https://quantnet.com/threads/typo-in-sd-formula.14424/

*/