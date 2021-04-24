/*Author: Vishrut Talekar
*/

/*Approach:
* Define a abstract base class which should be inherited  the base class - force contract
* The pure virtual function in this base will have to implemented in the derived class 
* and these cover the Price function for Call and Put and Sensitivities
*/

#ifndef Options_H
#define Options_H


#include <string>
using namespace std;

namespace VISHRUTTALEKAR
{
	
	namespace OPTIONS
	{
		class Options
		{
		private:
			//'Kernel' functions for Options calculations
			/* Pure virtual functions for 
			* Calculate Call price, calculate Put price
			* Sensitivites for both Call and Put
			* Delta, Gamma, Theta, Vega
			*/
			virtual double CallPrice() const = 0;
			virtual double PutPrice() const = 0;
			virtual double CallDelta() const = 0;
			virtual double PutDelta() const = 0;
			virtual double CallGamma() const = 0;
			virtual double PutGamma() const = 0;
			virtual double CallTheta() const = 0;
			virtual double PutTheta() const = 0;
			virtual double CallVega() const = 0;
			virtual double PutVega() const = 0;

		public:
			/*Canonical header file
			*/
			/*Default Constructor
			*/
			Options();			
			/*Copy Constructor
			*/
			Options(const Options& source_op);
			/*Destructor
			*/
			virtual ~Options();
			/*Operator Overloading
			* Assignment operator
			*/
			Options& operator = (const Options& source_op);
		};

	}

}

#endif


/*
* References:
https://quantnet.com/threads/about-the-data-member.40005/#post-251179
http://www.webwise-scripts.com/c++faq/private-virtuals.html

*/