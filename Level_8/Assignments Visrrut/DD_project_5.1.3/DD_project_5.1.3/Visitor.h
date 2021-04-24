
/*Author: Vishrut Talekar; Nov 2020
*/

/*This is a canonical header file that defines the Visitor Class.
* The Visitor class is a derived from boost::static_visitor contains the following;
* Default Constructor, Copy Constructor, Destructor,
* Member functions:
* Operator Overloading:
* Assignment Operator
*
*/

#ifndef Visitor_H
#define Visitor_H

#include<iostream>
#include"Array.h"
#include"Point.h"
#include"Line.h"
#include"Circle.h"
#include <boost/variant.hpp>

using namespace std;
using boost::variant;

namespace VISHRUTTALEKAR
{
	namespace CAD
	{
		class Visitor : public boost::static_visitor<void>
		{
		private:
			/*Declare data member required
			*/
			double m_dx;
			double m_dy;
		public:

			/*Declaring the canonical header file
			*/
			/* Default Constructor
			*/
			Visitor();

			/*Custom  Constructor
			*/
			Visitor(const Visitor& source_v);

			/*Parameter constructor
			*/
			Visitor(double dx, double dy);
			/*Destructor
			*/
			virtual ~Visitor();
			/*Operator overloading
			* Assignment operator
			*/
			Visitor& operator = (const Visitor& source_v);

			/*create an operator () that changes the coordinates of the shape
			* Point, Line, Circle
			*/

			void operator () (Point& p) const;

			void operator () (Line& l) const;

			void operator () (Circle& c) const;

			
		};
	}
}

#endif

/*References
* https://quantnet.com/threads/question-about-operator.44277/
* https://quantnet.com/threads/purposes-of-using-the-visitors.40138/
* https://quantnet.com/threads/visitor-class.39954/
* https://quantnet.com/threads/confirming-my-understanding-of-the-static_visitor-function.39197/
* https://quantnet.com/threads/changing-the-object-stored-by-boost-variant-t.39233/
* https://quantnet.com/threads/error-c2664.18862/#post-179506
* https://quantnet.com/threads/create-an-instance-of-the-visitor.40324/
* https://quantnet.com/threads/understanding-of-this-exercise.26157/
* 
* 
* 
* 
*/