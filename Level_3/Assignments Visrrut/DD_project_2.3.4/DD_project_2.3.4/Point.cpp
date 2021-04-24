/*
Requirements
In the test program create a const point and try to set the x-coordinate:
const Point cp(1.5, 3.9);
cp.X(0.3);
Compile the program. Did you get a compiler error? It should give a compiler error because you try to change a const object.
Now replace the line that changes the x-coordinate to code that reads the x-coordinate:
cout<<cp.X()<<endl;
Compile the program again. You will see that is still gives a compiler error even while retrieving the x-coordinate does not change the point object. 
This is because the compiler does not know that the function does not change anything. 
So we need to mark the x-coordinate getter as const by making it a const function. 
Do this also for the y-coordinate getter and the Distance() and ToString() functions because these don’t change the point object as well. 
Recompile the application. It should now work.
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