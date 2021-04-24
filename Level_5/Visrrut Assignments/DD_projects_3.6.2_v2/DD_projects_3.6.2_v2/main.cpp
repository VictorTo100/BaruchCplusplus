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
* ******************** Test in 3.5.4 *****************************
* Make Shape Abstract class
* Add pure virtual function
* virtual void Draw()=0;
*
* ********************* Test in 3.5.5  *****************************
* Make Shape Abstract class
* Add pure virtual function
* virtual void Draw()=0;
*
* ********************* Test in 3.6.1  *****************************
* In the GetElement(), SetElement() and index operator throw -1 if the index was toosmall or too big.
• In the main program, create an Array object and access an element that does not exist.Run the program. What happens?
• The exception must be caught, so place the code inside a try ... catch block thatcatches an int.
• In the catch handler, print an error message;
*
* ********************* Test in 3.6.2  *****************************
* create an exception hierarchy with an ArrayException base class and an OutOfBoundsExceptionderived class
* Test the class functionalities
*/

/*Exception handling using Try and Catch blocks
*/
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Array.h"
#include "Shape.h"
#include "ArrayException.h"
#include "OutOfBoundsException.h"
#include<iostream>
#include<sstream>

using namespace std;
using namespace VISHRUTTALEKAR;


int main()
{
	using Containers::Array;
	using Containers::ArrayException;
	using Containers::OutOfBoundsException;

	/*As suggested in the last exercise 
	* create an Array object and access an element that does not exist
	*/
	Array arr(2);
	
	/*Test the exception by assigning the index which does not exists
	*/
	try
	{
		cout << arr[4] << endl;
	}

	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}

	/*Test the exception by assigning the index which does not exists
	*/
	try
	{
		cout << arr.GetElement(4) << endl;
	}

	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}

	/*Test the exception by assigning the index which does not exists
	*/
	try
	{
		arr[4] = CAD::Point(2, 4);
	}

	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}

	/*Test the exception by assigning the index which does not exists
	*/
	try
	{
		arr.SetElement(4, CAD::Point(2, 4));
	}
	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}

	/*Repeat the above two for negative index
	*/
	/*Test the exception by accessing index which does not exists
	*/
	try
	{
		cout << arr[-1] << endl;
	}

	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}

	try
	{
		cout << arr.GetElement(-1) << endl;
	}

	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}


	/*Test the exception by assigning the index which does not exists
	*/
	try
	{
		arr[-1] = CAD::Point(2, 4);
	}
	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}

	/*Test the exception by assigning the index which does not exists
	*/
	try
	{
		arr.SetElement(-1, CAD::Point(2, 4));
	}
	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}

	return 0;
}


// READY FOR SUBMISSION