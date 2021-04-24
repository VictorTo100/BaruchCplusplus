/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this header file is to define the Shape class
* The Shape Class:
* The purpose of the class is base class for Point, Line and Circle
* Has a private data member m_id
* Has Default constructor and the destructor
* Getter for id
* Member function:
* ToString: To return a string description of the Shape
*
* Virtual destructor - 3.5.3
* virtual void Draw() const = 0 - Pure virtual function; to be overriden in the inherited classes
*
*/
#ifndef Shape_H
#define Shape_H
#include<iostream>

using namespace std;

namespace VISHRUTTALEKAR
{
	namespace CAD
	{
		class Shape
		{

		private:
			/* Id number of type int
			*/
			int m_id;

		public:
			/* Default constructor
			*/
			Shape();
			/*Copy constructor
			*/
			Shape(const Shape& source_s);
			/* Destructor
			*/
			virtual ~Shape();
			/* Getter function for id
			*/
			int ID() const;

			/* ******** Overloaded operators ***********
			*/

			/*Assignment Operator
			*To complete the canonical header file
			*/
			Shape& operator =  (const Shape& source_s);

			/*ToString function to print the description of the Shape object
			*/
			virtual std::string ToString() const;

			/*The implementation uses the << operator to send data to the os input argument
			* Declared as friend in this excercise
			* std::ostream class had to be a global function and thus can’t access the private members
			*/
			friend ostream& operator << (ostream& os, const Shape& s);

			/* Pure virtual function; making the Shape class an abstract class
			*/
			virtual void Draw() const = 0;

			void Print() const;

		};
		/*Normal Inline functions for Getter of
		*/
		inline int Shape::ID() const { return m_id; }
	}
}

#endif