#ifndef Point_H
#define Point_H

#include<iostream>
using namespace std;

class Point
{

private:

	double m_x; // X coordinate
	double m_y; // Y coordinate
public:

	Point(); // default constructor

	Point(const double& m_x, const double& m_y); // custom constructor

	~Point(); // Destructor

	Point(const Point& p); 				// Copy constructor

	/* Declare Getters and Setters*/

	double X() const;          // Get x coordinate of the Point 
	void X(double newX); // Set x value of the Point

	double Y() const;          // Get y coordinate of the Point
	void Y(double newY); // Set y coordinate of the Point

	/* Member function decalration*/

	// ToString function to print the description of the Point object
	std::string ToString() const;

	// Distance function to calculate distance from origin
	double Distance() const;

	// Distance function to calculate distance between two points
	double Distance(const Point& p) const;

};

#endif
