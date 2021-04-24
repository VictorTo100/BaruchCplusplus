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
*
* ********************* Test in 4.2a.1 *****************************
* Create a Template Array Class to enable to store Objects of different types
* Test the functionalities of the Template Array Class
*
* ********************* Test in 4.2b.2 *****************************
* Static member default size added; test the line of code given in the exercise
* 
* ********************* Test in 4.2b.3 ****************************
* Create class PointArray by concrete inheritance
* 
* 
*/


#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Array.cpp"
#include "NumericArray.cpp"
#include "Shape.h"
#include "ArrayException.h"
#include "MatchingSizeException.h"
#include<iostream>
#include<sstream>

using namespace std;
using namespace VISHRUTTALEKAR;


int main()
{
	using Containers::NumericArray;
	using Containers::MatchingSizeException;
	using CAD::Point;

	// Test program from the homework assigments

	NumericArray<int> intArray1;
	
	NumericArray<double> doubleArray1;

	cout << "The size of intArray1 is: " << intArray1.Size() << endl;

	for (int i = 0; i < intArray1.Size(); i++)
	{
		cout << intArray1.GetElement(i);
	}

	NumericArray<int> intArray2(4); // Intialize NumericArray with Custom Constructor

	// Set the elements of array 2 and also test the Set function
	intArray2.SetElement(0, 10);
	intArray2.SetElement(1, 15);
	intArray2.SetElement(2, 20);
	intArray2.SetElement(3, 25);

	for (int i = 0; i < intArray2.Size(); i++)
	{
		cout << "The element " << (i) << " of intArray2 is: " << intArray2.GetElement(i) << endl;
	}

	// Test the copy constructor
	NumericArray<int> intArray3(intArray2);
	// Check the output for the intArray3
	for (int i = 0; i < 4; i++)
	{
		cout << "The element " << (i) << " of intArray3 is: " << intArray3.GetElement(i) << endl;
	}

	// Test setting using the square bracket operator []

	intArray2[0] = 4;
	intArray2[1] = 8;
	intArray2[2] = 12;
	intArray2[3] = 16;

	// Get using the square bracket operator
	for (int i = 0; i < 4; i++)
	{
		cout << "The element " << (i) << " intArray2 is: " << intArray2[i] << endl;
	}

	// Test the Assignment operator
	intArray3 = intArray2;
	for (int i = 0; i < intArray3.Size(); i++)
	{
		cout << "The element " << (i) << " of intArray3 is: " << intArray3.GetElement(i) << endl;
	}

	// 

	// Test the Scaling operator
 	NumericArray<int> intArray4 = intArray2*2;

	cout << "The Size of intArray2 is: " << intArray2.Size() << endl;
	cout << "The Size of intArray4 is: " << intArray4.Size() << endl;

	for (int i = 0; i < intArray4.Size(); i++)
	{
		cout << "The element " << (i) << " of intArray4 is: " << intArray4.GetElement(i) << endl;
	}

	// Test the sum(+) operator
	NumericArray<int> intArray5(4);
	cout << "The Size of intArray2 is: "  << intArray2.Size() << endl;
	cout << "The Size of intArray3 is: " << intArray3.Size() << endl;
	intArray5 = intArray2 + intArray3;

	for (int i = 0; i < intArray5.Size(); i++)
	{
		cout << "The element " << (i) << " of intArray5 is: " << intArray5.GetElement(i) << endl;
	}

	// Test the sum(+) operator with Array's of different range
	NumericArray<int> intArray6(5);
	
	try
	{
		intArray5 = intArray2 + intArray6;
	}
	catch(MatchingSizeException& err)
	{
		cout << err.GetMessage() << endl;
	}

	

	// Test The Dot product

	double dot_prod_test;

	dot_prod_test = intArray5.DotProduct(intArray4);

	cout << "The dot product between intArray4 and intArray5 is: " << dot_prod_test << endl;

	// Test the dot operator with Array's of different range
	double dot_prod_test_2;

	try
	{
		dot_prod_test_2 = intArray5.DotProduct(intArray6);
	}
	catch (MatchingSizeException& err)
	{
		cout << err.GetMessage() << endl;
	}

	return 0;
}