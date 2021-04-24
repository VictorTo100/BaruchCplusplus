/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the MatchingSizeException class
* defined in MatchingSizeException header file
*/

#include "MatchingSizeException.h"
#include<iostream>
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		/*Default Constructor
		*/
		MatchingSizeException::MatchingSizeException() :ArrayException()
		{
			cout << " Default Constructor of MatchingSizeException is called" << endl;
		}
		/*Copy constructor
		*/
		MatchingSizeException::MatchingSizeException(const MatchingSizeException& source_ex) : ArrayException(source_ex)
		{
			cout << "Copy Constructor of MatchingSizeException is called " << endl;

		}

		/*Operator Overloading
		*/
		/*Assignment Operator
		*/
		MatchingSizeException& MatchingSizeException::operator = (const MatchingSizeException& source_ex) 
		{
			/*Preclude from assigning to itself
			*/
			if (this == &source_ex)
			{
				return *this;
			}

			else
			{
				return *this;
			}

		}
		MatchingSizeException::~MatchingSizeException()
		{

		}

		/*Implemtation of the GetMessage function
		* similar to OutOfBoundsException
		*/
		string MatchingSizeException::GetMessage() const
		{
			/*arguments:
			* return: String message with size not matching
			*/
			/* Use the output stream class. The class uses stringbuffer.
			* The sequence of character can be accessed directly as string
			* object using member str as below
			*/
			ostringstream output;

			output << " Size of the Arrays do not match\n" << endl;

			return output.str();

		}

	}
}
