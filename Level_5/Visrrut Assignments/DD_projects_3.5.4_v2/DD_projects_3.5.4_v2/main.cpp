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
* ******************** Test in 3.5.3 *****************************
* Virtual Destructors
* Declare the Destructor of the Shape Class virtual so that
* derived class destructors are appropriately called
*
*  ******************** Test in 3.5.4 *****************************
* Make Shape Abstract class
* Add pure virtual function
* virtual void Draw()=0;
* 
* 
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
	using CAD::Point;
	using CAD::Line;
	using CAD::Circle;

	/*
	Now Shape is an abstract class and the object cannot be instantiated but;
	A pointer to the Shape can be created
	*/
	/*Test the draw shapes using following code  given in the exercise
	*/
	Shape* shapes[10];
	shapes[0] = new Line;
	shapes[1] = new Point(3, 6);
	shapes[2] = new Point(5);
	shapes[3] = new Circle;
	shapes[4] = new Line(Point(), Point(3, 6));
	shapes[5] = new Point;
	shapes[6] = new Circle(Point(2, 3), 3);
	shapes[7] = new Circle(Point(), 2);
	shapes[8] = new Point;
	shapes[9] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));

	for (int i = 0; i < 10; i++) shapes[i]->Draw();

	for (int i = 0; i < 10; i++) delete shapes[i];

	return 0;
}