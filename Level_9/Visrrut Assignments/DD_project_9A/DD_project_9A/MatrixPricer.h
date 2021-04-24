#ifndef MatrixPricer_H
#define MatrixPricer_H


#include <string>
#include"Options.h"
#include"EuropeanEquityOptions.h"
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
			/*Pointer to the abstract Option class
			*/
			T* opt;
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
			MatrixPricer(const T& opt, const std::vector<std::vector<double>>& option_params);	

			/*Destructor
			*/
			virtual ~MatrixPricer();

			/*Copy Constructor
			*/
			MatrixPricer(const MatrixPricer<T>& source_mp);	
		
			/*Operator Overloading
			*/
			MatrixPricer<T>& operator = (const MatrixPricer<T>& source_mp);

			/*Member functions*/

			std::vector<double> CalculateMatrixPriceNoMesh(T& opt, const std::vector<std::vector<double>>& option_params);
			//std::vector<double> CalculateMatrixPriceNoMesh();

		};
	}
}
#ifndef MatrixPricer_cpp // Must be the same name as in source file
#include "MatrixPricer.cpp"
#endif

#endif