
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
#ifndef MatrixPricer_CPP
#define MatrixPricer_CPP


#include <iostream>
#include "EuropeanOptions.h"
#include "Options.h"
#include <cmath>
#include <iostream>
#include <string>
#include <boost/math/distributions/normal.hpp>
#include <vector>
#include <map>
#include"MatrixPricer.h"
#include"GlobalMesher.h"

using namespace boost::math;

namespace VISHRUTTALEKAR
{
	namespace OPTIONS
	{
		template <typename T>
		MatrixPricer<T>::MatrixPricer()
		{
			opt = new T;
			
			option_params[0][0] = 0;
			
			mesh_size = 0;
			start_mesh = 0;
			end_mesh = 0;
			mesh_option_param = "Spot";
			std::cout << "Default Constructor of MatrixPricer is called\n" << endl;
		}

		/*Implementing the Custom Constructor
		*/
		template <typename T>
		MatrixPricer<T>::MatrixPricer(const T opt, const std::vector<std::vector<double>>& option_params): opt(opt), option_params(option_params)
		{
			mesh_size = 0;
			start_mesh = 0;
			end_mesh = 0;
			mesh_option_param = "Spot";

			std::cout << "Custom Constructor of Matrix Pricer is called\n" << endl;
		}

		

		/*Copy Constructor
		*/
		template <typename T>
		MatrixPricer<T>::MatrixPricer(const MatrixPricer<T>& source_mp): option_params(source_mp.option_params), mesh_size(source_mp.mesh_size), start_mesh(source_mp.start_mesh), end_mesh(source_mp.end_mesh), mesh_option_param(source_mp.mesh_option_param)
		{
			//opt = new T;
			//*opt = *source_mp.opt; 
			opt = source_mp.opt;
			std::cout << "Copy Constructor of MatrixPricer is called\n" << endl;
		}

		/*Destructor
		*/
		template <typename T>
		MatrixPricer<T>::~MatrixPricer()
		{
			//delete opt;
			std::cout << "Destructor of EuropeanOptions is called\n" << endl;
		}

		/*Overload Operator
		* Assignment Operator
		*/
		template <typename T>
		MatrixPricer<T>& MatrixPricer<T>::operator = (const MatrixPricer<T>& source_mp)
		{
			if (this == &source_mp)
			{
				return *this;
			}
			else
			{
				opt = source_mp.opt;
				option_params = source_mp.option_params;
				mesh_size = source_mp.mesh_size;
				start_mesh = source_mp.start_mesh;
				end_mesh = source_mp.end_mesh;
				mesh_option_param = source_mp.mesh_option_param;

				return *this;
			}
		}

		/*Getterand setters for Template MatrixPricer
		*
		*/
		template <typename T>
		T MatrixPricer<T>::Opt() const
		{
			return opt;
		}
		template <typename T>

		void MatrixPricer<T>::Opt(T newT)
		{
			opt = newT;
		}
		template <typename T>
		std::vector<std::vector<double>> MatrixPricer<T>::optParams() const
		{
			return option_params;
		}
		template <typename T>
		void MatrixPricer<T>::optParams(const std::vector<std::vector<double>>& new_option_params)
		{
			option_params = new_option_params;
		}
		template <typename T>
		double MatrixPricer<T>::meshSize() const
		{
			return mesh_size;
		}
		template <typename T>
		void MatrixPricer<T>::meshSize(const double& new_mesh_size)
		{
			mesh_size = new_mesh_size;
		}
		template <typename T>
		double MatrixPricer<T>::meshStart() const
		{
			return start_mesh;
		}
		template <typename T>
		void MatrixPricer<T>::meshStart(const double& new_start)
		{
			start_mesh = new_start;
		}
		template <typename T>
		double MatrixPricer<T>::meshEnd() const
		{
			return end_mesh;
		}
		template <typename T>
		void MatrixPricer<T>::meshEnd(const double& new_end)
		{
			end_mesh = new_end;
		}

		template <typename T>
		string MatrixPricer<T>::meshOptionParam() const
		{
			return mesh_option_param;
		}

		template <typename T>
		void MatrixPricer<T>::meshOptionParam(const string& new_mesh_option_param)
		{
			mesh_option_param = new_mesh_option_param;
		}

