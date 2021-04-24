
#ifndef MatrixPricer_CPP
#define MatrixPricer_CPP


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
		template <typename T>
		MatrixPricer<T>::MatrixPricer(const T& opt, const std::vector<std::vector<double>>& option_params): opt(new T), option_params(option_params)
		{
			mesh_size = 0;
			start_mesh = 0;
			end_mesh = 0;
			mesh_option_param = "Spot";

			std::cout << "Custom Constructor of Matrix Pricer is called\n" << endl;
		}

		/*Implementing the Custom Constructor with all data Parameters
		* This is to with Generate mesh for a particular Option pricing parameter
		*/
		template <typename T>
		MatrixPricer<T>::MatrixPricer(const T& opt, const std::vector<std::vector<double>>& option_params, const double& mesh_size, const double& start_mesh, const double& end_mesh, const string& mesh_option_param) : opt(new T), option_params(option_params), mesh_size(mesh_size), start_mesh(start_mesh), end_mesh(end_mesh), mesh_option_param(mesh_option_param)
		{
			std::cout << "Custom Constructor of Matrix Pricer is called\n" << endl;
		}

		/*Copy Constructor
		*/
		template <typename T>
		MatrixPricer<T>::MatrixPricer(const MatrixPricer<T>& source_mp): option_params(source_mp.option_params), mesh_size(source_mp.mesh_size), start_mesh(source_mp.start_mesh), end_mesh(source_mp.end_mesh), mesh_option_param(source_mp.mesh_option_param)
		{
			opt = new T;
			*opt = *source_mp.opt; 
			std::cout << "Copy Constructor of MatrixPricer is called\n" << endl;
		}

		/*Destructor
		*/
		template <typename T>
		MatrixPricer<T>::~MatrixPricer()
		{
			delete opt;
			std::cout << "Destructor of EuropeanEquityOptions is called\n" << endl;
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
				opt = new T;
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
		/*Implementation of CalculateMatrixPriceNoMesh 
		* 
		* 
		* 
		* 
		*/
		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculateMatrixPriceNoMesh(T&opt, const std::vector<std::vector<double>>& option_params)
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


		template <typename T>
		std::vector<double> MatrixPricer<T>::CalculateMatrixPriceMesh(T& opt, const std::vector<std::vector<double>>& option_params,const double& mesh_size, const double& start_mesh, const double& end_mesh, const string& mesh_option_param)
		{
			std::vector<double> mesh_vec = GenerateMesh(mesh_size, start_mesh, end_mesh);

			const string optionType = opt.SOpt();
			double ir = opt.SIr();
			double strike = opt.SK();
			double vol = opt.SVol();
			double expiry = opt.ST();
			double cost_of_carry = opt.Sb();

			std::vector<double> price_results;
			for (int iter = 0; iter < mesh_vec.size(); iter++)
			{
				/* Option Spot
				*/
				opt.SP(mesh_vec[iter]);
				price_results.push_back(opt.Price());
			}

			return price_results;
		}
	}
}
#endif

/*References
* https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
*/ 