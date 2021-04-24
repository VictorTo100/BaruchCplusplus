#ifndef EuropeanEquityOptions_H
#define EuropeanEquityOptions_H

#include"Options.h"
#include"EuropeanEquityOptions.h"
#include<vector>
#include<map>
#include <string>
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace OPTIONS
	{
		class EuropeanEquityOptions: public Options
		{
		private:

		// 'Kernel' functions for option calculations
		double CallPrice() const; // Function to calculate the Call Price
		double PutPrice() const;                     // Function to calculate the Call Price
		double CallDelta() const;
		double PutDelta() const;
		double CallGamma() const;
		double PutGamma() const;
		double CallTheta() const;
		double PutTheta() const;
		double CallVega() const;
		double PutVega() const;

		private:
			double r;		// Interest rate
			double sig;		// Volatility
			double K;		// Strike price
			double T;		// Expiry date
			double S;       // Price of the underlying asset
			double b;		// Cost of carry
			std::string optionType;	// Option name (call, put)
		
		private:
			double CallPrice(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const;
			double PutPrice(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const; 
			double CallDelta(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const;
			double PutDelta(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const;
			double CallGamma(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const;
			double PutGamma(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const;
			double CallTheta(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const;
			double PutTheta(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const;
			double CallVega(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const;
			double PutVega(const double& S, const double& ir, const double& strike, const double& sig, const double& T, const double& b) const;

		public:	// Public functions
			EuropeanEquityOptions();							// Default call option
			EuropeanEquityOptions(const EuropeanEquityOptions& option2);	// Copy constructor
			EuropeanEquityOptions(const string& optionType, const double& S, const double& r, const double& K, const double& sig, const double& T);	// Customer Constructor with all parameters
			virtual ~EuropeanEquityOptions();

			EuropeanEquityOptions& operator = (const EuropeanEquityOptions& option2);


			// ************************************************ Pricing Function **************************************************
			/*Functions that calculate Options price and sensitivities
			*/
			double Price() const;
			double Delta() const;
			double Gamma() const;
			double Vega() const;
			double Theta() const;

			// Adding the Put-Call Parity Functions; this valid only for European Options

			double CallWithParity(const double& putPrice) const;
			double PutWithParity(const double& callPrice) const;

			// Check if given set of Call and Put prices Satisfy the Parity 

			map<string, double> CheckParity(const double& callPrice, const double& putPrice) const;


			double SP() const;          // Get Spot price coordinate of the underlying Stock 
			void SP(const double& newS) {S = newS; } // Set Spot price of the underlying Stock

			double SK() const;          // Get Spot price coordinate of the underlying Stock 
			void SK(const double& newK) { K = newK; } // Set Spot price of the underlying Stock

			double SIr() const;          // Get Spot price coordinate of the underlying Stock 
			void SIr(const double& newIr) { r = newIr; } // Set Spot price of the underlying Stock

			double SVol() const;          // Get Spot price coordinate of the underlying Stock 
			void SVol(const double& newVol) { sig = newVol; } // Set Spot price of the underlying Stock
			
			double ST() const;          // Get Spot price coordinate of the underlying Stock 
			void ST(const double& newT) { T = newT; } // Set Spot price of the underlying Stock

			double Sb() const;          // Get Spot price coordinate of the underlying Stock 
			void Sb(const double& newb) { b = newb; } // Set Spot price of the underlying Stock

			string SOpt() const;          // Get Spot price coordinate of the underlying Stock 
			void SOpt(const string& newOpt) { optionType = newOpt; } // Set Spot price of the underlying Stock
													  
			// Functions that calculate option price and sensitivities
			
		};

		// Inline getters and setter for optimization

		inline double EuropeanEquityOptions::SP() const { return S;}
		inline double EuropeanEquityOptions::SK() const { return K; }
		inline double EuropeanEquityOptions::SIr() const { return r; }
		inline double EuropeanEquityOptions::SVol() const { return sig; }
		inline double EuropeanEquityOptions::Sb() const { return b; }
		inline double EuropeanEquityOptions::ST() const { return T; }
		inline string EuropeanEquityOptions::SOpt() const { return optionType; }

	}

}


#endif


/*
* References:
https://quantnet.com/threads/about-the-data-member.40005/#post-251179
http://www.webwise-scripts.com/c++faq/private-virtuals.html

*/
