
/*
Reference from Daniel Duffy's codes


*/

#include "Options.h"
#include <cmath>
#include <iostream>
#include<string>

namespace VISHRUTTALEKAR
{
	namespace OPTIONS
	{

		Options::Options()
		{ 
			std::cout << "Default Constructor of Option is called\n" << endl;
		}

		Options::~Options()
		{

		}

		Options::Options(const Options& option2)
		{
			std::cout << "Copy Constructor of Option is called\n" << endl;
		}

		//************************************************************** Assignment Operator *************************************************************
		Options& Options::operator = (const Options& option2) 
		{

			if (this == &option2)
			{
				return *this;
			}
			else
			{
				return *this;
			}	
		}
	}
}