		/*Member Functions
		*/
		/*Implementation of CalculateMatrixPriceNoMesh 
		*
		*/
		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculateEuropeanMatrixPriceNoMesh(T opt, const std::vector<std::vector<double>>& option_params) const
		{
			const string optionType = opt.SOpt();
			//int vector_size = option_params.size();
			 
			std::vector<double> price_results;
			for (int iter = 0; iter < option_params.size(); iter++)
			{
				/* Option Spot
				*/
				opt.SP(option_params[iter][0]);
				/*Interest rate
				*/
				opt.SIr(option_params[iter][1]);
				/*Strike
				*/
				opt.SK(option_params[iter][2]);
				/*Volatility
				*/
				opt.SVol(option_params[iter][3]);
				/*Expiry
				*/
				opt.ST(option_params[iter][4]);
				/*Cost of Carry
				*/
				opt.Sb(option_params[iter][5]);
				/*Option type
				*/
				opt.SOpt(optionType);

				price_results.push_back(opt.Price());
			}

			return price_results;
		}

		/*Member Functions
		*/
		/*Implementation of CalculateMatrixPriceNoMesh
		*/
		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculateEuropeanMatrixPriceMesh(T opt, const std::vector<std::vector<double>>& option_params) const
		{
			std::vector<double> mesh_vec = GenerateMesh(mesh_size, start_mesh, end_mesh);

			const string optionType = opt.SOpt();
			
			opt.SP(option_params[0][0]);
			/*Interest rate
			*/
			opt.SIr(option_params[0][1]);
			/*Strike
			*/
			opt.SK(option_params[0][2]);
			/*Volatility
			*/
			opt.SVol(option_params[0][3]);
			/*Expiry
			*/
			opt.ST(option_params[0][4]);
			/*Cost of Carry
			*/
			opt.Sb(option_params[0][5]);

			std::vector<double> price_results;
			map<string, int> option_param;
			option_param["Spot"] = 1;
			option_param["IR"] = 2;
			option_param["Strike"] = 3;
			option_param["Vol"] = 4;
			option_param["Expiry"] = 5;
			option_param["costofcarry"] = 6;

			int compare = option_param[mesh_option_param];

			switch(compare)
			{
			case 1:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Spot
					*/
					opt.SP(mesh_vec[iter]);
					price_results.push_back(opt.Price());
					
				} break;
			case 2:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SIr(mesh_vec[iter]);
					price_results.push_back(opt.Price());
					
				}break;
			case 3:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SK(mesh_vec[iter]);
					price_results.push_back(opt.Price());
			
				}break;
			case 4:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Vol
					*/
					opt.SVol(mesh_vec[iter]);
					price_results.push_back(opt.Price());
					break;
				}
			case 5:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.ST(mesh_vec[iter]);
					price_results.push_back(opt.Price());
					
				}break;
			case 6:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.Sb(mesh_vec[iter]);
					price_results.push_back(opt.Price());
					
				}break;
			}
			return price_results;
		}

/*******************************************************************************************************************************************************
*/
		/*Member Functions
		*/
		/*Implementation of CalculateMatrixDeltaNoMesh
		*/
		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculateEuropeanMatrixDeltaMesh(T opt, const std::vector<std::vector<double>>& option_params) const
		{
			std::vector<double> mesh_vec = GenerateMesh(mesh_size, start_mesh, end_mesh);

			const string optionType = opt.SOpt();

			opt.SP(option_params[0][0]);
			/*Interest rate
			*/
			opt.SIr(option_params[0][1]);
			/*Strike
			*/
			opt.SK(option_params[0][2]);
			/*Volatility
			*/
			opt.SVol(option_params[0][3]);
			/*Expiry
			*/
			opt.ST(option_params[0][4]);
			/*Cost of Carry
			*/
			opt.Sb(option_params[0][5]);

			/*Declare variable for price result
			*/
			std::vector<double> delta_results;

			map<string, int> option_param;
			option_param["Spot"] = 1;
			option_param["IR"] = 2;
			option_param["Strike"] = 3;
			option_param["Vol"] = 4;
			option_param["Expiry"] = 5;
			option_param["costofcarry"] = 6;

			switch (option_param[mesh_option_param])
			{
			case 1:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Spot
					*/
					opt.SP(mesh_vec[iter]);
					delta_results.push_back(opt.Delta());
				}break;
			case 2:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SIr(mesh_vec[iter]);
					delta_results.push_back(opt.Delta());
				}break;
			case 3:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SK(mesh_vec[iter]);
					delta_results.push_back(opt.Delta());
				}break;
			case 4:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SVol(mesh_vec[iter]);
					delta_results.push_back(opt.Delta());
				}break;
			case 5:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.ST(mesh_vec[iter]);
					delta_results.push_back(opt.Delta());
				}break;
			case 6:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.Sb(mesh_vec[iter]);
					delta_results.push_back(opt.Delta());
				}break;
			}
			return  delta_results;
		}
