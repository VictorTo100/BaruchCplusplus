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
#include "PerpetualAmericanOptions.h"
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
		PerpetualAmericanOptions::PerpetualAmericanOptions() :Options(), optionType("Call"), S(60), r(0.08), K(65), sig(0.30), b(r)
		{
			std::cout << "Default Constructor of PerpetualAmericanOptions is called\n" << endl;
		}

		/*Custom Constructor
		*/
		PerpetualAmericanOptions::PerpetualAmericanOptions(const string& type, const double& spot, const double& ir, const double& strike, const double& vol, const double& cost_of_carry) : Options(), optionType(type), S(spot), r(ir), K(strike), sig(vol), b(cost_of_carry)
		{
			std::cout << "Custom Constructor of PerpetualAmericanOptions is called\n" << endl;
		}

		// Destructor
		PerpetualAmericanOptions::~PerpetualAmericanOptions()
		{
			std::cout << "Destructor of PerpetualAmericanOptions is called\n" << endl;
		}

		// ******************* Copy Constructor ****************************************
		PerpetualAmericanOptions::PerpetualAmericanOptions(const PerpetualAmericanOptions& option2) : Options(), optionType(option2.optionType), S(option2.S), r(option2.r), K(option2.K), sig(option2.sig), b(option2.b) // Custom Constructor 
		{
			std::cout << "Copy Constructor of PerpetualAmericanOptions is called\n" << endl;
		}


		// *******************Overload the Assignment Operator****************************************
		PerpetualAmericanOptions& PerpetualAmericanOptions::operator = (const PerpetualAmericanOptions& source_op)
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
				S = source_op.S;       // Price of the underlying asset
				b = source_op.r;


				return *this;
			}

		}

		/* ************************* Define Getter and Setters **********************************************
		*/
		/*Getters
		*/
		/*Get Spot Price of the underlying
		*/
		double PerpetualAmericanOptions::SP() const
		{
			return S;
		}
		/*Get the Strike Price
		*/
		double PerpetualAmericanOptions::SK() const
		{
			return K;
		}
		/*Get the Interest rate
		*/
		double PerpetualAmericanOptions::SIr() const
		{
			return r;
		}
		/*Get the Volatility
		*/
		double PerpetualAmericanOptions::SVol() const
		{
			return sig;
		}
		/*Get the Cost of carry
		*/
		double PerpetualAmericanOptions::Sb() const
		{
			return b;
		}
		/*Get the Strike Price
		*/
		
		string PerpetualAmericanOptions::SOpt() const
		{
			return optionType;
		}

		/*Setters
		* Spot
		* Interest Rate
		* Strike
		* Cost of carry
		*/
		void PerpetualAmericanOptions::SP(const double& newS)
		{
			S = newS;
		}

		void PerpetualAmericanOptions::SK(const double& newK)
		{
			K = newK;
		}

		void PerpetualAmericanOptions::Sb(const double& newb)
		{
			b = newb;
		}

		void PerpetualAmericanOptions::SVol(const double& newVol)
		{
			sig = newVol;
		}


		void PerpetualAmericanOptions::SIr(const double& newIr)
		{
			r = newIr;
		}

		void PerpetualAmericanOptions::SOpt(const string& newOpt)
		{
			optionType = newOpt;
		}

		/* ************************* Define Member Functions **********************************************
		*/


		/* The important function are the pricing and sensitivities
		*/
		double PerpetualAmericanOptions::CallPrice() const
		{
			return CallPrice(S, r, K, sig, b);
		}

		double PerpetualAmericanOptions::PutPrice() const
		{
			return PutPrice(S, r, K, sig, b);
		}

		double PerpetualAmericanOptions::Price() const
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

		/* Place holders created as a part of contract between the abstract Option base class and derived class
		*/
	
		double PerpetualAmericanOptions::CallDelta() const
		{
			return CallDelta(S, r, K, sig, b);
		}

		double PerpetualAmericanOptions::PutDelta() const
		{
			return PutDelta(S, r, K, sig, b);
		}

		double PerpetualAmericanOptions::CallGamma() const
		{
			return CallGamma(S, r, K, sig, b);
		}

		double PerpetualAmericanOptions::PutGamma() const
		{
			return PutGamma(S, r, K, sig, b);
		}

		double PerpetualAmericanOptions::CallVega() const
		{
			return CallVega(S, r, K, sig, b);
		}

		double PerpetualAmericanOptions::PutVega() const
		{
			return PutVega(S, r, K, sig, b);
		}

		double PerpetualAmericanOptions::CallTheta() const
		{
			return CallTheta(S, r, K, sig, b);
		}

		double PerpetualAmericanOptions::PutTheta() const
		{
			return PutTheta(S, r, K, sig, b);
		}
 
		double PerpetualAmericanOptions::Delta() const
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

		double PerpetualAmericanOptions::Vega() const
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

		double PerpetualAmericanOptions::Gamma() const
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

		double PerpetualAmericanOptions::Theta() const
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


		/*Definition of Call Price for perpetual American Options
		*/
		double PerpetualAmericanOptions::CallPrice(const double& S, const double& r, const double& K, const double& sig, const double& b) const
		{
			double y_1 = 0.5 - (b/pow(sig, 2)) + sqrt(pow(((b/ pow(sig, 2))-(0.5)),2)+((2*r)/(pow(sig,2))));

			double callP = (K/(y_1-1))*(pow((((y_1-1)/y_1)*(S/K)),y_1)) ;
			return callP;

		}

		/*Definition of Put Price for perpetual American Options
		*/
		double PerpetualAmericanOptions::PutPrice(const double& S, const double& r, const double& K, const double& sig, const double& b) const
		{
			double y_2 = 0.5 - (b / pow(sig, 2)) - sqrt(pow(((b / pow(sig, 2)) - (0.5)), 2) + ((2 * r) / (pow(sig, 2))));

			double putP = (K / (1-y_2)) * (pow((((y_2 - 1) / y_2) * (S / K)), y_2));

			return putP;
		}

		/* Place holders created as a part of contract between the abstract Option base class and derived class
		*/
		// Defintion of Call Delta
		double PerpetualAmericanOptions::CallDelta(const double& S, const double& r, const double& K, const double& sig,  const double& b) const
		{
			cout << "There is no implementation, this is just a place holder";
			double call_delta = 0;

			return call_delta;
		}

		// Definition of Put Delta
		double PerpetualAmericanOptions::PutDelta(const double& S, const double& r, const double& K, const double& sig, const double& b) const
		{
			cout << "There is no implementation, this is just a place holder";
			double put_delta = 0;

			return put_delta;
		}

		// Definition of Call Gamma
		double PerpetualAmericanOptions::CallGamma(const double& S, const double& r, const double& K, const double& sig,const double& b) const
		{
			cout << "There is no implementation, this is just a place holder";
			double call_gamma = 0;

			return call_gamma;
		}

		// Definition of Put Gamma

		double PerpetualAmericanOptions::PutGamma(const double& S, const double& r, const double& K, const double& sig,  const double& b) const
		{
			return CallGamma(S, r, K, sig, b);
		}

		// Definition of Call Vega
		double PerpetualAmericanOptions::CallVega(const double& S, const double& r, const double& K, const double& sig, const double& b) const
		{
			cout << "There is no implementation, this is just a place holder";
			double call_vega = 0;

			return call_vega;
		}

		// Definition of Put Vega
		double PerpetualAmericanOptions::PutVega(const double& S, const double& r, const double& K, const double& sig,  const double& b) const
		{
			return CallVega(S, r, K, sig, b);
		}

		// Definition of Call Theta
		double PerpetualAmericanOptions::CallTheta(const double& S, const double& r, const double& K, const double& sig, const double& b) const
		{
			cout << "There is no implementation, this is just a place holder";
			double call_theta = 0;

			return call_theta;
		}

		double PerpetualAmericanOptions::PutTheta(const double& S, const double& r, const double& K, const double& sig, const double& b) const
		{
			cout << "There is no implementation, this is just a place holder";
			double put_theta = 0;

			return put_theta;
		}

	}
}
