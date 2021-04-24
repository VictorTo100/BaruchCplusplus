/*Author: Vishrut Talekar
*/
/* The Purpose of this file is to implement the Pricing Class for European Options
* The Class is derived from Underlying Options class which is blue print to implement 
* pricing as well as Sensitivity functionalities
* 
* This consists of Default Constrcutor:
* Parameter Constructors: 1 for Equities b=r
* and Other with user defined value for b= cost of carry
* 
* The Member function include Private function and Public function for calling the
* Call and Put price as well as Sentivities
* 
* Only high level function are visible to the user and the actual compute function are private
* 
* 
* 
*/


#include <iostream>
#include "EuropeanOptions.h"
#include "Options.h"
#include <cmath>
#include <iostream>
#include <string>
#include <boost/math/distributions/normal.hpp>
#include <vector>
#include <map>
using namespace boost::math;

namespace VISHRUTTALEKAR
{
	namespace OPTIONS
	{
		/*Default Constructor
		*/
		EuropeanOptions::EuropeanOptions():Options(), optionType("Call"), S(1), r(0.01), K(1), sig(0.1), T(0.1), b(r)
		{
			std::cout << "Default Constructor of EuropeanOptions is called\n" << endl;
		}

		/*Custom Constructor for Equities
		*/
		EuropeanOptions::EuropeanOptions(const string& type, const double& spot, const double& ir, const double& strike, const double& vol, const double& exp): Options(), optionType(type), S(spot), r(ir), K(strike), sig(vol), T(exp) // Custom Constructor 
		{
			b = ir; 
			std::cout << "Custom Constructor of EuropeanOptions is called\n" << endl;
		}

		/*Custom Constructor for div yield
		*/
		EuropeanOptions::EuropeanOptions(const string& type, const double& spot, const double& ir, const double& strike, const double& vol, const double& exp, const double& costofcarry) : Options(), optionType(type), S(spot), r(ir), K(strike), sig(vol), T(exp), b(costofcarry)
		{
			
			std::cout << "Custom Constructor of EuropeanOptions is called\n" << endl;
		}

		/*Destructor
		*/
		EuropeanOptions::~EuropeanOptions()
		{
			std::cout << "Destructor of EuropeanOptions is called\n" << endl;
		}

		// ******************* Copy Constructor ****************************************
		EuropeanOptions::EuropeanOptions(const EuropeanOptions& option2) : Options(), optionType(option2.optionType), S(option2.S), r(option2.r), K(option2.K), sig(option2.sig), T(option2.T), b(option2.b) // Custom Constructor 
		{
			std::cout << "Copy Constructor of EuropeanOptions is called\n" << endl;
		}


		// *******************Overload the Assignment Operator****************************************
		EuropeanOptions& EuropeanOptions::operator = (const EuropeanOptions& source_op) 
		{

			if (this == &source_op)
			{
				return *this;
			}
			else
			{
				Options::operator=(source_op);

				r = source_op.r;		// Interest rate
				sig = source_op.sig;	// Volatility
				K = source_op.K;		// Strike price
				T = source_op.T;		// Expiry date
				S = source_op.S;       // Price of the underlying asset
				b = source_op.b;

				return *this;
			}

		}

		/* ************************* Define Getter and Setters **********************************************
		*/
		/*Getters
		*/
		/*Get Spot Price of the underlying
		*/
		double EuropeanOptions::SP() const 
		{ 
			return S; 
		}
		/*Get the Strike Price
		*/
		double EuropeanOptions::SK() const 
		{ 
			return K; 
		}
		/*Get the Interest Rate
		*/
		double EuropeanOptions::SIr() const 
		{ 
			return r; 
		}
		/*Get the Volatility
		*/
		double EuropeanOptions::SVol() const 
		{ 
			return sig; 
		}
		/*Get the Cost of Carry
		*/
		double EuropeanOptions::Sb() const 
		{ 
			return b; 
		}

		/*Get the Expiry
		*/
		double EuropeanOptions::ST() const 
		{ 
			return T; 
		}
		/*Get the Option Type
		*/
		string EuropeanOptions::SOpt() const 
		{ 
			return optionType; 
		}

		/*Setters
		*/
		/* Set Spot price
		*/
		void EuropeanOptions::SP(const double& newS)
		{
			S = newS;
		}
		/* Set Strike price
		*/
		void EuropeanOptions::SK(const double& newK)
		{
			K = newK;
		}
		/* Set Expiry
		*/
		void EuropeanOptions::ST(const double& newT)
		{
			T = newT;
		}
		/*Set The Cost of Carry
		*/
		void EuropeanOptions::Sb(const double& newb)
		{
			b = newb;
		}
		/*Set Volatility
		*/
		void EuropeanOptions::SVol(const double& newVol)
		{
			sig = newVol;
		}
		/*Set Interest rate
		*/
		void EuropeanOptions::SIr(const double& newIr)
		{
			r = newIr;
		}

