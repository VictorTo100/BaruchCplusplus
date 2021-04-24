/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the Array class defined in Array Header file
*
*
* ************** Added in 3.6.1 *************************************
* GetElement(), SetElement() and index operator throw -1 if the index was toosmall or too big.
*
* ************** Added in 3.6.2 *************************************
* Replace throw -1, with the OutOfBoundsException handling
*
*************** Added in 4.2a.1 *************************************
* Make Array Class generic where it is able to store any type and not
* only Point Objects
*/
#ifndef Array_CPP
#define Array_CPP

#include "Array.h"
#include "Point.h"
#include "OutOfBoundsException.h"
#include<iostream>
#include<sstream>
#include<iomanip>

using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		/*Default Constructor for Array with size 10
		* Colon syntax is used
		* Please note I could use new Point[m_size];
		* however that initiates the x and y coordinates to
		* garbage values and not '0'
		*/

		template <typename T>
		int Array<T>::m_size_default = 10;

		// Given Point is in namespace VISHRUTTALEKAR; we can refer to Poiny using only CAD part => 2.6.1 testing first bullet  point
		template <typename T>
		Array<T>::Array() : m_data(new T[m_size_default]), m_size(m_size_default) // Default constructor with Colon Syntax
		{
			cout << "Default constructor for Array is called" << endl;
		}

		/*Custom constructor with intialization parameters
		* Colon Syntax is used
		*/
		template <typename T>
		// Custom constructor with intialization parameters
		Array<T>::Array(int size) : m_data(new T[size]), m_size(size)
		{
			cout << "Intialize Array using custom constructor\n" << endl;
		}

		template <typename T>
		/*Copy constructor added
		*/
		Array<T>::Array(const Array<T>& arr)
		{
			m_size = arr.m_size;
			/*Allocate C array with same size
			*/
			m_data = new T[arr.m_size];
			/*Copy each element separately
			*/
			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = arr.m_data[i];

			}

			cout << "Copy constructor of Array is called\n" << endl;
		}

		/*Destructor
		*/
		template <typename T>
		Array<T>::~Array()
		{
			delete[] m_data;
			cout << "destructor is called" << endl;
		}

		/* Operator Overloading
		*/
		/*Assignment operator
		*/
		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source)
		{
			// Avoid doing assign to myself
			if (this == &source)
			{
				return *this;
			}
			else
			{
				/*Delete old C array before allocation, as C arrays cannot grow
				*/
				delete[] m_data;

				m_size = source.m_size;
				/*Allocate C array with same size
				*/
				m_data = new T[source.m_size];

				/*Copy each element separately
				*/
				for (int i = 0; i < m_size; i++)
				{
					m_data[i] = source.m_data[i];

				}
				return *this;
			}
		}

		/*Get elements of Array using square bracket operator
		*/
		template <typename T>
		T& Array<T>::operator [](int index)
		{
			/*argument:
			*	1. index of type double: Index of the Array object
			*returns: Template type as reference
			*/
			/*Condition for out of bounds index
			* Error handling will be added later
			*/

			if (index >= m_size || index < 0)
			{
				throw OutOfBoundsException(index);
			}
			else
			{
				return m_data[index];
			}
		}
		/*Const version of square bracket Operator
		*/
		template <typename T>
		const T& Array<T>::operator [](int index) const
		{
			/*argument:
			*	1. index of type double: Index of the Array object
			*returns: Template type as reference
			*/
			/*Condition for out of bounds index
			* Error handling will be added later
			*/
			cout << "Const version is used" << endl;
			if (index >= m_size || index < 0)
			{
				throw OutOfBoundsException(index);
			}
			else
			{
				return m_data[index];
			}
		}
		/*Get elements of Array
		*/
		template <typename T>
		T& Array<T>::GetElement(int index) const
		{
			/*argument:
			*	1. index of type double: Index of the Array object
			*returns: Template type as reference
			*/
			/*Condition for out of bounds index
			* Error handling will be added later 
			*/
			if (index >= m_size || index < 0)
			{
				throw OutOfBoundsException(index);
			}
			else
			{
				return m_data[index];
			}
		}
		/*Set elements of Array
		*/
		template <typename T>
		void Array<T>::SetElement(int index, const T& p)
		{
			/*argument:
			*	1. index of type double: Index of the Array object
			*	2. Template type as reference
			*returns: void
			*/
			if (index >= m_size || index < 0)
			{
				throw OutOfBoundsException(index);
			}
			else
			{
				m_data[index] = p;
			}
		}
		/*Get Size of the Array
		*/
		template <typename T>
		int Array<T>::Size() const
		{
			/*argument:None
			 *returns: Size of the array of type double
			 */
			return m_size;
		}

		template <typename T>
		int Array<T>::DefaultSize()
		{
			return m_size_default;
		}

		template <typename T>
		void Array<T>::DefaultSize(int size)
		{
			m_size_default = size;
		}

	}
}

#endif