/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this header(canonical) file is to define the Line class
* The Line has Point objects as data members;
* this mechanism is called composition
* The Line Class:
* The purpose of the class is to define a line in a two dimensional space
* Has two private data member to represent the start and end points of line;
* These are Point objects as mentioned above
* Has Default constructor and the destructor
* Getter and Setters
* Member function:
* ToString: To return a string description of the point
* Length: The function calculates the length of the line
* 
* ************* Added in 2.4.1 **************************
* Operator overloading for assignment operator
*
*/

#ifndef Line_H
#define Line_H

#include "Point.h"
#include <iostream>
using namespace std;

class Line
{
private:
	/*Declare the data members of Line
	*/
	/* Starting point, Point object
	*/
	Point startPoint;

	/* Starting point, Point object
	*/
	Point endPoint;

public:
	/* Default constructor
	*  Line with both end Points at the origin
	*/
	Line();

	/* Default constructor
	*  Line with end Points [p1, p2]
	* note the Point object is passed as const reference
	*/
	Line(const Point& p1, const Point& p2);

	/* Copy Constructor
	*
	*/
	Line(const Line& source_l);

	/* Default constructor
	*/
	~Line();

	/* Declare Getters and Setters
	*/

	/* Getter for starting point
	*/
	Point start() const;
	/* Getter for end point
	*/
	Point end() const;

	/* Setter for starting point
	* Deafult inline function
	*/
	void start(const Point& pt) { startPoint = pt; }
	/* Setter for end point
	* Deafult inline function
	*/
	void end(const Point& pt) { endPoint = pt; }

	/*Length: Calculates length of the line
	*/
	double Length() const;

	/*ToString: to describe the Line object
	*/
	std::string ToString() const;

	// Assignment Operator
	Line& operator =  (const Line& l);

};
/* Normal inline functions for Getters of
* start and end point of line
*/
inline Point Line::start() const { return startPoint; }
inline Point Line::end() const { return endPoint; }

#endif