		/*Set the Option Type
		*/
		void EuropeanOptions::SOpt(const string& newOpt)
		{
			optionType = newOpt;
		}




		/* ************************* Define Member Functions **********************************************
		*/
		
		/*Pricing function
		* calling the actual pricing function with Parameters Overloaded functions
		*/
		/*Pricing- Call Price
		* calling the actual pricing function with Parameters Overloaded functions
		*/
		double EuropeanOptions::CallPrice() const
		{
			return CallPrice(S, r, K, sig, T, b);
		}
		/*Put Price
		* calling the actual pricing function with Parameters Overloaded functions
		*/
		double EuropeanOptions::PutPrice() const
		{
			return PutPrice(S, r, K, sig, T, b);
		}
		/*Call delta
		* calling the actual pricing  and Sensitivities functions with Parameters Overloaded functions
		*/
		double EuropeanOptions::CallDelta() const
		{
			return CallDelta(S, r, K, sig, T, b);
		}
		/*Delta function
		* calling the actual calculating/pricing function with Parameters Overloaded functions
		*/
		double EuropeanOptions::PutDelta() const
		{
			return PutDelta(S, r, K, sig, T, b);
		}
		/*Gamma function
		* calling the actual calculating/pricing function with Parameters Overloaded functions
		*/
		double EuropeanOptions::CallGamma() const
		{
			return CallGamma(S, r, K, sig, T, b);
		}
		/*Gamma function
		* calling the actual calculating/pricing function with Parameters Overloaded functions
		*/
		double EuropeanOptions::PutGamma() const
		{
			return PutGamma(S, r, K, sig, T, b);
		}
		/*Vega function
		* calling the actual calculating/pricing function with Parameters Overloaded functions
		*/
		double EuropeanOptions::CallVega() const
		{
			return CallVega(S, r, K, sig, T, b);
		}
		/*Vega function
		* calling the actual calculating/pricing function with Parameters Overloaded functions
		*/
		double EuropeanOptions::PutVega() const
		{
			return PutVega(S, r, K, sig, T, b);
		}
		/*Vega function
		* calling the actual calculating/pricing function with Parameters Overloaded functions
		*/
		double EuropeanOptions::CallTheta() const
		{
			return CallTheta(S, r, K, sig, T, b);
		}
		/*Vega function
		* calling the actual calculating/pricing function with Parameters Overloaded functions
		*/
		double EuropeanOptions::PutTheta() const
		{
			return PutTheta(S, r, K, sig, T, b);
		}

		/* High Level Pricing function; it call the relevant Pricing function internally 
		* depending on the Call or Put Object
		*/
		double EuropeanOptions::Price() const
		{

			if (optionType == "Call")
			{
				cout << "Calling the Call Pricer\n";
				return CallPrice();
			}
			else
			{
				cout << "Calling the Put Pricer\n";
				return PutPrice();
			}
		}
		/* High Level Sensitivities -Delta function; it call the relevant Pricing function internally
		* depending on the Call or Put Object
		*/
		double EuropeanOptions::Delta() const
		{

			if (optionType == "Call")
			{
				cout << "Calling the Call Delta\n";
				return CallDelta();
			}
			else
			{
				cout << "Calling Put Delta\n";
				return PutDelta();
			}
		}
		/* High Level Sensitivities -Vega function; it call the relevant Pricing function internally
		* depending on the Call or Put Object
		*/
		double EuropeanOptions::Vega() const
		{

			if (optionType == "Call")
			{
				cout << "Calling the Call Vega\n";
				return CallVega();
			}
			else
			{
				cout << "Calling the Put Vega\n";
				return PutVega();
			}
		}
		/* High Level Sensitivities -Gamma function; it call the relevant Pricing function internally
		* depending on the Call or Put Object
		*/
		double EuropeanOptions::Gamma() const
		{

			if (optionType == "Call")
			{
				cout << "Calling the Call Gamma\n";
				return CallGamma();
			}
			else
			{
				cout << "Calling the Put Gamma\n";
				return PutGamma();
			}
		}
		/* High Level Sensitivities -Delta function; it call the relevant Pricing function internally
		* depending on the Call or Put Object
		*/
		double EuropeanOptions::Theta() const
		{

			if (optionType == "Call")
			{
				cout << "Calling the Call Theta\n";
				return CallTheta();
			}
			else
			{
				cout << "Calling the Put Theta\n";
				return PutTheta();
			}
		}


		// Kernel Functions (Haug)

		/* All the function take in 
		* Spot
		* Strike
		* Interest Rate
		* Volatility
		* Expiry
		* Cost of Carry
		*/
		// Definition of Call Price
		double EuropeanOptions::CallPrice(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
		/* Args:
		* Spot
		* Strike
		* Interest Rate
		* Volatility
		* Expiry
		* Cost of Carry
		* Returns: Call Price
		*/

			
			double tmp = sig * sqrt(T);
			/*Calculate d1 and d2
			*/
			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			double d2 = d1 - tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return (S * exp((b - r) * T) * cdf(myNormal, d1)) - (K * exp(-r * T) * cdf(myNormal, d2));

		}

