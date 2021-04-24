/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this header(canonical) file is to define the Circle class
* The Circle has Point objects as data members definining the center;
* this mechanism is called composition
*
* The Circle Class:
* The purpose of the class is to define a Circle
* Has two private data member to represent the center and radius;
* Point Object as center and radius of type double
* Has Default constructor and the destructor
* Getter and Setters
* Member function: to calculate
* Diameter, Area, Circumference of the Circle
* ************** Added in 2.4.1 **************************
* Operator overloading for assignment operator
* 
* 
*/


#ifndef Circle_H
#define Circle_H

#include "Point.h"
#include <iostream>
using namespace std;

class Circle
{
private:
	/*Declare the data members of Circle
	*/
	/* Point as center
	*/
	Point m_center;
	/*radius of type double
	*/
	double m_radius;

public:
	/* Default constructor
	*  with center Point(0,0) and radius = 0
	*/
	Circle();
	/* Parameter Constructor
	*  Point with parameters
	*  radius of type double
	*/
	Circle(const Point& p1, const double& r)

		/* Copy Constructor
		*
		*/;
	Circle(const Circle& c);

	/* Destructor
	*/
	~Circle();

	/* Getter for starting point
	*/
	Point CenterPoint() const;
	/* Getter for starting point
	*/
	double Radius() const;

	/*Set the value of center of Circle object
	* Default inline function
	*/
	void CenterPoint(const Point& pt) { m_center = pt; }

	/*Set the value of radius of Circle object
	* Default inline function
	*/
	void Radius(const double& r) { m_radius = r; }

	/* Function to calculate the diameter of Circle
	*/
	double Diameter() const;
	/* Function to calculate the area of the Circle
	*/
	double Area() const;

	/* Function to calculate the circumference of Circle
	*/
	double Circumference() const;

	/*ToString: to describe the Circle object
	*/
	std::string ToString() const;

	//Assignment Operator
	Circle& operator =  (const Circle& source_c);

};

/*Normal inline functions to get the center and radius of the circle
*/
inline Point Circle::CenterPoint() const { return m_center; }
inline double Circle::Radius() const { return m_radius; }


#endif