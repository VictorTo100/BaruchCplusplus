/*Author: Vishrut Talekar; Nov 2020
*/
/*Testing:
* 1. Include the point header file.
* 2. Ask the user for the x- and y-coordinates using the std::cin object (needs the “iostream” header file).
* 3. Then create a Point object using the default constructor.
* 4. Set the coordinates entered by the user using the setter functions.
* 5. Print the description of the point returned by the ToString() function.
* 6. Print the point coordinates using the get functions.
*
* ************** Already test in 2.3.1 ****************************
* Test the application and role of copy constructor
	* 1. In absence of defined Copy Constructor the parameter
	* Constructor is called twice we get the
	* Copy Constructor for free and destructor is called thrice
	* 2. In presence of defined Copy Constructor the parameter
	* Constructor is called twice the defined
	* Copy Constructor is called and destructor is called thrice

* ************** Already tested in 2.3.2 ****************************
* The point object is passed as 'const reference' in the Distance() function
*
* **************** Already tested in 2.3.3 *************************
* Test the function overloading for getters, setters and Distance
*
* ***************** Already tested in 2.3.4 *************************
* Test const function accesses
*
* **************** Already Tested in 2.3.5 *************************
* Implement the Line class with;
* Default Constructor, Desstructor, Parameter Constructor, Copy Constructor, ToString
* Getters, Setter, Length()
* Point object as data members to define starting and ending of line
* Test the functionalities of Line class
*
* **************** Alread Tested in this 2.3.6 *************************
* Implement the Circle class with;
* Default Constructor, Desstructor, Parameter Constructor, Copy Constructor, ToString
* Getters, Setter, Length()
* Point object as data members to define center of Circle
* Test the functionalities of Line class
*
* **************** Already tested in 2.3.7 inline functions *****************************
* Added inline functions for Getters and Setter for Point, Line and Circle
*
***************** Tested in 2.4.1 *****************************
* Testing the Operator overloading for Point class primarily
*
* ***************** Test in 2.4.2 *****************************
* Testing implemenation of << operator to send data to the os input argument
*
* ***************** Test in 2.4.3 *****************************
* Testing the explicit constructor for Point with same
* value for coordinates x and y
*
* ***************** Test in 2.4.4 *****************************
* Make ostream << operator a friend function
*
* ***************** Test in 2.5.1 *****************************
* Create Point object on Stack
*
* ******************* Test in 2.5.2 *****************************
* • Create an array of Point pointers with 3 elements on the heap.
* • Create for each element in the array a point on the heap.
* • Iterate the array and print each point in the array.
* • Iterate the array again and delete each point in the array.
* • Delete the array itself.
*
* ******************* Test in 2.5.3 *****************************
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
*  ******************* Test in 2.6.1 *****************************
* Test the functionalities after embedding classes in CAD and 
* Containers namespace respectively
*
*/



#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Array.h"
#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	/*Testing the full namespace for Point class
	*/
	VISHRUTTALEKAR::CAD::Point p1(3, 6); 
	VISHRUTTALEKAR::CAD::Point p2(6, 9);
	cout << "Point p1 is: " << p1 << "and Point p2 is: "<< p2 <<endl;

	/*Testing using declaration for using a single class (Line).
	*/
	using VISHRUTTALEKAR::CAD::Line;    
	Line l1(p1, p2); 
	cout << "Line l1 is: " << l1 << endl;

	/*using declaration for a complete namespace (Containers)
	*/
	using namespace VISHRUTTALEKAR::Containers;
	Array arr1(1);
	using namespace VISHRUTTALEKAR::CAD;
	arr1[0] = Point(2, 4);

	cout << arr1[0] << endl;

	/*Create Alias
	*/
	/* Notes slide 14
	*/
	namespace VT = VISHRUTTALEKAR::CAD; 

	using VT::Circle;
	Circle c1(VT::Point(2, 2), 1);
	cout << "Circle c1 is: " << c1 << endl;


	/* Test functionalities developed and tested in earlier excerices 
	*/
	/*Declare Point objects
	*/
	Point p3, p4;

	/*Declare Line objects
	*/
	Circle c2;

	/*Set the coordinates of point p1
	*/
	p3.X(2);
	p3.Y(4);
	/* Set the coordinates of point p2
	*/
	p4.X(3);
	p4.Y(6);

	/*Testing for the osstream change to print the Point object
	*/
	cout << "Point p1 is: " << p1 << endl;

	/*Declare Line objects
	*/
	Line l2(p3, p4);

	/*Testing for the osstream change to print the Line object
	*/
	cout << "Line l1 is: " << l1 << endl;
	
	c2.CenterPoint(p3);
	c2.Radius(4);

	/*Testing for the osstream change to print the Line object
	*/
	cout << "Circle c1 is: " << c1 << endl;

	/*Testing the Operator Overloading for point
*/

