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

			/*'Kernel' functions for option calculations
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
			PerpetualAmericanOptions();
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

			// Get Spot price coordinate of the underlying Stock 
			double SK() const;
			void SK(const double& newK);

			double SIr() const;
			void SIr(const double& newIr);

			double SVol() const;
			void SVol(const double& newVol);

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

