/*Author: Vishrut Talekar; Nov 2020
*/

/* The Purpose of this class is to define the NumericArray
*template class derived from the Array class using generic inheritance.
* Contains:
* Default Constructor, Destructor, Copy Constructor
* Operator Overloading:
* An operator * to scale the elements of the numeric array by a factor
* An operator + to add the elements of two numeric arrays. Throw anexception if the two arrays have not the same size.
* A function to calculate the dot product.
*/
#ifndef NumericArray_H
#define NumericArray_H

#include"Array.h"
#include"Array.cpp"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		template <typename T>
		class NumericArray : public Array<T>
		{

		public:
			/*Default Constructor
			*/
			NumericArray();
			/*Parameter Constructor with size argument of type int
			*/
			NumericArray(int size);
			/*Destructor
			*/
			~NumericArray();
			/*Copy Constructor
			*/
			NumericArray(const NumericArray<T>& arr);

			/*Operator Overloading
			*/
			/*Assignment Operator
			*/
			NumericArray<T>& operator =  (const NumericArray<T>& arr);

			/*Scaling Operator
			*/
			NumericArray<T> operator * (double factor) const;

			/* Summ (+) Operator to add elements of two Numeric Arrays
			*/
			NumericArray<T> operator + (const NumericArray<T>& arr) const;

			/*Member function for Dot Product
			*/
			double DotProduct(const NumericArray<T>& arr) const;

		};

	}
}

#endif