/*Testing the Negation Operator for Point Object
*/
	p3 = -p1;
	cout << "The output for p3 should result in negative of each coordinate of p1" << p3.ToString() << "\n" << endl;

	/*Test the scale and assign operator for Point object
	*/
	p2 *= -3;
	cout << "The output for p2 should result in negatively scaled by factor of " << p2.ToString() << "\n" << endl;

	/*Test the scale operator
	*/
	p3 = p1 * -3;

	cout << "The output for p3 should result in scaled by factor of p1 " << p3.ToString() << "\n" << endl;
	cout << "Check if p1 has remained unchanged " << p1.ToString() << "\n" << endl;

	/*Test the add operator
	*/
	p3 = p1 + p2;
	cout << "The output for p3 should result in addition of p1 and the changed p2 " << p3.ToString() << "\n" << endl;

	/*Test the assignment operator
	*/
	p2 = p1;

	cout << "The value of p2 should be same as p1 " << p2.ToString() << "\n" << endl;

	/*Check for the Comparator
	*/
	cout << "Comparator check for p1 and p2; 1 if true:  " << (p1 == p2) << "\n" << endl;


	/*Test assignment operator for Circle
	*/
	c2 = c1;

	cout << "check for c1 assigned to c2 " << c2.ToString() << "\n" << endl;

	/*Test  the assignment operator for Line
	*/
	l2 = l1;

	cout << "check for l1 assigned to l2 " << l2.ToString() << "\n" << endl;

	/*Intialize Array with parameter constructor with specific size
*/
	Array arr2(4);

	/*Set the elements of array 2 and also test the Set function
	*/
	arr2.SetElement(0, Point(3.5, 4.5));
	arr2.SetElement(1, Point(6, 9));
	arr2.SetElement(2, Point(5, 7));
	arr2.SetElement(3, Point(10, 11));

	/*Print the elements using the GetElements
	*/
	for (int i = 0; i < 4; i++)
	{
		cout << "The element " << (i) << " of arr2 is: " << arr2.GetElement(i) << endl;
	}

	/*Test the copy constructor
	*/
	Array arr3(arr2);

	/*Check the output for the arr3
	*/
	for (int i = 0; i < 4; i++)
	{
		cout << "The element " << (i) << " of arr3 is: " << arr3.GetElement(i) << endl;
	}

	/*Test setting using the square bracket operator []
	*/

	arr2[0] = Point(3.5, 4.5);
	arr2[1] = Point(6, 9);
	arr2[2] = Point(5, 7);
	arr2[3] = Point(10, 11);

	/*Get using the square bracket operator
	*/
	for (int i = 0; i < 4; i++)
	{
		cout << "The element " << (i) << " of arr2 is: " << arr2[i] << endl;
	}

	/*https://quantnet.com/threads/2-5-3-const-point-operator-int-index-const-purpose-of-first-const.40417/
	*/
	/*Test the const return version of the square bracket operator
	*/
	const Array arr4(arr3);

	for (int i = 0; i < 4; i++)
	{
		cout << "The element " << (i) << " of arr4 is: " << arr4[i] << endl;
	}
	return 0;
}