#include <iostream>
#include "EuropeanEquityOptions.h"
#include "Options.h"
#include <cmath>
#include <iostream>
#include <string>
#include <boost/math/distributions/normal.hpp>
#include <vector>
#include <map>
#include"MatrixPricer.h"

using namespace boost::math;

namespace VISHRUTTALEKAR
{
	namespace OPTIONS
	{

		MatrixPricer::MatrixPricer()
		{
			opt = new EuropeanEquityOptions();
			
			option_params[0][0] = 0;
			option_params[0][1] = 0;
			option_params[0][2] = 0;
			option_params[0][3] = 0;
			option_params[0][4] = 0;
			option_params[0][5] = 0;
			mesh_size = 0;
			start_mesh = 0;
			end_mesh = 0;
			mesh_option_param = "Spot";
			std::cout << "Default Constructor of MatrixPricer is called\n" << endl;
		}

		/*Implementing the Custom Constructor
		*/
		MatrixPricer::MatrixPricer(const EuropeanEquityOptions& opt, const std::vector<std::vector<double>>& option_params): opt(new EuropeanEquityOptions()), option_params(option_params)
		{
			mesh_size = 0;
			start_mesh = 0;
			end_mesh = 0;
			mesh_option_param = "Spot";

			std::cout << "Custom Constructor of Matrix Pricer is called\n" << endl;
		}

		/*Copy Constructor
		*/
		MatrixPricer::MatrixPricer(const MatrixPricer& source_mp): option_params(source_mp.option_params), mesh_size(source_mp.mesh_size), start_mesh(source_mp.start_mesh), end_mesh(source_mp.end_mesh), mesh_option_param(source_mp.mesh_option_param)
		{
			opt = new EuropeanEquityOptions();
			*opt = *source_mp.opt; 
			std::cout << "Copy Constructor of MatrixPricer is called\n" << endl;
		}

		/*Destructor
		*/
		MatrixPricer::~MatrixPricer()
		{
			delete opt;
			std::cout << "Destructor of EuropeanEquityOptions is called\n" << endl;
		}

		/*Overload Operator
		* Assignment Operator
		*/
		MatrixPricer& MatrixPricer::operator = (const MatrixPricer& source_mp)
		{
			if (this == &source_mp)
			{
				return *this;
			}
			else
			{
				opt = new EuropeanEquityOptions();
				*opt = *source_mp.opt;
				option_params = source_mp.option_params;
				mesh_size = source_mp.mesh_size;
				start_mesh = source_mp.start_mesh;
				end_mesh = source_mp.end_mesh;
				mesh_option_param = source_mp.mesh_option_param;

				return *this;
			}
		}

		/*Member Functions
		*/
		std::vector<double> MatrixPricer::CalculateMatrixPriceNoMesh(EuropeanEquityOptions& opt, const std::vector<std::vector<double>>& option_params)
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
	}
}

/*References
* https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
*/ 