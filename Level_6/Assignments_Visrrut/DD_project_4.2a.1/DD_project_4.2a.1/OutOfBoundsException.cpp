
/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the OutOfBoundsException class
* defined in ArrayException header file
*/
#include "ArrayException.h"
#include "OutOfBoundsException.h"
#include<iostream>
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		/*Default constructor for OutOfBoundsException
		*default value of m_index to'0'
		*/
		OutOfBoundsException::OutOfBoundsException() :ArrayException(), m_index(0)
		{
			cout << " Default Constructor of OutOfBoundsException is called" << endl;
		}
		/*Parameter constructor for OutOfBoundsException
		* Set the value of m_index to index
		*/
		OutOfBoundsException::OutOfBoundsException(int index) : ArrayException(), m_index(index)
		{
			/*arguments: index of type in
			* return: OutOfBoundsException object
			*/
			cout << "Custom Constructor of OutOfBoundsException is called " << endl;

		}
		/*Implementation of the copy constructor
		*/
		OutOfBoundsException::OutOfBoundsException(const OutOfBoundsException& ex) :ArrayException(ex), m_index(ex.m_index)
		{
			/*arguments: OutOfBoundsException as const object as const reference
			* return: OutOfBoundsException object
			*/
			cout << "Copy Constructor of OutOfBoundsException is called " << endl;

		}

		OutOfBoundsException& OutOfBoundsException::operator = (const OutOfBoundsException& source_ex)
		{
			/*arguments: OutOfBoundsException as const object as const reference
			* return: reference to the source OutOfBoundsException object
			*
			/*Preclude assignment to itslef
			*/
			if (this == &source_ex)
			{
				return *this;
			}

			else
			{
				/*Call to the assignment operator of base class
				*/
				ArrayException::operator=(source_ex);
				m_index = source_ex.m_index;
				return *this;
			}

		}
		OutOfBoundsException::~OutOfBoundsException()
		{

		}

		/*Implemtation of the GetMessage function
		*/
		string OutOfBoundsException::GetMessage() const
		{
			/*arguments:
			* return: String message with  out of bounds index
			*/
			/* Use the output stream class. The class uses stringbuffer.
			* The sequence of character can be accessed directly as string
			* object using member str as below
			*/
			ostringstream output;

			output << "Index: " << m_index << " is out of bounds" << endl;

			return output.str();

		}

	}
}
