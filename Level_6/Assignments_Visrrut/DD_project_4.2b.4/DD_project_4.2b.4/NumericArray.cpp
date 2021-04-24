/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this file is implement the template class NumericArray defined in header file NumericArray
*/

#ifndef NumericArray_CPP
#define NumericArray_CPP


#include "Array.h"
#include "NumericArray.h"
#include "OutOfBoundsException.h"
#include "MatchingSizeException.h"
#include<iostream>
#include<sstream>
#include<iomanip>

using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		/*Default Constructor
		*/
		template <typename T>
		NumericArray<T>::NumericArray() : Array<T>()
		{
			cout << "Default constructor for Array is called" << endl;
		}

		/*Custom constructor with intialization parameters
		*/
		template <typename T>
		NumericArray<T>::NumericArray(int size) : Array<T>(size)
		{
			cout << "Intialize Array using custom constructor\n" << endl;
		}

		/*Copy constructor added
		*/
		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& source_narr) :Array<T>(source_narr)
		{

		}

		template <typename T>
		NumericArray<T>::~NumericArray()  // Destructor
		{

		}

		/* Operator Overloading
		*/
		/*Assignment operator
		*/
		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source_narr)
		{
			// Avoid doing assign to myself
			if (this == &source_narr)
			{
				return *this;
			}
			else
			{
				/*Call the assignment Operator from base class
				*/
				Array<T>::operator = (source_narr);
				return *this;
			}
		}

		/*Assignment operator
		*/
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (double factor) const
		{
			/*argument: factor of type double
			* return:NumericArray of type T
			*/
			/*Declare a temporary NumericArray to scale
			*/
			NumericArray<T> tmp(*this);
			/*Scale each element of the NumericArray
			*/
			for (int i = 0; i < tmp.Size(); i++)
			{
				tmp[i] *= factor;
			}

			return tmp;
		}


		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& narr) const
		{
			/*argument: const reference of NumericArray of type T
			* return:NumericArray of type T
			*/
			/*Check for the condition of the matching array size
			*/
			if (NumericArray<T>::Size() != narr.Size())
			{
				throw MatchingSizeException();
			}

			else
			{
				/*Declare a temporary NumericArray to sum
				*/
				NumericArray<T> tmp(*this);

				for (int i = 0; i < tmp.Size(); i++)
				{
					tmp[i] += narr[i];
				}

				return tmp;
			}
		}

		template <typename T>
		double NumericArray<T>::DotProduct(const NumericArray<T>& narr) const
		{
			/*argument: const reference of NumericArray of type T
			* return: Number of type double
			*/
			/*Check for the condition of the matching array size
			*/
			if (NumericArray<T>::Size() != narr.Size())
			{
				throw MatchingSizeException();
			}
			else
			{
				/*Declare a temporary NumericArray to sum
				*/
				NumericArray<T> tmp(*this);
				/*Declare variable to store result of dot product
				*/
				double result_dp = 0;

				for (int i = 0; i < tmp.Size(); i++)
				{
					result_dp += (tmp[i] * narr[i]);
				}

				return result_dp;
			}

			
		}
	}
}

#endif