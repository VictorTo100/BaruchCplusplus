#define _USE_MATH_DEFINES

#include "Point.h"
#include "Circle.h"
#include <iostream>
#include<sstream>
#include<iomanip>
#include<cmath>

// Default Constructor
Circle::Circle() :m_center(0, 0), m_radius(0)  // Default constructor 
{
	std::cout << "default Constructor for line is called\n" << endl;
}

// Destructor
Circle::~Circle()
{

}

/*Constructor with parameters using the colon syntax*/
Circle::Circle(const Point& p1, const double& r) : m_center(p1), m_radius(r)
{
	cout << "Custom/Parameter constructor for Circle is called\n" << endl;
}

Circle::Circle(const Circle& c)
{
	m_center = c.m_center;
	m_radius = c.m_radius;

	cout << "Copy constructor of the Circle is called\n" << endl;
}

double Circle::Diameter() const
{
	return 2 * m_radius;
}

double Circle::Area() const
{
	return M_PI * pow(m_radius, 2);
}

double Circle::Circumference() const
{
	return 2 * M_PI * m_radius;
}


string Circle::ToString() const
{
	ostringstream output;

	output << fixed << showpoint << setprecision(2)
		<< "The Center of the Circle is at:" << m_center.ToString() << "and the Radius is:" << Radius() << endl;

	return output.str();

}


