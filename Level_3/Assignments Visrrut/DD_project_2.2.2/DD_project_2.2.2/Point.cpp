/*Author: Vishrut Talekar; Nov 2020
*/


/*The purpose of this file is to implement the Point Class defined in the header file
*
*/

#include "Point.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>

using namespace std;

/*Default constructor for Point
* Sets both X and Y coordinate to '0'
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

/*Define Getters and Setter
*/
double Point::GetX() const
{
	/*Getter function for  x-coordinate
	* arguments: No input arguments
	* returns: The X-coordinate of type double
	*/
	return m_x;
}

void Point::SetX(double newX)
{
	/*Setter function for  x-coordinate
	* Function to assign value to x-coordinate
	* arguments: number of type double
	* returns: void
	*/
	m_x = newX;
}


double Point::GetY() const
{
	/*Getter function for y-coordinate
	* arguments:
	* returns: The Y-coordinate of type double
	*/
	return m_y;
}

void Point::SetY(double newY)
{
	/*Getter function for y-coordinate
	* arguments: number of type double
	* returns: void
	*/
	m_y = newY;
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
		<< "Point(" << GetX() << "," << GetY() << ")" << endl;

	return output.str();

}

/*Definition of DistanceOrigin
*/

double Point::DistanceOrigin()
{
	/* argument: No input arguments
	*  returns: The Euclidean distance of point from the origin
	*/

	/* Decalre and initialise variable distanceOrigin
	*/
	double distanceOrigin = 0.0;
	
	distanceOrigin = std::sqrt((std::pow((m_x - 0), 2) + std::pow((m_y - 0), 2)));
	return distanceOrigin;
}

double Point::Distance(Point p)
{
	/* argument: Point object
	*  returns: The Euclidean distance between 2 points
	*/

	/* Decalre and initialise variable distancePoints
	*/
	double distancePoints = 0.0;
	
	distancePoints = std::sqrt((std::pow((m_x - p.GetX()), 2) + std::pow((m_y - p.GetY()), 2)));
	return distancePoints;
}