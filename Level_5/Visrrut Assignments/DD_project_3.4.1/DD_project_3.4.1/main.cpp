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
* 
*/


#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Array.h"
#include<iostream>
#include<sstream>

using namespace std;
using namespace VISHRUTTALEKAR;

int main()
{
	
	/*Test the use of Colon syntax in the constructor
	*/
	using CAD::Line;

	//Line l1(CAD::Point(3, 5), CAD::Point(6, 10));

	Line l1;

	cout << "Line is " << (l1) << endl;


	return 0;
}

// READY FOR SUBMISSION

/* The difference is due to following
* When Colon syntax is not used default constructors of Point is invoked
* twice for each data member when Line construstor is called; Then again called when 
* startPoint and endPoint is assigned in the constructor
*  
*/


/* Without Colon Syntax in Line class class
* 
Default constructor of Point is called

Default constructor of Point is called

Default constructor of Point is called

Default constructor of Point is called

default Constructor for line is called

Destructor of Point is called

Destructor of Point is called

Line is The starting point is:Point(0.00,0.00)
and End point is:Point(0.00,0.00)

Destructor for line is called

Destructor of Point is called

Destructor of Point is called
*/

/* With Colon Syntax

Default constructor of Point is called

Default constructor of Point is called

default Constructor for line is called

Line is The starting point is:Point(0.00,0.00)
and End point is:Point(0.00,0.00)



Destructor for line is called

Destructor of Point is called

Destructor of Point is called



*/