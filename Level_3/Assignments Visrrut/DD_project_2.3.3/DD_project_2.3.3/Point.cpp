#include "Point.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>

using namespace std;

Point::Point() : m_x(0), m_y(0) // Default constructor 
{
	cout << "constructor is called" << endl;
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

	cout << " copy constructor is called" << endl;
}

/* Construtor to initialize specific values for Point*/

Point::Point(double newX, double newY) : m_x(newX), m_y(newY)
{
	cout << "Intialize using custom constructor" << endl;
}


/* */
/* Define Getters and Setter */
double Point::X() const
{
	return m_x;
}

void Point::X(double newX)
{
	m_x = newX;
}


double Point::Y() const
{
	return m_y;
}

void Point::Y(double newY)
{
	m_y = newY;
}

const string Point::ToString() const
{
	ostringstream output;

	output << fixed << showpoint << setprecision(2)
		<< "Point(" << X() << "," << Y() << ")" << endl;

	return output.str();

}

double Point::Distance()
{

	return std::sqrt((std::pow((m_x - 0), 2) + std::pow((m_y - 0), 2)));

}

double Point::Distance(const Point& p)
{
	return std::sqrt((std::pow((m_x - p.X()), 2) + std::pow((m_y - p.Y()), 2)));

}