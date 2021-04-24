/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the StackException base class
* defined in StackException header file
*/
#include<iostream>
#include "StackException.h"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		/*Default Constructor
		*/
		StackException::StackException()
		{
			std::cout << "Default Constructor of StackException is called\n";
		}

		/*Copy Constructor
		*/
		StackException::StackException(const StackException& stexp)
		{
			std::cout << "Default Constructor of StackException is called\n";
		}

		/*Operator Overloading
		* Assignment Operator
		*/
		StackException& StackException::operator = (const StackException& stexp)
		{
			std::cout << "Assignment operator of StackException is called\n";

			/*Preclude from assigning it to itself
			*/
			if (this == &stexp)
			{
				return *this;
			}
			else
			{
				return *this;
			}
		}

		StackException::~StackException()
		{
			std::cout << "Destructor of StackException is called\n";
		}

	}

}