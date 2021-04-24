
/*Author: Vishrut Talekar
*/
/* The Purpose of this file is to defin the abstract base Option 
* The Class  will be implemented by the inherited classes
* 
The file defined the basic canonical header file 
*/

#include "Options.h"
#include <cmath>
#include <iostream>
#include<string>

namespace VISHRUTTALEKAR
{
	namespace OPTIONS
	{
		/*Default Constructor
		*/
		Options::Options()
		{ 
			std::cout << "Default Constructor of Option is called\n" << endl;
		}
		/*Destructor
		*/
		Options::~Options()
		{

		}
		/*Copy constructor
		*/
		Options::Options(const Options& option2)
		{
			std::cout << "Copy Constructor of Option is called\n" << endl;
		}

		/*Operator overloadin
		* Assignment operator
		*/
		Options& Options::operator = (const Options& option2) 
		{
			/*Preclude from assigning to itself
			*/
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