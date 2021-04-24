/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this header file is to define the Point class
* The Point Class:
* The purpose of the class is define a point in a two dimensional space
* Has two private data member to represent the X and Y coordinates of the Point
* Has Default constructor and the destructor
* Getter and Setters for X and Y coordinates
* Member function:
* ToString: To return a string description of the point

**********Additions to this exercise**********************
* DistanceOrigin:calculates the Euclidean distance of point from the origin
* Distance: 
*/

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