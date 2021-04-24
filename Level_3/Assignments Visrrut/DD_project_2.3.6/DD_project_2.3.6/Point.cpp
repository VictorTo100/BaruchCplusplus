#include "Point.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>

using namespace std;

Point::Point() : m_x(0), m_y(0) // Default constructor with Colon Syntax
{
	cout << "default constructor for point is called" << endl;
}

Point::~Point() // Destructor
{
	cout << "destructor is called" << endl;
}

/*Copy constructor added*/
Point::Point(const Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;

	cout << "Copy constructor of point is called\n" << endl;
}

/* Construtor to initialize specific values for Point*/

Point::Point(const double& newX, const double& newY) : m_x(newX), m_y(newY)
{
	cout << "Intialize point using custom constructor\n" << endl;
}


/* Define Getters and Setter */
/*
double Point::X() const
{
	return m_x;
}
*/

void Point::X(const double& newX)
{
	m_x = newX;
}


double Point::Y() const
{
	return m_y;
}

void Point::Y(const double& newY)
{
	m_y = newY;
}

string Point::ToString() const
{
	ostringstream output;

	output << fixed << showpoint << setprecision(2)
		<< "Point(" << X() << "," << Y() << ")" << endl;

	return output.str();

}

double Point::Distance() const
{

	return std::sqrt((std::pow((m_x - 0), 2) + std::pow((m_y - 0), 2)));

}

double Point::Distance(const Point& p) const
{
	return std::sqrt((std::pow((m_x - p.X()), 2) + std::pow((m_y - p.Y()), 2)));

}