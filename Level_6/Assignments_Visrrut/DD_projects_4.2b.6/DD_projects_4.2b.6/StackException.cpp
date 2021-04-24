
#include<iostream>
#include "StackException.h"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{

		/* */
		StackException::StackException()
		{
			std::cout << "Default Constructor of StackException is called\n";
		}

		StackException::StackException(const StackException& stexp)
		{
			std::cout << "Default Constructor of StackException is called\n";
		}

		StackException& StackException::operator = (const StackException& stexp)
		{
			std::cout << "Assignment operator of StackException is called\n";

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

		StackException::~StackException()
		{
			std::cout << "Destructor of StackException is called\n";
		}

	}

}