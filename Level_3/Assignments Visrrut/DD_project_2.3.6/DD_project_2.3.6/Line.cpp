// MP Implementation of the Line segment .cpp

#include "Line.h"
#include "Point.h"
#include <iostream>
#include<sstream>
#include<iomanip>
#include<cmath>

Line::Line() :startPoint(0, 0), endPoint(0, 0)  // Default constructor 
{
	std::cout << "default Constructor for line is called\n" << endl;
}

Line::~Line()
{

}

Line::Line(const Point& p1, const Point& p2) : startPoint(p1), endPoint(p2)
{
	cout << "Custom constructor for line is called\n" << endl;
	//startPoint = p1;
	//endPoint = p2;
}

Line::Line(const Line& l)
{
	startPoint = l.startPoint;
	endPoint = l.endPoint;

	cout << "Copy constructor of the Line is called\n" << endl;
}


Point Line::start() const
{
	return startPoint;
}

Point Line::end() const
{
	return endPoint;
}

void Line::start(const Point& pt)
{
	startPoint = pt;
}

void Line::end(const Point& pt)
{
	endPoint = pt;
}

double Line::Length() const
{
	return startPoint.Distance(endPoint);
}



const string Line::ToString() const
{
	ostringstream output;

	output << fixed << showpoint << setprecision(2)
		<< "The starting point is:" << startPoint.ToString() << "and End point is:" << endPoint.ToString() << endl;

	return output.str();

}
