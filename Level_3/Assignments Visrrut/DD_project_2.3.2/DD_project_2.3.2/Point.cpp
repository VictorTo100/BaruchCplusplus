/*
Requirements
In this exercise we are going to add distance functions to the Point class. The distance functions have the following signature:
double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
double Distance(Point p); // Calculate the distance between two points.
Add the definitions to the header file and implement the functions in the source file. Use the std::sqrt() function from the “cmath” header file 
to implement the Pythagoras algorithm. Extend the main program to print the distance between the origin and another point and test it.
*/


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


/* Define Getters and Setter */
double Point::GetX() const
{
	return m_x;
}

void Point::SetX(double newX)
{
	m_x = newX;
}


double Point::GetY() const
{
	return m_y;
}

void Point::SetY(double newY)
{
	m_y = newY;
}

string Point::ToString() const
{
	ostringstream output;

	output << fixed << showpoint << setprecision(2)
		<< "Point(" << GetX() << "," << GetY() << ")" << endl;

	return output.str();

}

double Point::DistanceOrigin()
{

	return std::sqrt((std::pow((m_x - 0), 2) + std::pow((m_y - 0), 2)));

}

double Point::Distance(const Point& p)
{
	return std::sqrt((std::pow((m_x - p.GetX()), 2) + std::pow((m_y - p.GetY()), 2)));

}