/*Author: Vishrut Talekar; Nov 2020
*/


/*Testing:
****************** Deleted functionalities already tested in level 3
***************** Already Tested in 2.4.1 *****************************
* Testing the Operator overloading for Point class primarily
*
* ***************** Already Tested in 2.4.2 *****************************
* Testing implemenation of << operator to send data to the os input argument
*
* ***************** Already Tested in 2.4.3 *****************************
* Testing the explicit constructor for Point with same
* value for coordinates x and y
*
* ***************** Already Tested in 2.4.4 *****************************
* Make ostream << operator a friend function
*
* ***************** Test in 2.5.1 *****************************
* Create Point object on Stack
*
* ******************* Already Tested in 2.5.2 *****************************
* • Create an array of Point pointers with 3 elements on the heap.
* • Create for each element in the array a point on the heap.
* • Iterate the array and print each point in the array.
* • Iterate the array again and delete each point in the array.
* • Delete the array itself.
*
* ******************* Already Tested in 2.5.3 *****************************
* Create an Array class and Test the functionalities of the class
*
* Default Constructor: Constructor that allocates 10 elements
* Parameter Constructor: Constructor with Size arguments
* Copy Constructor, Destructor,
* Member functions:
* Size, SetElements, GetElements
* Operator Overloading:
* Assignment Operator, Square bracket[] operator,
* Const version of the square bracket operator
*
* ******************** Already Tested in 2.6.1 *****************************
* Test the functionalities after embedding classes in CAD and
* Containers namespace respectively
*
* ******************** Test in 2.6.1 *****************************
* Test the functionalities after embedding classes in CAD and
* Containers namespace respectively
*
* ******************** Test in 3.4.1 *****************************
* Test Colon Syntax:
*
* ******************** Test in 3.4.2 *****************************
* Create then Shape base class of Point, Line and Circle
* Test the functionalities of Shape Class as given in the exercise
*
* ******************** Test in 3.5.1 *****************************
* Polymorphism od ToString fucnction
* Declare ToString in Shape class virtual
* Test: ToString() function of Point called when you use a Shape* that contains a Point
*
* ******************** Test in 3.5.2 *****************************
* Calling base class functionality
* Call std::string s=Shape::ToString(); in ToString of Point, Line and Circle
* Append the Shape description to Point, Line and Circle and add description string
* before returning.
*
*/
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Array.h"
#include "Shape.h"
#include<iostream>
#include<sstream>

using namespace std;
using namespace VISHRUTTALEKAR;

int main()
{
	using CAD::Shape;
	Shape s; // Create shape.

	using CAD::Point;
	Point p(10, 20);// Create point.

	using CAD::Line;
	Line l(Point(1, 2), Point(3, 4)); // Create line.

	using CAD::Circle;
	Circle c1(p, 4);

	/* Please note
	* Now ID is printed along with the Description of Point, Line
	*/
	cout << s.ToString() << endl;// Print shape
	cout << p.ToString() << endl;// Print point.
	cout << l.ToString() << endl;// Print line
	cout << c1.ToString() << endl;// Print Circle

	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work?; Yes it works
	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work?; Yes it works


	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible? Yes it is possible

	cout << "What is printed " << sp->ToString() << endl;// What is printed? Point(10.00,20.00); Now that the ToString in Shape is defined as virtual and Shape pointer is pointing to Point address
	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call the base class assignment in point? 
	/*No it is not, we need to call ToString in the base class
	*/
	return 0;
}