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
*/
#include "Array.h"
#include "Point.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include "OutOfBoundsException.h"

using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{

		/*Given Point is in namespace VISHRUTTALEKAR; we can refer to Poiny using only CAD part
		* => 2.6.1 testing first bullet  point
		*/

		/*Default Constructor for Array with size 10
		* Colon syntax is used
		* Please note I could use new Point[m_size];
		* however that initiates the x and y coordinates to
		* garbage values and not '0'
		*/
		Array::Array() : m_data(new CAD::Point[10]), m_size(10)
		{
			cout << "Default constructor for Array is called" << endl;
		}

		/*Custom constructor with intialization parameters
		* Colon Syntax is used
		*/
		Array::Array(const int& size) : m_data(new CAD::Point[size]), m_size(size)
		{
			cout << "Intialize Array using custom constructor\n" << endl;
		}

		/*Copy constructor added
		*/
		Array::Array(const Array& source_arr)
		{
			m_size = source_arr.m_size;
			/*Allocate C array with same size
			*/
			m_data = new CAD::Point[source_arr.m_size];

			/*Copy each element separately
			*/
			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = source_arr.m_data[i];
			}

			cout << "Copy constructor of Array is called\n" << endl;
		}

		/*Destructor
		*/
		Array::~Array()
		{
			delete[] m_data;
			cout << "Destructor of Array is called" << endl;
		}

		/* Operator Overloading
		*/
		/*Assignment operator
		*/
		Array& Array::operator = (const Array& source)
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
				m_data = new CAD::Point[source.m_size];

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
		CAD::Point& Array::operator [](int index)
		{
			/*argument:
			*	1. index of type double: Index of the Array object
			*returns: Point object as reference
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
		const CAD::Point& Array::operator [](int index) const
		{
			/*argument:
			*	1. index of type double: Index of the Array object
			*returns: Point object as const reference
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
		const CAD::Point& Array::GetElement(int index) const
		{
			/*argument:
			*	1. index of type double: Index of the Array object
			*returns: Point object as const reference
			*/
			/*Condition for out of bounds index
			* Error handling will be added later
			*/
			if (index >= m_size || index < 0)
			{
				cout << "Index is out of bounds for get elements\n";
				throw OutOfBoundsException(index);
			}
			else
			{
				return m_data[index];
			}
		}

		/*Set elements of Array
		*/
		void Array::SetElement(int index, const CAD::Point& p)
		{
			/*argument:
			*	1. index of type double: Index of the Array object
			*	2. Point object as const reference
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
		int Array::Size() const
		{
			/*argument:None
			 *returns: Size of the array of type double
			 */
			return m_size;
		}
	}
}