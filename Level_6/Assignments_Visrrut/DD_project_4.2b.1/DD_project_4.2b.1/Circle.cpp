/*Author: Vishrut Talekar; Nov 2020
*/
/*The Purpose of this file is to implement the Point class defined in Header file
*/

#define _USE_MATH_DEFINES

#include "Point.h"
#include "Circle.h"
#include"Shape.h"
#include <iostream>
#include<sstream>
#include<iomanip>
#include<cmath>

namespace VISHRUTTALEKAR
{

	namespace CAD
	{
		/*Default constructor for Circle
		* Center: Point object with X and Y coordinates as '0'
		* radius = '0'
		*/
		Circle::Circle() :Shape(), m_center(0, 0), m_radius(0)
		{
			std::cout << "Default Constructor for line is called\n" << endl;
		}

		/*Destructor for Circle
		*/
		Circle::~Circle()
		{
			std::cout << "Destructor for line is called\n" << endl;
		}

		/*Parameter Constructor for Circle
		* Center: Point object with specific values for X and Y coordinates
		* radius of type double
		*/
		Circle::Circle(const Point& p1, const double& r) :Shape(), m_center(p1), m_radius(r)
		{
			cout << "Custom/Parameter constructor for Circle is called\n" << endl;
		}

		/*Copy Constructor for Circle
		*/
		Circle::Circle(const Circle& source_c) : Shape(source_c), m_center(source_c.m_center), m_radius(source_c.m_radius)
		{
			/*Copy the data member of the source Line to another Line
			*/
			cout << "Copy Constructor of the Circle is called\n" << endl;
		}

		/*member functions
		*/
		double Circle::Diameter() const
		{
			/* Function to calculate diameter of the circle
			* arguments:
			* returns: diameter of type double
			*/

			/*Declare and initialise variables
			*/
			double diameter = 0.0;
			/*Application of formula for diameter of circle
			*/
			diameter = 2 * m_radius;
			return diameter;
		}

		double Circle::Area() const
		{
			/* Function to calculate are of the circle
			* arguments:
			* returns: area of type double
			*/

			/*Declare and initialise variables
			*/
			double area = 0.0;
			/*Application of formula for area of circle
			*/
			area = M_PI * pow(m_radius, 2);
			return area;
		}


		double Circle::Circumference() const
		{
			/* Function to calculate circumference of the circle
			* arguments:
			* returns: circumference of type double
			*/
			/*Declare and initialise variables
			*/
			double circumference = 0.0;
			/*Application of formula for circumference of circle
			*/
			circumference = 2 * M_PI * m_radius;
			return circumference;
		}

		string Circle::ToString() const
		{
			/* argument: No input arguments
			*  returns: String description of the Circle object
			*/
			/* Use the output stream class. The class uses stringbuffer.
			* The sequence of character can be accessed directly as string
			* object using member str as below
			*/
			ostringstream output;
			/*Format the floating point values on output operations
			*/
			std::string s = Shape::ToString();
			output << fixed << showpoint << setprecision(2)
				<< "The Center of the Circle is at:" << m_center.ToString() << "and the Radius is:" << Radius() << "Circle id is : " << s << endl;

			return output.str();

		}


		/*Assignment operator
		* Operator overloading
		*/
		Circle& Circle::operator = (const Circle& source_c)
		{
			/*arguments: Line object as const reference
			* return: reference to the source Line object
			*/

			/* Condition to avoid assigning to itself
			*/

			if (this == &source_c)
			{
				return *this;
			}
			else
			{
				Shape::operator=(source_c);
				m_center = source_c.m_center;
				m_radius = source_c.m_radius;

				return *this;
			}

		}

		/*The implementation uses the << operator to send data to the os input argument
		*/
		ostream& operator << (ostream& os, const Circle& c)
		{

			os << "The center of the circle is: " << c.m_center << " The radius of the circle is:  " << c.m_radius << endl;

			return os;
		}

		/*Overriden from the base class
		*/
		void Circle::Draw() const
		{
			cout << "Draw a Circle\n" << endl;
		}

	}
}

/*References
* https://quantnet.com/threads/2-3-6-issue-with-_use_math_defines-resolved.10241/#post-93083
*/