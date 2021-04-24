
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

		Options::Options():optionType("Call")               // Default Constructor
		{ 
			std::cout << "Default Constructor of Option is called\n" << endl;
		}

		Options::Options(const string& tp): optionType(tp)         // Custom Constructor 
		{

		}

		Options::~Options()
		{

		}

		Options::Options(const Options& option2) : optionType(option2.optionType) 
		{
			std::cout << "Copy Constructor of Option is called\n" << endl;
		}

		//************************************************************** Assignment Operator *************************************************************
		Options& Options::operator = (const Options& option2)   // Copy Constructor
		{

			if (this == &option2)
			{
				return *this;
			}
			else
			{
				optionType = option2.optionType;
			}

			return *this;
		}

		
	}
}