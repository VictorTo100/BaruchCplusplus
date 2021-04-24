/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the Point class defined in Header file
*
*/


#include "Point.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>

using namespace std;

/*Default constructor for Point
* Sets both Xand Y coordinate to '0'
*/
Point::Point() : m_x(0), m_y(0)
{
	std::cout << "Default constructor of Point is called\n" << endl;
}

/*Destructor for Point
*/
Point::~Point()
{
	std::cout << "Destructor of Point is called\n" << endl;
}

/*Construtor to initialize specific values for Point
*/

Point::Point(const double& newX, const double& newY) : m_x(newX), m_y(newY)
{
	cout << "Parameter Constructor of Point is called\n" << endl;
}

/* Construtor to initialize with same x and y coordinate for Point
*/
Point::Point(const double& value) : m_x(value), m_y(value)
{
	cout << "Intialize point using custom constructor\n" << endl;
}


//**************************** Copy constructor added *******************************************

Point::Point(const Point& source_p)
{
	/*Copy the data member of the source Point to another point
	*/
	m_x = source_p.m_x;
	m_y = source_p.m_y;

	cout << "Copy constructor of Point is called\n" << endl;
}


/*Definition of ToString function
*/
string Point::ToString() const
{
	/* argument: No input arguments
	*  returns: String description of the Point object
	*/
	/* Use the output stream class. The class uses stringbuffer.
	* The sequence of character can be accessed directly as string
	* object using member str as below
	*/
	ostringstream output;
	/*Format the floating point values on output operations
	*/
	output << fixed << showpoint << setprecision(2)
		<< "Point(" << X() << "," << Y() << ")" << endl;

	return output.str();

}

/*Definition of DistanceOrigin
*/

double Point::Distance() const
{
	/* argument: No input arguments
	*  returns: The Euclidean distance of point from the origin
	*/

	/* Decalre and initialise variable distanceOrigin
	*/
	double distanceOrigin = 0.0;
	/*Using sqrt and pow functions for calculating the square root and
	* calculate square
	*/
	distanceOrigin = std::sqrt((std::pow((m_x - 0), 2) + std::pow((m_y - 0), 2)));
	return distanceOrigin;
}

double Point::Distance(const Point& p) const
{
	/* argument: Point object as const reference
	*  returns: The Euclidean distance between 2 points
	*/

	/* Declare and initialise variable distancePoints
	*/
	double distancePoints = 0.0;
	/*Using sqrt and pow functions for calculating the square root and
	* calculate square
	*/
	distancePoints = std::sqrt((std::pow((m_x - p.m_x), 2) + std::pow((m_y - p.m_y), 2)));
	return distancePoints;
}

/*Assignment operator
* Operator overloading
*/
Point& Point::operator = (const Point& source_p)
{
	/*arguments: Point object as const reference
	* return: reference to the source Point object
	*/
	/* Condition to avoid assigning to itself
	*/
	if (this == &source_p)
	{
		return *this;
	}
	else
	{
		/* Assign the coordinates of source points
		*/
		m_x = source_p.m_x;
		m_y = source_p.m_y;

		return *this;
	}

}

/*Add coordinates of point Operator
*/
Point Point::operator + (const Point& p) const
{
	/*arguments: Point object as const reference
	* return: sum of each of the coordinates of Point
	*/

	return Point(m_x + p.m_x, m_y + p.m_y);
}


/*Scale coordinates
*/
Point Point::operator * (const double& factor) const
{
	/*arguments: Point object as const reference
	* return: sum of each of the coordinates of Point
	*/
	return Point(m_x * factor, m_y * factor);
}


/*Scale and Assign Operator; reference samples from Complex class
*/
Point& Point::operator *= (const double& factor)
{
	/*argument:
	*/
	Point tmp = (*this) * factor;
	*this = tmp;

	return *this;
}

/*The Negation Operator
*/
Point Point::operator - () const
{ /*reverse the sign of the coordinates
  */

	return Point(-m_x, -m_y);
}

/*The Comparator Operator
*/
bool Point::operator == (const Point& source_p) const
{
	/*Compare each data member of Point and
	* return true only if all are equal
	*/
	if (m_x == source_p.m_x && m_y == source_p.m_y)
	{
		return true;
	}

	else { return false; }

}

/*The implementation uses the << operator to send data to the os input argument
*/

ostream& operator << (ostream& os, const Point& p)
{ /*Send to ostream
  */

	os << p.m_x << ", " << p.m_y << endl;

	return os;
}


/*Reference
* https://quantnet.com/threads/question-about-this-in-2-4-1.41733/
*/

