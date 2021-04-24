#include<iostream>
#include "StackFullException.h"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{

		/* */
		StackFullException::StackFullException() :StackException()
		{
			std::cout << "Default Constructor of StackEmptyException is called\n";
		}

		/* Define Copy Constructor for StackEmptyException*/
		StackFullException::StackFullException(const StackFullException& stexp) : StackException(stexp)
		{
			std::cout << "Default Constructor of StackFullException is called\n";
		}

		StackFullException& StackFullException::operator = (const StackFullException& stexp)
		{
			std::cout << "Assignment operator of StackEmptyException is called\n";

			/* Check if it is same object*/
			if (this == &stexp)
			{
				return *this;
			}
			else
			{
				return *this;
			}
		}

		StackFullException::~StackFullException()
		{
			std::cout << "Destructor of StackFulException is called\n";
		}


		std::string StackFullException::GetMessage() const
		{
			ostringstream output;

			output << " The Stack is Full\n" << endl;

			return output.str();
		}

	}

}
