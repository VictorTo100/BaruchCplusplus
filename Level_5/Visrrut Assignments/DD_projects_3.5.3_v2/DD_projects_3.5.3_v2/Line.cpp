/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the Line class defined in Line Header file
*/

#include "Line.h"
#include "Point.h"
#include "Shape.h"
#include <iostream>
#include<sstream>
#include<iomanip>
#include<cmath>

namespace VISHRUTTALEKAR
{
	namespace CAD
	{
		/*Default constructor for Point
		* Sets both X and Y coordinates of
		* start and end point  to '0'
		*/


		Line::Line() :Shape(), startPoint(Point()), endPoint(Point())
		{
			std::cout << "default Constructor for line is called\n" << endl;
		}

		Line::~Line()
		{
			std::cout << "Destructor for line is called\n" << endl;
		}

		/* Construtor to initialize Line with specific values for Point
		* Point is passed as 'const reference'
		*/
		Line::Line(const Point& p1, const Point& p2) : Shape(), startPoint(p1), endPoint(p2)
		{
			cout << "Parameter Constructor for line is called\n" << endl;
		}

		Line::Line(const Line& source_l) : Shape(source_l), startPoint(source_l.startPoint), endPoint(source_l.endPoint)
		{
			/*Copy the data member of the source Line to another Line
			*/
			cout << "Copy Constructor of the Line is called\n" << endl;
		}

		double Line::Length() const
		{
			/* argument:
			*  returns: The Euclidean distance between 2 points
			*/

			/* Uses the Distance function from Point class
			* This mechanism is called 'delegation'
			*/
			return startPoint.Distance(endPoint);
		}


		string Line::ToString() const
		{
			/* argument: No input arguments
			*  returns: String description of the Line object
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
				<< "The starting point is:" << startPoint.ToString() << "and End point is:" << endPoint.ToString() << " The id of Line is: " << s << endl;

			return output.str();

		}

		/*Assignment operator
		*Operator overloading
		*/
		Line& Line::operator = (const Line& source_l)
		{
			/*arguments: Line object as const reference
			* return: reference to the source Line object
			*/

			/* Condition to avoid assigning to itself
			*/
			if (this == &source_l)
			{
				return *this;
			}
			else
			{
				Shape::operator=(source_l);
				startPoint = source_l.startPoint;
				endPoint = source_l.endPoint;

				return *this;
			}

		}

		/*The implementation uses the << operator to send data to the os input argument
		*/
		ostream& operator << (ostream& os, const Line& l)
		{ // Send to ostream

			os << l.ToString() << endl;

			return os;
		}


	}
}