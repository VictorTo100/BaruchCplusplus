/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the file is to defin the European options Class whicis derived from
* the abstract class Options
* This Classs follows the blue print where core functionalities of option pricing
* and sensitivities is covered
*
* Both private data and functions make the design ribust in term os encapsulation
*/


#ifndef MatrixPricer_H
#define MatrixPricer_H


#include <string>
#include"Options.h"
#include"EuropeanOptions.h"
#include<vector>
using namespace std;

namespace VISHRUTTALEKAR
{

	namespace OPTIONS
	{
		template<typename T>
		class MatrixPricer
		{
		private:
			/*Template type for any option class 
			*/
			T opt;
			/* Matrix(Vector of Vector of Option parameters
			*/
			std::vector<std::vector<double>> option_params;
			/*mesh size(h) to create increments
			*/
			double mesh_size;
			/*start of the mesh
			*/
			double start_mesh;
			/*End of the mesh
			*/
			double end_mesh;
			/*The option parameter which is to be monotonically incremented
			*/
			string mesh_option_param;

		public:
			/*Default Constructor
			*/
			MatrixPricer();

			/*Overloaded Parameter Constructor for different applications
			*/
			MatrixPricer(const T opt, const std::vector<std::vector<double>>& option_params);	

			/*Destructor
			*/
			virtual ~MatrixPricer();

			/*Copy Constructor
			*/
			MatrixPricer(const MatrixPricer<T>& source_mp);	
		
			/*Operator Overloading
			*/
			MatrixPricer<T>& operator = (const MatrixPricer<T>& source_mp);
		/***********************************************************************************************
		* Getter and setters for Template MatrixPricer
		*
		*/
			/*
			*/
			T Opt() const;
			void Opt(T newT);

			std::vector<std::vector<double>> optParams() const;
			void optParams(const std::vector<std::vector<double>>& new_option_params);

			double meshSize() const;
			void meshSize(const double& new_mesh_size);

			double meshStart() const;
			void meshStart(const double& new_start);

			double meshEnd() const;
			void meshEnd(const double& new_end);

			string meshOptionParam() const;
			void meshOptionParam(const string& new_mesh_option_param);
			
			/*Member functions
			*/

			/*Function to Price a Matrix(options parameter in each row) of Options
			* Parameters are stored in vector
			* Returns a vector of prices
			*/
			std::vector<double> CalculateEuropeanMatrixPriceNoMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			std::vector<double> CalculateEuropeanMatrixDeltaNoMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			std::vector<double> CalculateEuropeanMatrixGammaNoMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			std::vector<double> CalculateEuropeanMatrixThetaNoMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			std::vector<double> CalculateEuropeanMatrixVegaNoMesh(T opt, const std::vector<std::vector<double>>& option_params) const;


			/*Function to Price a Matrix(options parameter in each row) of Options
			* Parameters are stored in vector
			* Returns a vector of prices
			*/
			std::vector<double> CalculateEuropeanMatrixPriceMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			/*Function to Calculate Delta a for a given options data and 
			and vary Matrix(options parameter in each row) of Options
			* Parameters are stored in vector
			* Returns a vector of prices
			*/
			std::vector<double> CalculateEuropeanMatrixDeltaMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			/*Function to Calculate Gamma of a Matrix(options parameter in each row) of Options
			* Parameters are stored in vector
			* Returns a vector of prices
			*/
			std::vector<double> CalculateEuropeanMatrixGammaMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			/*Function to Calculate Theta of option a Matrix(options parameter in each row) of Options
			* Parameters are stored in vector
			* Returns a vector of prices
			*/
			std::vector<double> CalculateEuropeanMatrixThetaMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			/*Function to Price a Matrix(options parameter in each row) of Options
			* Parameters are stored in vector
			* Returns a vector of prices
			*/
			std::vector<double> CalculateEuropeanMatrixVegaMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			/*Function to Price a Matrix(options parameter in each row) of Options
			* Parameters are stored in vector
			* Returns a vector of prices
			*/
			std::vector<double> CalculatePerAmeMatrixPriceNoMesh(T opt, const std::vector<std::vector<double>>& option_params) const;

			std::vector<double>CalculateAmericanMatrixPriceMesh(T opt, const std::vector<std::vector<double>>& option_params) const;



		};
	}
}
#ifndef MatrixPricer_cpp // Must be the same name as in source file
#include "MatrixPricer.cpp"
#endif

#endif