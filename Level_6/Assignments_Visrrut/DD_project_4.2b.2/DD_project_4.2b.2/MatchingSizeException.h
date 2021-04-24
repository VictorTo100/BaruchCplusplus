/*Author: Vishrut Talekar; Nov 2020
*/

/*This is a canonical header file that defines the MatchingSize exception for 
* NumericArray template class.
* Default Constructor, Copy Constructor, Destructor,
* Member functions:
* Pure virtual function GetMessage
* Operator Overloading:
* Assignment Operator
*
*/

#ifndef MatchingSizeException_H
#define MatchingSizeException_H

#include<iostream>
#include "ArrayException.h"
#include <sstream>
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		class MatchingSizeException : public ArrayException
		{

		public:

			/*Default constructors
			*/
			MatchingSizeException();
			/*Copy Constructor
			*/
			MatchingSizeException(const MatchingSizeException& ex);
			/*Operator overloading
			* Assignment Operator
			*/
			MatchingSizeException& operator= (const MatchingSizeException& ex);
			/*Destructor
			*/
			virtual ~MatchingSizeException();
			
			/*GetMessage
			* Inherited from abstract base class ArrayException
			*/
			virtual string GetMessage() const;

		};
	}
}

#endif // !



