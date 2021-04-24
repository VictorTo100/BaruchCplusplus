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
	void CenterPoint(const Point& pt) { m_center = pt; }					// Set Point pt1
	void Radius(const double& r) { m_radius = r; }						// Set Point pt2

	double Diameter() const;
	double Area() const;
	double Circumference() const;

	// ToString function to print the description of the Point object
	std::string ToString() const;

};

inline Point Circle::CenterPoint() const { return m_center; }
inline double Circle::Radius() const { return m_radius; }


#endif

