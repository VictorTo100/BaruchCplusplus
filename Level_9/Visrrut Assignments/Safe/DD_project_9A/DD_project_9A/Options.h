
/*
Approach:
Define a abstract base class which should be inherited by the base class - force contract
Following from the lecture example 

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
			// 'Kernel' functions for Options calculations
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

		protected:
			string optionType;       // Call or Put
			
		public:
			Options();											// Default constructor
			Options(const string& type);
			Options(const Options& Options2);						// Copy Constructor
			virtual ~Options();									// Destructor
			Options& operator = (const Options& Options2);			// Overload the Assignment Operator 

		};

	}

}

#endif


/*
* References:
https://quantnet.com/threads/about-the-data-member.40005/#post-251179
http://www.webwise-scripts.com/c++faq/private-virtuals.html

*/