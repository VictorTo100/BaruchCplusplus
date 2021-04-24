
#include <iostream>
#include "EuropeanEquityOptions.h"
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
		// Default Constructor
		EuropeanEquityOptions::EuropeanEquityOptions() :Options(), optionType("Call"), S(60), r(0.08), K(65), sig(0.30), T(0.25), b(r)
		{
			std::cout << "Default Constructor of EuropeanEquityOptions is called\n" << endl;
		}

		// Custom Constructor
		EuropeanEquityOptions::EuropeanEquityOptions(const string& type, const double& spot, const double& ir, const double& strike, const double& vol, const double& exp) : Options(), optionType(type), S(spot), r(ir), K(strike), sig(vol), T(exp) // Custom Constructor 
		{
			b = r;
			std::cout << "Custom Constructor of EuropeanEquityOptions is called\n" << endl;
		}

		// Destructor
		EuropeanEquityOptions::~EuropeanEquityOptions()
		{
			std::cout << "Destructor of EuropeanEquityOptions is called\n" << endl;
		}

		// ******************* Copy Constructor ****************************************
		EuropeanEquityOptions::EuropeanEquityOptions(const EuropeanEquityOptions& option2) : Options(), optionType(option2.optionType), S(option2.S), r(option2.r), K(option2.K), sig(option2.sig), T(option2.T), b(option2.b) // Custom Constructor 
		{
			std::cout << "Copy Constructor of EuropeanEquityOptions is called\n" << endl;
		}


		// *******************Overload the Assignment Operator****************************************
		EuropeanEquityOptions& EuropeanEquityOptions::operator = (const EuropeanEquityOptions& source_op)
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
				b = source_op.r;


				return *this;
			}

		}

		// ************************* Define Member Functions **********************************************


		double EuropeanEquityOptions::CallPrice() const
		{
			return CallPrice(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::PutPrice() const
		{
			return PutPrice(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::CallDelta() const
		{
			return CallDelta(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::PutDelta() const
		{
			return PutDelta(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::CallGamma() const
		{
			return CallGamma(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::PutGamma() const
		{
			return PutGamma(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::CallVega() const
		{
			return CallVega(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::PutVega() const
		{
			return PutVega(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::CallTheta() const
		{
			return CallTheta(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::PutTheta() const
		{
			return PutTheta(S, r, K, sig, T, b);
		}

		double EuropeanEquityOptions::Price() const
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

		double EuropeanEquityOptions::Delta() const
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

		double EuropeanEquityOptions::Vega() const
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

		double EuropeanEquityOptions::Gamma() const
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

		double EuropeanEquityOptions::Theta() const
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


		// Definition of Call Price
		double EuropeanEquityOptions::CallPrice(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{

			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			double d2 = d1 - tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return (S * exp((b - r) * T) * cdf(myNormal, d1)) - (K * exp(-r * T) * cdf(myNormal, d2));

		}

		// Definition of Put Price
		double EuropeanEquityOptions::PutPrice(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{

			double tmp = sig * sqrt(T);
			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			double d2 = d1 - tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return (K * exp(-r * T) * cdf(myNormal, -d2)) - (S * exp((b - r) * T) * cdf(myNormal, -d1));

		}

		// Defintion of Call Delta
		double EuropeanEquityOptions::CallDelta(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return exp((b - r) * T) * cdf(myNormal, d1);
		}

		// Definition of Put Delta
		double EuropeanEquityOptions::PutDelta(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return exp((b - r) * T) * (cdf(myNormal, d1) - 1.0);
		}

		// Definition of Call Gamma
		double EuropeanEquityOptions::CallGamma(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return (pdf(myNormal, d1) * exp((b - r) * T)) / (S * sig * sqrt(T));
		}

		// Definition of Put Gamma

		double EuropeanEquityOptions::PutGamma(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			return CallGamma(S, r, K, sig, T, b);
		}

		// Definition of Call Vega
		double EuropeanEquityOptions::CallVega(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			normal_distribution<> myNormal(0, 1); // Generate standard normal and take the cumulative distribution function as required. 

			return (pdf(myNormal, d1) * exp((b - r) * T) * S * sqrt(T));
		}

		// Definition of Put Vega
		double EuropeanEquityOptions::PutVega(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			return CallVega(S, r, K, sig, T, b);
		}

		// Definition of Call Theta
		double EuropeanEquityOptions::CallTheta(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
		{
			normal_distribution<> myNormal(0, 1);
			double tmp = sig * sqrt(T);

			double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			double d2 = d1 - tmp;

			double t1 = (S * exp((b - r) * T) * pdf(myNormal, d1) * sig * 0.5) / sqrt(T);
			double t2 = (b - r) * (S * exp((b - r) * T) * cdf(myNormal, d1));
			double t3 = r * K * exp(-r * T) * cdf(myNormal, d2);

			return -(t1 + t2 + t3);
		}

		double EuropeanEquityOptions::PutTheta(const double& S, const double& r, const double& K, const double& sig, const double& T, const double& b) const
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
		double EuropeanEquityOptions::CallWithParity(const double& putPrice) const
		{
			double callPrice;

			callPrice = putPrice + S - K * exp(-r * T);

			return callPrice;

		}

		double EuropeanEquityOptions::PutWithParity(const double& callPrice) const
		{
			double putPrice;

			putPrice = callPrice + K * exp(-r * T) - S;
			return putPrice;

		}

		map<string, double> EuropeanEquityOptions::CheckParity(const double& callPrice, const double& putPrice) const
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

	}
}





