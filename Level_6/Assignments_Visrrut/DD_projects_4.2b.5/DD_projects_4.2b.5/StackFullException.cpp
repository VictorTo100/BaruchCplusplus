/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the StackFullException class
* defined in ArrayFullException header file
*/
#include<iostream>
#include "StackFullException.h"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{

		/*Default Constructor 
		*/
		StackFullException::StackFullException() :StackException()
		{
			std::cout << "Default Constructor of StackEmptyException is called\n";
		}

		/* Define Copy Constructor for StackEmptyException
		*/
		StackFullException::StackFullException(const StackFullException& stexp) : StackException(stexp)
		{
			std::cout << "Default Constructor of StackFullException is called\n";
		}

		/*Operator Overloading
		* Assignment Operator
		*/
		StackFullException& StackFullException::operator = (const StackFullException& stexp)
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
		StackFullException::~StackFullException()
		{
			std::cout << "Destructor of StackFulException is called\n";
		}

		/*Member function
		*/
		/*GetMesasge: Function to print the Stack Empty Message
		*/
		std::string StackFullException::GetMessage() const
		{
			/* argument: No input arguments
			*  returns: String description of the StackEmptyException
			*/
			/* Use the output stream class. The class uses stringbuffer.
			* The sequence of character can be accessed directly as string
			* object using member str as below
			*/
			ostringstream output;

			output << " The Stack is Full\n" << endl;

			return output.str();
		}

	}

}
