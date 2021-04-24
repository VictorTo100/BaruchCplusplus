/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the abstract base class ArrayException class 
* defined in ArrayException header file
*/
#include "ArrayException.h"
#include<iostream>
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		/*Default Constructor
		*/
		ArrayException::ArrayException()
		{
			cout << "Default constructor of the ArrayException is called" << endl;
		}

		/*Copy Constructor
		*/
		ArrayException::ArrayException(const ArrayException& ex) 
		{

		}

		/*Operator Overloading
		*/
		/*Assignment Operator
		*/
		ArrayException& ArrayException::operator = (const ArrayException& source_ex) 
		{
			if (this == &source_ex)
			{
				return *this;
			}

			else
			{
				return *this;
			}

		}

		/*Destructor
		*/
		ArrayException::~ArrayException()
		{
			cout << "Destructor of the ArrayException is called" << endl;
		}

	}
}
