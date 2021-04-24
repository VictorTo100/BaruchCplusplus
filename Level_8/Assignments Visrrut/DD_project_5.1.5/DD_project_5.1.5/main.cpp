/*Author: Vishrut Talekar; Nov 2020
*/
/* The purpose of this file is to experiment with statistical function of Boost
*/


#include <boost/math/distributions/exponential.hpp> // Include headers for Exponential and Poisson distribution
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
#include <vector>
#include <iostream>
using namespace std;


/*Reference
*/
/*
https://www.boost.org/doc/libs/1_47_0/libs/math/doc/sf_and_dist/html/math_toolkit/dist/dist_ref/dists/poisson_dist.html
https://www.boost.org/doc/libs/1_54_0/libs/math/doc/html/math_toolkit/dist_ref/dists/exp_dist.html
https://www.boost.org/doc/libs/1_37_0/boost/math/distributions/exponential.hpp
https://www.boost.org/doc/libs/1_66_0/boost/math/distributions/poisson.hpp
*/



int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	double scale_parameter = 0.5; // The question mentions 0.5
	exponential_distribution <> myExponential(0.5); // Default type is 'double'
	cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << endl;

	// Distributional properties
	cout << "pdf: " << pdf(myExponential, 1) << endl;
	cout << "cdf: " << cdf(myExponential, 0) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\n***Exponential distribution: \n";
	cout << "median: " << skewness(myExponential) << endl;
	cout << "mode: " << mode(myExponential) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
	cout << "kurtosis: " << kurtosis(myExponential) << endl;
	cout << "Quantile: " << quantile(myExponential, 0.9) << endl;

	// Poisson Distribution
	double mean = 3.0;
	poisson_distribution<double> myPoisson(mean);

	double val = 2.0;
	cout << endl << "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;

	// Other properties
	cout << "\n***Exponential distribution: \n";
	cout << "median: " << skewness(myPoisson) << endl;
	cout << "mode: " << mode(myPoisson) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myPoisson) << endl;
	cout << "kurtosis: " << kurtosis(myPoisson) << endl;
	cout << "Quantile: " << quantile(myPoisson, 0.9) << endl;


	// Taken from the example code and modified for Poisson distribution
	vector<double> pdfList;
	vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));
		cdfList.push_back(cdf(myPoisson, val));

		val += h;
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";

	}

	return 0;
}

/*Reference
*/
/*
https://www.boost.org/doc/libs/1_47_0/libs/math/doc/sf_and_dist/html/math_toolkit/dist/dist_ref/dists/poisson_dist.html
https://www.boost.org/doc/libs/1_54_0/libs/math/doc/html/math_toolkit/dist_ref/dists/exp_dist.html
https://www.boost.org/doc/libs/1_37_0/boost/math/distributions/exponential.hpp
https://www.boost.org/doc/libs/1_66_0/boost/math/distributions/poisson.hpp
*/
