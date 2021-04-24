#ifndef Circle_H
#define Circle_H

#include "Point.h"
#include <iostream>
using namespace std;

class Circle
{
private:

	Point m_center; 
	double m_radius;

public:

	/* Declaration for Constructors and Destructors*/

	Circle();									// Default constructor Circle with Center Point(0, 0) and Radius 0
	Circle(const Point& p1, const double& r);	// Constructor with parameters
	Circle(const Circle& c); 				  // Copy constructor
	~Circle();							// Destructor

	// Accesssing functions
	Point CenterPoint() const;
	double Radius() const;

	// Modifiers
	void CenterPoint(const Point& pt);					// Set Point pt1
	void Radius(const double& r);						// Set Point pt2

	double Diameter() const;
	double Area() const;
	double Circumference() const;

	// ToString function to print the description of the Point object
	std::string ToString() const;

};

#endif



