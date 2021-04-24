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
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++) delete shapes[i];

/*Will the proper destructors (including the destructor of the Shape base class) be called? 
* No proper destructors are not called with original code
* After adding the virtual destructor; destructors for each shape is called. 
* 
*/

/*Output from console

Default constructor for Shape with Colon Syntax is called
Default constructor for Shape with Colon Syntax is called
Default constructor of Point is called

Default constructor for Shape with Colon Syntax is called
Default constructor for Shape with Colon Syntax is called
Default constructor of Point is called

Default constructor for Shape with Colon Syntax is called
Default constructor of Point is called

default Constructor for line is called

Destructor of Shape is called
Destructor of Point is called

Destructor of Shape is called
Destructor for line is called

Destructor of Point is called

Destructor of Shape is called
Destructor of Point is called

Destructor of Shape is called
Destructor of Shape is called

V:\Baruch C++\Actual Course\Level_5\Visrrut Assignments\DD_projects_3.5.3_v2\Debug\DD_projects_3.5.3_v2.exe (process 18736) exited with code 0.
Press any key to close this window . . .

*/

	return 0;
}