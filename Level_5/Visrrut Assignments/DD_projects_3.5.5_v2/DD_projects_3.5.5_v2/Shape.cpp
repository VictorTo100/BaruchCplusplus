/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the Shape class defined in Header file
*
*/

#include "Point.h"
#include "stdlib.h"
#include "Shape.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>

using namespace std;

// NOTE: Please note I have used colon syntax for default and custom constructor based on https://quantnet.com/threads/copy-constructor-in-2-3-5.43428/#post-276102
// In this excercise I have changed it for Copy Constructor 

namespace VISHRUTTALEKAR

{
	namespace CAD
	{

		/*Default constructor for Point
		*Sets the value of ID using rand()
		*/
		Shape::Shape() : m_id(rand())
		{
			cout << "Default constructor for Shape with Colon Syntax is called" << endl;
		}

		// Destructor
		Shape::~Shape()
		{
			cout << "Destructor of Shape is called" << endl;
		}

		/*Copy Constructor
		*Copies the ID
		*/
		Shape::Shape(const Shape& source_s) :m_id(source_s.m_id)
		{
			cout << "Copy constructor of point is called\n" << endl;
		}

		/*ToString function to describe the Shape Object
		*/

		string Shape::ToString() const
		{
			/* argument: No input arguments
			*  returns: String description of the Shape object
			*/
			/* Use the output stream class. The class uses stringbuffer.
			* The sequence of character can be accessed directly as string
			* object using member str as below
			*/
			ostringstream output;

			output << fixed << showpoint << setprecision(2)
				<< "ID is: " << ID() << endl;

			return output.str();

		}

		// Assingment operator 
		Shape& Shape::operator = (const Shape& source_s)
		{
			/*arguments: Point object as const reference
			* return: reference to the source Point object
			*/
			/* Condition to avoid assigning to itself -
			*/
			if (this == &source_s)
			{
				return *this;
			}
			else
			{
				m_id = source_s.m_id;
				return *this;
			}
		}

		/*The implementation uses the << operator to send data to the os input argument
		*/
		ostream& operator << (ostream& os, const Shape& s)
		{
			/*Send to ostream
			*/
			os << "Shape(" << s.m_id << ")" << endl;

			return os;
		}


		void Shape::Print() const
		{
			cout << ToString() << endl;
		}

	}
}