/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the file is to defin the European options Class whicis derived from 
* the abstract class Options
* This Classs follows the blue print where core functionalities of option pricing 
* and sensitivities is covered
* 
* Both private data and functions make the design ribust in term os encapsulation
*/

#ifndef EuropeanOptions_H
#define EuropeanOptions_H

#include"Options.h"
#include<vector>
#include<map>
#include <string>
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace OPTIONS
	{
		class EuropeanOptions: public Options
		{
		private:

		/*'Kernel' functions for option calculations
		*/
		/* Function for pricing and calculating sensitivities
		*/
		double CallPrice() const; 
		double PutPrice() const; 
		double CallDelta() const;
		double PutDelta() const;
		double CallGamma() const;
		double PutGamma() const;
		double CallTheta() const;
		double PutTheta() const;
		double CallVega() const;
		double PutVega() const;

		private:
			/*Interest rate
			*/
			double r;
			/*Volatility
			*/
			double sig;
			/*Option Strike
			*/
			double K;
			/*Expiry date
			*/
			double T;

			/*Spot price of the underlying
			*/
			double S;

			/*Cost of Carry
			*/
			double b;

			/*Type of Option
			*/
			std::string optionType;	// Option name (call, put)
		
		private:
			/*Declaration for function for calculation of 
			* Price for both Call and Put
			* Calculation of sensitivities
			* These function are not visible to the user and are encapsulated
			* /*Private function for pricing and calculating sensitivities
			* Call Price
			* Put Price
			* Call Delta
			* Put Delta
			* Call Gamma
			* CallTheta
			* Put Theta
			* Call Vega
			* Call Vega
			* 
			*/
			
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

		public:
			/* Parameter Constructor for Equities
			*/
			EuropeanOptions();
			/* Parameter Constructor for Equities
			*/
			EuropeanOptions(const EuropeanOptions& source_op);
			
			/* Parameter Constructor for Equities
			*/
			EuropeanOptions(const string& optionType, const double& S, const double& r, const double& K, const double& sig, const double& T);
			
			/* Parameter Constructor for other values of cost of carry
			*/
			EuropeanOptions(const string& optionType, const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b);
			virtual ~EuropeanOptions();

			EuropeanOptions& operator = (const EuropeanOptions& source_op);


			/* ******Public Pricing Function **************************************************
			*/
			/*Functions that calculate Options price and sensitivities
			*/
			double Price() const;
			double Delta() const;
			double Gamma() const;
			double Vega() const;
			double Theta() const;

			/*Adding the Put-Call Parity Functions; this valid only for European Options
			*/
			double CallWithParity(const double& putPrice) const;
			double PutWithParity(const double& callPrice) const;

			/*Check if given set of Call and Put prices Satisfy the Parity
			*/
			map<string, double> CheckParity(const double& callPrice, const double& putPrice) const;

			/*Divided differences
			*/
			double DeltaDivDiff(const double& h) const;
			double GammaDivDiff(const double& h) const;

			double SP() const;         
			void SP(const double& newS);

			/*Get Spot price coordinate of the underlying Stock
			*/
			double SK() const;          
			void SK(const double& newK);

			double SIr() const;         
			void SIr(const double& newIr);

			double SVol() const;          
			void SVol(const double& newVol);
			
			double ST() const;          
			void ST(const double& newT);

			double Sb() const;          
			void Sb(const double& newb);

			string SOpt() const;         
			void SOpt(const string& newOpt);
		};
	}
}

#endif


/*
* References:
https://quantnet.com/threads/about-the-data-member.40005/#post-251179
http://www.webwise-scripts.com/c++faq/private-virtuals.html

*/
