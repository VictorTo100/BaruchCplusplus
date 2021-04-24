
#include"Options.h"
#include"EuropeanEquityOptions.h"
#include<iostream>
#include<string>
#include"MatrixPricer.h"
using namespace std;
using namespace VISHRUTTALEKAR;

int main()
{
	/*Testing the Options Class functionalities  
	*/
	using OPTIONS::EuropeanEquityOptions;
	using OPTIONS::MatrixPricer;

	EuropeanEquityOptions callOption("Call", 60, 0.08, 65, 0.30, 0.25);

	double callPrice = callOption.Price();

	std::cout << "Call Price is: " << callPrice << endl;

	double putPrice = callOption.PutWithParity(callPrice);

	std::cout << "Put Price is: " << putPrice << endl;

	map<string, double> resultCheck = callOption.CheckParity(callPrice, putPrice); 
	
	std::map<std::string, double>::iterator it;

	for (it = resultCheck.begin(); it != resultCheck.end(); it++)
	{
		cout << "The Result of the Parity Check is: " << it->first << ":" << it->second << endl;
	}
	/*Index of parameter for matrix
	* Spot, Interest rate, Strike, Vol, Expiry, Cost of carry
	*/
	/*Create a vector of vector of Options
	*/

	std::vector<std::vector<double>> option_matrix_parameters(2, vector<double>(6, 0.0));
	option_matrix_parameters[0][0] = 60;
	option_matrix_parameters[0][1] = 0.08;
	option_matrix_parameters[0][2] = 65;
	option_matrix_parameters[0][3] = 0.30;
	option_matrix_parameters[0][4] = 0.25; 
	option_matrix_parameters[0][5] = 0.08;

	option_matrix_parameters[1][0] = 60;
	option_matrix_parameters[1][1] = 0.08;
	option_matrix_parameters[1][2] = 65;
	option_matrix_parameters[1][3] = 0.30;
	option_matrix_parameters[1][4] = 0.25;
	option_matrix_parameters[1][5] = 0.08;

	MatrixPricer<EuropeanEquityOptions> pricerM1(callOption, option_matrix_parameters);
	std::vector<double> results(2);
	results = pricerM1.CalculateMatrixPriceNoMesh(callOption, option_matrix_parameters);

	cout << "Price of the first option is: " << results[0] << endl;
	
	return 0;
}


/*References
* 
* https://quantnet.com/threads/clarification-about-meshes.45149/
* https://quantnet.com/threads/question-on-mesh-array-and-mesh-matrices.44505/
* 
* 
*/