/*******************************************************************************************************************************************************
*/
		/*Member Functions
		*/
		/*Implementation of CalculateMatrixDeltaNoMesh
		*/
		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculateEuropeanMatrixGammaMesh(T opt, const std::vector<std::vector<double>>& option_params) const
		{
			std::vector<double> mesh_vec = GenerateMesh(mesh_size, start_mesh, end_mesh);

			const string optionType = opt.SOpt();

			opt.SP(option_params[0][0]);
			/*Interest rate
			*/
			opt.SIr(option_params[0][1]);
			/*Strike
			*/
			opt.SK(option_params[0][2]);
			/*Volatility
			*/
			opt.SVol(option_params[0][3]);
			/*Expiry
			*/
			opt.ST(option_params[0][4]);
			/*Cost of Carry
			*/
			opt.Sb(option_params[0][5]);

			/*Declare variable for price result
			*/
			std::vector<double> gamma_results;

			map<string, int> option_param;
			option_param["Spot"] = 1;
			option_param["IR"] = 2;
			option_param["Strike"] = 3;
			option_param["Vol"] = 4;
			option_param["Expiry"] = 5;
			option_param["costofcarry"] = 6;

			switch (option_param[mesh_option_param])
			{
			case 1:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Spot
					*/
					opt.SP(mesh_vec[iter]);
					gamma_results.push_back(opt.Gamma());
				}break;
			case 2:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SIr(mesh_vec[iter]);
					gamma_results.push_back(opt.Gamma());
				}break;
			case 3:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SK(mesh_vec[iter]);
					gamma_results.push_back(opt.Gamma());
				}break;
			case 4:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SVol(mesh_vec[iter]);
					gamma_results.push_back(opt.Gamma());
				}break;
			case(5):
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.ST(mesh_vec[iter]);
					gamma_results.push_back(opt.Gamma());
				}break;
			case(6):
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.Sb(mesh_vec[iter]);
					gamma_results.push_back(opt.Gamma());
				}break;
			}
			return  gamma_results;
		}

/*******************************************************************************************************************************************************
*/

/*Member Functions
*/
/*Implementation of CalculateMatrixDeltaNoMesh
*/
		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculateEuropeanMatrixThetaMesh(T opt, const std::vector<std::vector<double>>& option_params) const
		{
			std::vector<double> mesh_vec = GenerateMesh(mesh_size, start_mesh, end_mesh);

			const string optionType = opt.SOpt();

			opt.SP(option_params[0][0]);
			/*Interest rate
			*/
			opt.SIr(option_params[0][1]);
			/*Strike
			*/
			opt.SK(option_params[0][2]);
			/*Volatility
			*/
			opt.SVol(option_params[0][3]);
			/*Expiry
			*/
			opt.ST(option_params[0][4]);
			/*Cost of Carry
			*/
			opt.Sb(option_params[0][5]);

			/*Declare variable for price result
			*/
			std::vector<double> theta_results;

			map<string, int> option_param;
			option_param["Spot"] = 1;
			option_param["IR"] = 2;
			option_param["Strike"] = 3;
			option_param["Vol"] = 4;
			option_param["Expiry"] = 5;
			option_param["costofcarry"] = 6;

			switch (option_param[mesh_option_param])
			{
			case 1 :
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Spot
					*/
					opt.SP(mesh_vec[iter]);
					theta_results.push_back(opt.Theta());
				}break;
			case 2:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SIr(mesh_vec[iter]);
					theta_results.push_back(opt.Theta());
				}break;
			case 3:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Strike
					*/
					opt.SK(mesh_vec[iter]);
					theta_results.push_back(opt.Theta());
				}break;
			case 4:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Vol
					*/
					opt.SVol(mesh_vec[iter]);
					theta_results.push_back(opt.Theta());
				}break;
			case 5:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Expiry
					*/
					opt.ST(mesh_vec[iter]);
					theta_results.push_back(opt.Theta());
				}break;
			case 6:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Cost of carry
					*/
					opt.Sb(mesh_vec[iter]);
					theta_results.push_back(opt.Theta());
				}break;
			}
			return  theta_results;
		}

