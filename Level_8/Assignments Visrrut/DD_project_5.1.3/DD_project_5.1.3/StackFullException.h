
/*Author: Vishrut Talekar; Nov 2020
*/

/*This is a canonical header file that defines the StackFullException Class.
* The StackFullException is a derived class from Stack Exception contains the following;
* Default Constructor, Copy Constructor, Destructor,
* Member functions:
* Pure virtual function GetMessage
* Operator Overloading:
* Assignment Operator
*
*/

#ifndef StackFullException_H
#define StackFullException_H

#include<iostream>
#include"StackException.h"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		class StackFullException : public StackException
		{
		public:

			/*Declaring the canonical header file*/

			/* Default Constructor
			*/
			StackFullException();

			/* Copy Constructor
			*/
			StackFullException(const StackFullException& stexp);

			/* Default Constructor
			*/
			StackFullException& operator = (const StackFullException& stexp);

			/*Destructor
			*/
			virtual ~StackFullException();

			/*Pure virtual function to be inherited and defined in the derived class
			*/
			std::string GetMessage() const;
		};
	}
}

#endif
