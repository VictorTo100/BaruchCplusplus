/*Author: Vishrut Talekar; Nov 2020
*/

/* This is the main file the class for testing the functionalities of the class developed for 
* Pricing European Options and Perpetual American Options 
*/

#include"Options.h"
#include"EuropeanOptions.h"
#include"PerpetualAmericanOptions.h"
#include<iostream>
#include<string>
#include"MatrixPricer.h"
using namespace std;
using namespace VISHRUTTALEKAR;

int main()
{
	/*Testing the Options Class functionalities  
	*/
	using OPTIONS::EuropeanOptions;
	using OPTIONS::PerpetualAmericanOptions;
	using OPTIONS::MatrixPricer;

	/*Price testing for batches
	*/
	/* Call Options
	* OptionType, Spot, IR, Strike, Sig, Expiry
	*/
	/*Initialize the data using the parameter constructor for Equity b=r
	*/
	EuropeanOptions callOption_batch_1("Call", 60, 0.08, 65, 0.30, 0.25);
	EuropeanOptions callOption_batch_2("Call", 100, 0.0, 100, 0.20, 1);
	EuropeanOptions callOption_batch_3("Call", 5, 0.12, 10, 0.50, 1);
	EuropeanOptions callOption_batch_4("Call", 100, 0.08, 100, 0.30, 30.0);

	/*Call the pricing function
	* 
	*/
	double callPrice_batch_1 = callOption_batch_1.Price();
	double callPrice_batch_2 = callOption_batch_2.Price();
	double callPrice_batch_3 = callOption_batch_3.Price();
	double callPrice_batch_4 = callOption_batch_4.Price();

	std::cout << "Call Price for callPrice_batch_1 is: " << callPrice_batch_1 << endl;
	std::cout << "Call Price for callPrice_batch_2 is: " << callPrice_batch_2 << endl;
	std::cout << "Call Price for callPrice_batch_3 is: " << callPrice_batch_3 << endl;
	std::cout << "Call Price for callPrice_batch_4 is: " << callPrice_batch_4 << endl;


	/*Call the Sensitivity Delta function
	* 
	*/
	double callDelta_batch_1 = callOption_batch_1.Delta();
	double callDelta_batch_2 = callOption_batch_2.Delta();
	double callDelta_batch_3 = callOption_batch_3.Delta();
	double callDelta_batch_4 = callOption_batch_4.Delta();

	std::cout << "Call Delta for batch_1 is: " << callDelta_batch_1 << endl;
	std::cout << "Call Delta for batch_2 is: " << callDelta_batch_2 << endl;
	std::cout << "Call Delta for batch_3 is: " << callDelta_batch_3 << endl;
	std::cout << "Call Delta for batch_4 is: " << callDelta_batch_4 << endl;

	/*Call the Gamma function
	*
	*/
	double callGamma_batch_1 = callOption_batch_1.Gamma();
	double callGamma_batch_2 = callOption_batch_2.Gamma();
	double callGamma_batch_3 = callOption_batch_3.Gamma();
	double callGamma_batch_4 = callOption_batch_4.Gamma();

	std::cout << "Call Gamma for batch_1 is: " << callGamma_batch_1 << endl;
	std::cout << "Call Gamma for batch_2 is: " << callGamma_batch_2 << endl;
	std::cout << "Call Gamma for batch_3 is: " << callGamma_batch_3 << endl;
	std::cout << "Call Gamma for batch_4 is: " << callGamma_batch_4 << endl;

	/*Call the Vega function
	*
	*/
	double callVega_batch_1 = callOption_batch_1.Vega();
	double callVega_batch_2 = callOption_batch_2.Vega();
	double callVega_batch_3 = callOption_batch_3.Vega();
	double callVega_batch_4 = callOption_batch_4.Vega();

	std::cout << "Call Vega for batch_1 is: " << callVega_batch_1 << endl;
	std::cout << "Call Vega for batch_2 is: " << callVega_batch_2 << endl;
	std::cout << "Call Vega for batch_3 is: " << callVega_batch_3 << endl;
	std::cout << "Call Vega for batch_4 is: " << callVega_batch_4 << endl;

	/*Call the Theta function
	*
	*/
	double callTheta_batch_1 = callOption_batch_1.Theta();
	double callTheta_batch_2 = callOption_batch_2.Theta();
	double callTheta_batch_3 = callOption_batch_3.Theta();
	double callTheta_batch_4 = callOption_batch_4.Theta();

	std::cout << "Call Theta for batch_1 is: " << callTheta_batch_1 << endl;
	std::cout << "Call Theta for batch_2 is: " << callTheta_batch_2 << endl;
	std::cout << "Call Theta for batch_3 is: " << callTheta_batch_3 << endl;
	std::cout << "Call Theta for batch_4 is: " << callTheta_batch_4 << endl;

	/* Put Options
	* OptionType, Spot, IR, Strike, Sig, Expiry
	*/
	/*Initialize the data using the parameter constructor for Equity b=r
	*/
	EuropeanOptions putOption_batch_1("Put", 60, 0.08, 65, 0.30, 0.25);
	EuropeanOptions putOption_batch_2("Put", 100, 0.0, 100, 0.20, 1);
	EuropeanOptions putOption_batch_3("Put", 5, 0.12, 10, 0.50, 1);
	EuropeanOptions putOption_batch_4("Put", 100, 0.08, 100, 0.30, 30.0);

	/*Call the pricing function
	*/
	double putPrice_batch_1 = putOption_batch_1.Price();
	double putPrice_batch_2 = putOption_batch_2.Price();
	double putPrice_batch_3 = putOption_batch_3.Price();
	double putPrice_batch_4 = putOption_batch_4.Price();

	std::cout << "Put Price for batch_1 is: " << putPrice_batch_1 << endl;
	std::cout << "Put Price for batch_2 is: " << putPrice_batch_2 << endl;
	std::cout << "Put Price for batch_3 is: " << putPrice_batch_3 << endl;
	std::cout << "Put Price for batch_4 is: " << putPrice_batch_4 << endl;


	/*Call the Sensitivity Delta function
	*
	*/
	double putDelta_batch_1 = putOption_batch_1.Delta();
	double putDelta_batch_2 = putOption_batch_2.Delta();
	double putDelta_batch_3 = putOption_batch_3.Delta();
	double putDelta_batch_4 = putOption_batch_4.Delta();

	std::cout << "Put Delta for batch_1 is: " << putDelta_batch_1 << endl;
	std::cout << "Put Delta for batch_2 is: " << putDelta_batch_2 << endl;
	std::cout << "Put Delta for batch_3 is: " << putDelta_batch_3 << endl;
	std::cout << "Put Delta for batch_4 is: " << putDelta_batch_4 << endl;

	/*Call the Sensitivity Gamma function
	*
	*/
	double putGamma_batch_1 = putOption_batch_1.Gamma();
	double putGamma_batch_2 = putOption_batch_2.Gamma();
	double putGamma_batch_3 = putOption_batch_3.Gamma();
	double putGamma_batch_4 = putOption_batch_4.Gamma();

	std::cout << "Put Gamma for batch_1 is: " << putGamma_batch_1 << endl;
	std::cout << "Put Gamma for batch_2 is: " << putGamma_batch_2 << endl;
	std::cout << "Put Gamma for batch_3 is: " << putGamma_batch_3 << endl;
	std::cout << "Put Gamma for batch_4 is: " << putGamma_batch_4 << endl;

	/*Call the Sensitivity Vega function
	*
	*/
	double putVega_batch_1 = putOption_batch_1.Vega();
	double putVega_batch_2 = putOption_batch_2.Vega();
	double putVega_batch_3 = putOption_batch_3.Vega();
	double putVega_batch_4 = putOption_batch_4.Vega();

	std::cout << "Put Vega for batch_1 is: " << putVega_batch_1 << endl;
	std::cout << "Put Vega for batch_2 is: " << putVega_batch_2 << endl;
	std::cout << "Put Vega for batch_3 is: " << putVega_batch_3 << endl;
	std::cout << "Put Vega for batch_4 is: " << putVega_batch_4 << endl;

	/*Call the Sensitivity Vega function
	*
	*/
	double putTheta_batch_1 = putOption_batch_1.Theta();
	double putTheta_batch_2 = putOption_batch_2.Theta();
	double putTheta_batch_3 = putOption_batch_3.Theta();
	double putTheta_batch_4 = putOption_batch_4.Theta();

	std::cout << "Put Theta for batch_1 is: " << putTheta_batch_1 << endl;
	std::cout << "Put Theta for batch_2 is: " << putTheta_batch_2 << endl;
	std::cout << "Put Theta for batch_3 is: " << putTheta_batch_3 << endl;
	std::cout << "Put Theta for batch_4 is: " << putTheta_batch_4 << endl;

	/**************************************************************************************************************************************************************************************************************/
	
	EuropeanOptions test(putOption_batch_1);
	EuropeanOptions test_1 = putOption_batch_1;


	/*gamma for call and put future option pricing using the data set: K = 100, S = 105, T = 0.5, r = 0.1, b = 0 and sig = 0.36.
	*/
	/**************************************************************************************************************************************************************************************************************/
	/* Test for Futures Call Option
	*/
	EuropeanOptions callOption_future_delta_gamma("Call", 105, 0.1, 100, 0.36, 0.5, 0);

	double callFuture_gamma_test = callOption_future_delta_gamma.Gamma();

	std::cout << "Call Future Options Gamma Test: " << callFuture_gamma_test << endl;

	double callFuture_delta_test = callOption_future_delta_gamma.Delta();

	std::cout << "Call Future Options Delta Test: " << callFuture_delta_test << endl;

	/* Test for Futures Put Option
	*/
	EuropeanOptions putOption_future_delta_gamma("Put", 105, 0.1, 100, 0.36, 0.5, 0);

	double putFuture_gamma_test = putOption_future_delta_gamma.Gamma();

	std::cout << "Put Future Options Gamma Test: " << putFuture_gamma_test << endl;

	double putFuture_delta_test = putOption_future_delta_gamma.Delta();

	std::cout << "Put Future Options Delta Test: " << putFuture_delta_test << endl;

	/**************************************************************************************************************************************************************************************************************/
	/*Put-Call Parity and Put Call Parity Checks
	*/

	double putPrice_parity = callOption_batch_1.PutWithParity(callPrice_batch_1);

	std::cout << "Put Price with parity is: " << putPrice_parity << endl;

	map<string, double> resultCheck = callOption_batch_1.CheckParity(callPrice_batch_1, putPrice_parity);

	std::map<std::string, double>::iterator it;

	for (it = resultCheck.begin(); it != resultCheck.end(); it++)
	{
		cout << "The Result of the Parity Check is: " << it->first << ":" << it->second << endl;
	}


	/* Divided Differences Testing
	*/

	double callDiffDelta = callOption_batch_1.DeltaDivDiff(1);
	double callDiffGamma = callOption_batch_1.GammaDivDiff(1);

	std::cout << "Diff Delta is: " << callDiffDelta << endl;
	std::cout << "Diff Gamma is: " << callDiffGamma << endl;


	/**************************************************************************************************************************************************************************************************************/
	/*Matrix Pricer with Mesh Generator
	* arguments: Europena option object and option parammeter
	*/
	/*Option Parameters in a matrix
	* Spot
	* IR
	* Strike
	* Sig
	* Expiry
	* b = r for Equities
	*/
	std::vector<std::vector<double>> option_matrix_parameters_mesh(1, vector<double>(6, 0.0));
	option_matrix_parameters_mesh[0][0] = 60;
	option_matrix_parameters_mesh[0][1] = 0.08;
	option_matrix_parameters_mesh[0][2] = 65;
	option_matrix_parameters_mesh[0][3] = 0.30;
	option_matrix_parameters_mesh[0][4] = 0.25;
	option_matrix_parameters_mesh[0][5] = 0.08;

	MatrixPricer<EuropeanOptions> pricerM2(callOption_batch_1, option_matrix_parameters_mesh);
	std::vector<double> results_1;
	/*Set the Mesh Parameters in Matrix Pricer Object
	* Start value, End value and Step Size for the Mesh generator
	*/
	pricerM2.meshEnd(65);
	pricerM2.meshSize(1);
	pricerM2.meshStart(60);
	pricerM2.meshOptionParam("Spot");
	results_1 = pricerM2.CalculateEuropeanMatrixPriceMesh(callOption_batch_1, option_matrix_parameters_mesh);

	cout << "The Price with Monotonically Increasing Spot is: " << results_1[0] << "\n" << results_1[1] << "\n" << results_1[2] << "\n" << results_1[3] << "\n" << results_1[4] << "\n" << results_1[5] << "\n" << endl;

	/**************************************************************************************************************************************************************************************************************/
	/*Matrix Pricer with out the Mesh Generator
	* arguments: Europena option object and option parammeter
	*/
	/*Option Parameters in a matrix
	* Spot
	* IR
	* Strike
	* Sig
	* Expiry
	* b = r for Equities
	*/
	std::vector<std::vector<double>> option_matrix_parameters(2, vector<double>(6, 0.0));
	option_matrix_parameters[0][0] = 60;
	option_matrix_parameters[0][1] = 0.08;
	option_matrix_parameters[0][2] = 65;
	option_matrix_parameters[0][3] = 0.30;
	option_matrix_parameters[0][4] = 0.25;
	option_matrix_parameters[0][5] = 0.08;

	option_matrix_parameters[1][0] = 100;
	option_matrix_parameters[1][1] = 0.0;
	option_matrix_parameters[1][2] = 100;
	option_matrix_parameters[1][3] = 0.20;
	option_matrix_parameters[1][4] = 1;
	option_matrix_parameters[1][5] = 0;

	MatrixPricer<EuropeanOptions> pricerM1(callOption_batch_1, option_matrix_parameters);
	std::vector<double> results(2);
	results = pricerM1.CalculateEuropeanMatrixPriceNoMesh(callOption_batch_1, option_matrix_parameters);

	cout << "The Price with Matrix input for Multiple Options is: " << results[0] << "\n" << results[1] << endl;
	/**************************************************************************************************************************************************************************************************************/
	/**************************************************************************************************************************************************************************************************************/
	/*Matrix Pricer with out the Mesh Generator
	* arguments: Europena option object and option parammeter
	*/
	/*Option Parameters in a matrix
	* Spot
	* IR
	* Strike
	* Sig
	* Expiry
	* b = r for Equities
	*/

	
	std::vector<double> results_delta_nm(2);
	results_delta_nm = pricerM1.CalculateEuropeanMatrixDeltaNoMesh(callOption_batch_1, option_matrix_parameters);

	cout << "The Delta with Matrix input for Multiple Options is: " << results_delta_nm[0] << "\n" << results_delta_nm[1] << endl;
	/**************************************************************************************************************************************************************************************************************/
	/*Pricing testing for Perpetual American Options
	* arguments: option object and option parammeter
	*/
	/*Option Parameters in a matrix
	* Spot
	* IR
	* Strike
	* Vol
	* b Cost of Carry
	* Test the data with K = 100, sig = 0.1, r = 0.1, b = 0.02, S = 110 (check C = 18.5035, P = 3.03106).
	*/
	PerpetualAmericanOptions pACallOption("Call", 110, 0.1, 100, 0.1, 0.02);
	double pa_callPrice = pACallOption.Price();
	std::cout << "Price of Perpetual American Call option is: " << pa_callPrice << endl;

	PerpetualAmericanOptions pAPutOption("Put", 110, 0.1, 100, 0.1, 0.02);
	double pa_PutPrice = pAPutOption.Price();
	std::cout << "Price of Perpetual American Put Option is: " << pa_PutPrice << endl;

	/**************************************************************************************************************************************************************************************************************/
	/*Matrix Pricer with the Mesh Generator for American Options
	* arguments: 
	*/
	/*Option Parameters in a matrix
	* Spot
	* IR
	* Strike
	* Sig
	* Expiry
	* b = r for Equities
	*/
	std::vector<std::vector<double>> option_matrix_parameters_pa(2, vector<double>(5, 0.0));
	option_matrix_parameters_pa[0][0] = 110;
	option_matrix_parameters_pa[0][1] = 0.1;
	option_matrix_parameters_pa[0][2] = 100;
	option_matrix_parameters_pa[0][3] = 0.10;
	option_matrix_parameters_pa[0][4] = 0.02;

	option_matrix_parameters_pa[1][0] = 110;
	option_matrix_parameters_pa[1][1] = 0.1;
	option_matrix_parameters_pa[1][2] = 100;
	option_matrix_parameters_pa[1][3] = 0.10;
	option_matrix_parameters_pa[1][4] = 0.02;

	MatrixPricer<PerpetualAmericanOptions> pricerPA_1(pACallOption, option_matrix_parameters_pa);
	std::vector<double> results_2(2);
	results_2 = pricerPA_1.CalculatePerAmeMatrixPriceNoMesh(pACallOption, option_matrix_parameters_pa);

	cout << "Price of the first and second option in the matrix is: " << results_2[0] <<"\n" << results_2[1] << endl;


	std::vector<std::vector<double>> option_matrix_parameters_pa_1(2, vector<double>(5, 0.0));
	option_matrix_parameters_pa_1[0][0] = 110;
	option_matrix_parameters_pa_1[0][1] = 0.1;
	option_matrix_parameters_pa_1[0][2] = 100;
	option_matrix_parameters_pa_1[0][3] = 0.10;
	option_matrix_parameters_pa_1[0][4] = 0.02;

	
	MatrixPricer<PerpetualAmericanOptions> pricerPA_2(pACallOption, option_matrix_parameters_pa);
	std::vector<double> results_3(6);
	pricerPA_2.meshEnd(105);
	pricerPA_2.meshSize(1);
	pricerPA_2.meshStart(100);
	pricerPA_2.meshOptionParam("Spot");
	results_3 = pricerPA_2.CalculateAmericanMatrixPriceMesh(pACallOption, option_matrix_parameters_pa);

	cout << "Price of the first and second option in the matrix is: " << results_3[0] << "\n" << results_3[1] << endl;

	/**************************************************************************************************************************************************************************************************************/

	/*Matrix Pricer with Mesh Generator
	* arguments: Europena option object and option parammeter
	*/
	/*Option Parameters in a matrix
	* Spot
	* IR
	* Strike
	* Sig
	* Expiry
	* b = r for Equities
	*/
	
	/*Set the Mesh Parameters in Matrix Pricer Object
	* Start value, End value and Step Size for the Mesh generator
	*/
	pricerM2.meshEnd(65);
	pricerM2.meshSize(1);
	pricerM2.meshStart(60);
	pricerM2.meshOptionParam("Spot");
	results_1 = pricerM2.CalculateEuropeanMatrixDeltaMesh(callOption_batch_1, option_matrix_parameters_mesh);

	cout << "The Delta with Monotonically Increasing Spot is: " << results_1[0] << "\n" << results_1[1] << "\n" << results_1[2] << "\n" << results_1[3] << "\n" << results_1[4] << "\n" << results_1[5] << "\n" << endl;


	/**************************************************************************************************************************************************************************************************************/

	return 0;
}


/*References
* 
* https://quantnet.com/threads/clarification-about-meshes.45149/
* https://quantnet.com/threads/question-on-mesh-array-and-mesh-matrices.44505/
* 
* 
*/
