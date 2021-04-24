/*Author: Vishrut Talekar; Nov 2020
*/

/*This is a canonical header file that defines the StackEmptyException Class.
* The StackEmptyException is a derived class from Stack Exception contains the following;
* Default Constructor, Copy Constructor, Destructor,
* Member functions:
* Pure virtual function GetMessage
* Operator Overloading:
* Assignment Operator
*
*/

#ifndef StackEmptyException_H
#define StackEmptyException_H

#include<iostream>
#include"StackException.h"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		class StackEmptyException : public StackException
		{
		public:

			/*Declaring the canonical header file*/

			/* Default Constructor*/
			StackEmptyException();

			/* Copy Constructor*/
			StackEmptyException(const StackEmptyException& stexp);

			/* Default Constructor*/
			StackEmptyException& operator = (const StackEmptyException& stexp);

			// Destructor
			virtual ~StackEmptyException();

			/*Pure virtual function to be inherited and implemented in the derived class
			*/
			std::string GetMessage() const;
		};
	}
}

#endif