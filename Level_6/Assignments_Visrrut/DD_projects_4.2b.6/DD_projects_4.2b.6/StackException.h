/*Author: Vishrut Talekar; Nov 2020
*/

/*This is a canonical header file that defines the StackException Class.
* The StackException is an abstract class contains the following;
* Default Constructor, Copy Constructor, Destructor,
* Member functions:
* Pure virtual function GetMessage
* Operator Overloading:
* Assignment Operator
*
*/

#ifndef StackException_H
#define StackException_H

#include<iostream>
#include <sstream>
#include<iomanip>
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		class StackException
		{
		public:

			/*Declaring the canonical header file*/

			/* Default Constructor
			*/
			StackException();
			/* Copy Constructor
			*/
			StackException(const StackException& stexp);
			/* Default Constructor
			*/
			StackException& operator = (const StackException& stexp);
			// Destructor
			virtual ~StackException();
			/*Pure virtual function to be inherited and defined in the derived class
			*/
			virtual std::string GetMessage() const = 0;
		};
	}
}

#endif