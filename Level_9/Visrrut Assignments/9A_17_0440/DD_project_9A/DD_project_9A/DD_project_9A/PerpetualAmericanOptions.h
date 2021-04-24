/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the file is to defin the Perpetual options Class whicis derived from
* the abstract class Options
* This Class follows the blue print where core functionalities of option pricing
* and sensitivities is covered
*
* Both private data and functions make the design robust in term of encapsulation
* 
* Please not the certain formula and functionalities are not available for Perpetual American options
* But had to inherit as part of the contract with abstract class
*/


#ifndef PerpetualAmericanOptions_H
#define PerpetualAmericanOptions_H

#include"Options.h"
#include<vector>
#include<map>
#include <string>
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace OPTIONS
	{
		class PerpetualAmericanOptions : public Options
		{
		private:

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
			/*Private function for pricing and calculating sensitivities
			* Declaration for function for calculation of 
			* Price for both Call and Put
			* Calculation of sensitivities
			* These function are not visible to the user and are encapsulated
			* 
			* Call Price
			* Put Price
			* Call Delta
			* Put Delta
			* Call Gamma
			* CallTheta
			* Put Theta
			* Call Vega
			* Call Vega
			*/
			double CallPrice(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			double PutPrice(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			double CallDelta(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			double PutDelta(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			double CallGamma(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			double PutGamma(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			double CallTheta(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			double PutTheta(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			double CallVega(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			double PutVega(const double& S, const double& ir, const double& strike, const double& sig, const double& b) const;
			
		public:
			/*Canonical header file 
			*/
			/*Default Constructor
			*/
			PerpetualAmericanOptions();
			/*Copy Constructor
			*/
			PerpetualAmericanOptions(const PerpetualAmericanOptions& option2);
			PerpetualAmericanOptions(const string& optionType, const double& S, const double& r, const double& K, const double& sig, const double& b);
			virtual ~PerpetualAmericanOptions();

			PerpetualAmericanOptions& operator = (const PerpetualAmericanOptions& option2);


			/*******Public Pricing Function **************************************************
			*/
			/*Functions that calculate Options price and sensitivities
			*/
			double Price() const;
			double Delta() const;
			double Gamma() const;
			double Vega() const;
			double Theta() const;

			/***************************Getter and Setters **************************************************
			*/
			double SP() const;
			void SP(const double& newS);

			/*Get  and set Spot price coordinate of the underlying Stock
			*/
			double SK() const;
			void SK(const double& newK);

			/*Get and set the Interest rate  price coordinate of the underlying Stock
			*/
			double SIr() const;
			void SIr(const double& newIr);

			/*Get and set volatility of the underlying Stock
			*/
			double SVol() const;
			void SVol(const double& newVol);

			/*Get and set the cost of carry
			*/
			double Sb() const;
			void Sb(const double& newb);

			/*Get and set underlying option type
			*/
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