/********************************************************************************************************************************************************
*/
		/*Member Functions
		*/
		/*Implementation of CalculateMatrixDeltaNoMesh
		*/
		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculateEuropeanMatrixVegaMesh(T opt, const std::vector<std::vector<double>>& option_params) const
		{
			std::vector<double> mesh_vec = GenerateMesh(mesh_size, start_mesh, end_mesh);

			const string optionType = opt.SOpt();

			opt.SP(option_params[0][0]);
			/*Interest rate
			*/
			opt.SIr(option_params[0][1]);
			/*Strike
			*/
			opt.SK(option_params[0][2]);
			/*Volatility
			*/
			opt.SVol(option_params[0][3]);
			/*Expiry
			*/
			opt.ST(option_params[0][4]);
			/*Cost of Carry
			*/
			opt.Sb(option_params[0][5]);

			/*Declare variable for price result
			*/
			std::vector<double> vega_results;

			map<string, int> option_param;
			option_param["Spot"] = 1;
			option_param["IR"] = 2;
			option_param["Strike"] = 3;
			option_param["Vol"] = 4;
			option_param["Expiry"] = 5;
			option_param["costofcarry"] = 6;

			switch (option_param[mesh_option_param])
			{
			case 1:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Spot
					*/
					opt.SP(mesh_vec[iter]);
					vega_results.push_back(opt.Vega());
				}
			case 2:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SIr(mesh_vec[iter]);
					vega_results.push_back(opt.Vega());
				}
			case 3:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Strike
					*/
					opt.SK(mesh_vec[iter]);
					vega_results.push_back(opt.Vega());
				}
			case 4:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Volatility
					*/
					opt.SVol(mesh_vec[iter]);
					vega_results.push_back(opt.Vega());
				}
			case 5:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/*Expiry
					*/
					opt.ST(mesh_vec[iter]);
					vega_results.push_back(opt.Vega());
				}
			case 6:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/*Cost of Carry
					*/
					opt.Sb(mesh_vec[iter]);
					vega_results.push_back(opt.Vega());
				}
			}
			return  vega_results;
		}




/*******************************************************************************************************************************************************
*/

		/*Member Functions
		*/
		/*Implementation of CalculateMatrixPriceNoMesh
		*
		*/
		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculatePerAmeMatrixPriceNoMesh(T opt, const std::vector<std::vector<double>>& option_params) const
		{
			const string optionType = opt.SOpt();
			//int vector_size = option_params.size();

			std::vector<double> price_results;
			for (int iter = 0; iter < option_params.size(); iter++)
			{
				/* Option Spot
				*/
				opt.SP(option_params[iter][0]);
				/*Interest rate
				*/
				opt.SIr(option_params[iter][1]);
				/*Strike
				*/
				opt.SK(option_params[iter][2]);
				/*Volatility
				*/
				opt.SVol(option_params[iter][3]);

				/*Cost of Carry
				*/
				opt.Sb(option_params[iter][4]);
				/*Option type
				*/
				opt.SOpt(optionType);

				price_results.push_back(opt.Price());
			}

			return price_results;
		}


		/*Member Functions
		*/
		/*Implementation of CalculateMatrixPriceNoMesh
		*/
		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculateAmericanMatrixPriceMesh(T opt, const std::vector<std::vector<double>>& option_params) const
		{
			std::vector<double> mesh_vec = GenerateMesh(mesh_size, start_mesh, end_mesh);

			const string optionType = opt.SOpt();

			opt.SP(option_params[0][0]);
			/*Interest rate
			*/
			opt.SIr(option_params[0][1]);
			/*Strike
			*/
			opt.SK(option_params[0][2]);
			/*Volatility
			*/
			opt.SVol(option_params[0][3]);
			
			/*Cost of Carry
			*/
			opt.Sb(option_params[0][4]);

			std::vector<double> price_results;
			map<string, int> option_param;
			option_param["Spot"] = 1;
			option_param["IR"] = 2;
			option_param["Strike"] = 3;
			option_param["Vol"] = 4;
			option_param["costofcarry"] = 5;

			int compare = option_param[mesh_option_param];

			switch (compare)
			{
			case 1:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Spot
					*/
					opt.SP(mesh_vec[iter]);
					price_results.push_back(opt.Price());

				} break;
			case 2:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SIr(mesh_vec[iter]);
					price_results.push_back(opt.Price());

				}break;
			case 3:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.SK(mesh_vec[iter]);
					price_results.push_back(opt.Price());

				}break;
			case 4:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Vol
					*/
					opt.SVol(mesh_vec[iter]);
					price_results.push_back(opt.Price());
					break;
				}

				
			case 5:
				for (int iter = 0; iter < mesh_vec.size(); iter++)
				{
					/* Option Interest rate
					*/
					opt.Sb(mesh_vec[iter]);
					price_results.push_back(opt.Price());

				}break;
			}
			return price_results;
		}








/*******************************************************************************************************************************************************
*/
	// NOTE: PRICE MESH FOR PERPETUAL AMERICAN OPTIION TO BE ADDED


	}
}
#endif

/*References
* https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
*/ 