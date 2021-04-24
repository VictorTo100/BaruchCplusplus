/*Author: Vishrut Talekar; Nov 2020
*/

/*This file defines the OutOfBoundsException Class.
* The OutOfBoundsException contains the following;
* Default Constructor, Copy Constructor, Destructor,
* Member functions:
* Override the GetMessage from the abstract base class
* Operator Overloading:
* Assignment Operator
*
*/


#ifndef OutOfBoundsException_H
#define OutOfBoundsException_H

#include<iostream>
#include "ArrayException.h"
#include <sstream>
using namespace std;


namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		class OutOfBoundsException : public ArrayException
		{

		private:
			int m_index;

		public:

			/*Default constructors
			*/
			OutOfBoundsException();
			/*Parameter constructor
			*/
			OutOfBoundsException(int index);
			// Copy Constructor
			OutOfBoundsException(const OutOfBoundsException& ex);

			/*Operator overloading
			* Assignment Operator
			*/
			OutOfBoundsException& operator =(const OutOfBoundsException& ex);
			/*Destructor
			*/
			virtual ~OutOfBoundsException();
			/*Member function
			*/
			/*GetMessage
			* Inherited from abstract base class ArrayException
			*/
			string GetMessage() const;

		};
	}
}

#endif // !

