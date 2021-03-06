
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

	Point(double m_x, double m_y); // custom constructor

	~Point(); // Destructor

	Point(const Point& l); 				// Copy constructor

	/* Declare Getters and Setters*/

	double GetX() const;          // Get x coordinate of the Point 
	void SetX(double newX); // Set x value of the Point

	double GetY() const;          // Get y coordinate of the Point
	void SetY(double newY); // Set y coordinate of the Point

	/* Member function decalration*/

	// ToString function to print the description of the Point object
	std::string ToString() const;

	// Distance function to calculate distance from origin
	double DistanceOrigin();

	// Distance function to calculate distance between two points
	double Distance(const Point& p);

};

#endif