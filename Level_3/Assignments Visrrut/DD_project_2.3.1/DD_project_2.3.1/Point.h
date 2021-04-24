#ifndef Point_H
#define Point_H

#include<iostream>
using namespace std;

class Point
{
private:
	/*Declare the data members of Point
	*/
	/* X coordinate of type double
	*/
	double m_x;
	/* Y coordinate of type double
	*/
	double m_y;

public:
	/* Default constructor
	*/
	Point();
	/*Destructor
	*/
	~Point();
	/*Constructor with parameters
	*/
	Point(double m_x, double m_y); 
	/*Copy constructor
	*/
	Point(const Point& p); 				

	/* Declare Getters and Setters
	*/

	/*Function to get X coordinate
	* declared as const to make the state of the object is not changed
	*/
	double GetX() const;
	/*Function to get X coordinate
	* Set the value of X coordinate
	*/
	void SetX(double newX);
	/*Function to get X coordinate
	*/
	double GetY() const;
	/*Function to get X coordinate
	*/
	void SetY(double newY);

	/*Member functions
	*/

	/*ToString: to describe the Point object
	*/
	std::string ToString() const;

	/*Distance function to calculate Euclidean distance from origin
	*/
	double DistanceOrigin();

	/*Distance function to calculate Euclidean distance between two points
	*/
	double Distance(Point p);

};

#endif