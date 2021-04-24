/*Author: Vishrut Talekar; Nov 2020
*/

/*This is a canonical header file that defines the ArrayException Class.
* The ArrayException is an abstract class contains the following;
* Default Constructor, Copy Constructor, Destructor,
* Member functions:
* Pure virtual function GetMessage
* Operator Overloading:
* Assignment Operator
*
*/

#ifndef ArrayException_H
#define ArrayException_H

#include<iostream>
using namespace std;


namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		class ArrayException

		{
		public:

			/*Default constructors
			*/
			ArrayException();
			/*Copy Constructor
			*/
			ArrayException(const ArrayException& ex);
			/*Operator overloading
			* Assignment Operator
			*/
			ArrayException& operator = (const ArrayException& ex);	// Assignment operator
			/*Destructor
			*/
			virtual ~ArrayException();
			/*GetMessage Pure virtual function, to be implemented in the derived class
			*/
			virtual std::string GetMessage() const = 0;

		};
	}
}

#endif



