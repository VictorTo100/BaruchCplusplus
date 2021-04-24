/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the StackEmptyException class
* defined in StackEmptyException header file
*/
#include<iostream>
#include "StackEmptyException.h"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{

		/*Default Constructor 
		*/
		StackEmptyException::StackEmptyException():StackException()
		{
			std::cout << "Default Constructor of StackEmptyException is called\n";
		}

		/* Define Copy Constructor for StackEmptyException
		*/
		StackEmptyException::StackEmptyException(const StackEmptyException& stexp): StackException(stexp)
		{
			std::cout << "Default Constructor of StackEmptyException is called\n";
		}

		/*Operator Overloading
		* Assignment Operator
		*/
		StackEmptyException& StackEmptyException::operator = (const StackEmptyException& stexp)
		{
			std::cout << "Assignment operator of StackEmptyException is called\n";

			/*Preclude from assigning to itself
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
		/*Destructor
		*/
		StackEmptyException::~StackEmptyException()
		{
			std::cout << "Destructor of StackEmptyException is called\n";
		}

		/*Member function
		*/
		/*GetMesasge: Function to print the Stack Empty Message
		*/
		std::string StackEmptyException::GetMessage() const
		{
			/* argument: No input arguments
			*  returns: String description of the StackEmptyException
			*/
			/* Use the output stream class. The class uses stringbuffer.
			* The sequence of character can be accessed directly as string
			* object using member str as below
			*/
			ostringstream output;
			output << " The Stack is Empty\n" << endl;
			return output.str();
		}

	}

}