		// Definition of Put Price
		double EuropeanOptions::PutPrice(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{

			double tmp = sig * sqrt(T);
			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			double d2 = d1 - tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return (K * exp(-r * T) * cdf(myNormal, -d2)) - (S * exp((b - r) * T) * cdf(myNormal, -d1));

		}

		// Defintion of Call Delta
		double EuropeanOptions::CallDelta(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return exp((b - r) * T) * cdf(myNormal,d1);
		}

		// Definition of Put Delta
		double EuropeanOptions::PutDelta(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return exp((b - r) * T) * (cdf(myNormal, d1) - 1.0);
		}

		// Definition of Call Gamma
		double EuropeanOptions::CallGamma(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return (pdf(myNormal, d1)*exp((b - r) * T))/(S * sig * sqrt(T));
		}

		// Definition of Put Gamma
	
		double EuropeanOptions::PutGamma(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			return CallGamma(S, r, K, sig, T, b);
		}

		// Definition of Call Vega
		double EuropeanOptions::CallVega(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return (pdf(myNormal, d1) * exp((b - r) * T) * S * sqrt(T));
		}

		// Definition of Put Vega
		double EuropeanOptions::PutVega(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			return CallVega(S, r, K, sig, T, b);
		}

		// Definition of Call Theta
		double EuropeanOptions::CallTheta(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			normal_distribution<> myNormal(0, 1);
			double tmp = sig * sqrt(T);
			/*Calculate d1 and d2
			*/
			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			double d2 = d1 - tmp;

			double t1 = (S * exp((b - r) * T) * pdf(myNormal, d1) * sig * 0.5) / sqrt(T);
			double t2 = (b - r) * (S * exp((b - r) * T) * cdf(myNormal, d1));
			double t3 = r * K * exp(-r * T) * cdf(myNormal, d2);

			return -(t1 + t2 + t3);
		}

		double EuropeanOptions::PutTheta(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			normal_distribution<> myNormal(0, 1);
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			double d2 = d1 - tmp;

			double t1 = (S * exp((b - r) * T) * pdf(myNormal, d1) * sig * 0.5) / sqrt(T);
			double t2 = (b - r) * (S * exp((b - r) * T) * cdf(myNormal, -d1));
			double t3 = r * K * exp(-r * T) * cdf(myNormal, -d2);

			return t2 + t3 - t1;
		}

		// Define the function to get Price of the Call (same strike and expiry) using the Put Price
		double EuropeanOptions::CallWithParity(const double& putPrice) const
		{
			double callPrice;

			callPrice = putPrice + S - K * exp(-r * T);
			
			return callPrice;

		}

		double EuropeanOptions::PutWithParity(const double& callPrice) const
		{
			double putPrice;

			putPrice = callPrice + K * exp(-r * T) - S;
			return putPrice;

		}

		/*Function to get check Put Call Parity
		* Check it both ways
		*/
		map<string, double> EuropeanOptions::CheckParity(const double& callPrice, const double& putPrice) const
		{
			double parityValue;
			double callMinusPut;
			map<string, double> results;

			parityValue = S - K * exp(-r * T);
			callMinusPut = callPrice - putPrice;

			results["Parity Value"] = parityValue;
			results["Call Put Difference"] = callMinusPut;
			
			return results;

		}

		/*Divided differences
		*/
		/*Calculate Delta using the Divided Differences
		*/
		double EuropeanOptions::DeltaDivDiff(const double& h) const
		{
			/*Declare new option object
			*/
			EuropeanOptions opt_1(*this);
			opt_1.SP(SP() + h);
			
			EuropeanOptions opt_2(*this);
			opt_2.SP(SP() - h);
			/*Get Option Price with +h
			*/
			double price_1 = opt_1.Price();
			/*Get Option Price with -h
			*/
			double price_2 = opt_2.Price();
			/*Calculate the diff delta
			*/
			double diff_delta = (price_1 - price_2) / 2 * h;

			return diff_delta;

		}

		/*Divided differences
		*/
		/*Calculate Delta using the Divided Differences
		*/
		double EuropeanOptions::GammaDivDiff(const double& h) const
		{
			/*Declare new option object
			*/
			
			EuropeanOptions opt_1(*this);
			opt_1.SP(SP() + h);
			
			EuropeanOptions opt_2(*this);
			opt_2.SP(SP() - h);
			/*Get Option Price with +h
			*/
			double price_1 = opt_1.Price();
			/*Get Option Price with +h
			*/
			double price_2 = opt_2.Price();

			double price_3 = Price();
			/*Calculate the diff delta
			*/
			double diff_gamma = (price_1 - 2*(price_3) + price_2) /(pow(h,2));

			return diff_gamma;

		}


	}
}





