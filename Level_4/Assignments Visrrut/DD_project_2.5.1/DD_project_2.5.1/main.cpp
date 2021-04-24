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
* Create Point object on Stack using 'new'
* 
*/

#include "Point.h"
#include"Line.h"
#include "Circle.h"
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	/*Declare and initialise variables; xand y coordinates for point p1and p2
	*/
	int size = 0;

	/*Declare Point pointers
	*/
	Point* p1;
	Point* p2;
	Point* p3;
	Point* p4;

	/*Assign Point object to the pointer using, default constructor, parameter constructor, 
	* parameter constructor with single value for x and y, copy constructor 
	*/
	p1 = new Point();
	p2 = new Point(3, 6);
	p3 = new Point(*p2); 
	p4 = new Point(6);

	/*Assign Point object to the pointer using, default constructor, parameter constructor,
	* parameter constructor with single value for x and y, copy constructor
	*/
	cout << "Point p1 is: " << (*p1) << "\n";
	cout << "Point p2 is: " << (*p2) << "\n";
	cout << "Point p3 is: " << (*p3) << "\n";
	cout << "Point p4 is: " << (*p4) << "\n";

	/*Calculate the distance between points
	*/
	cout << "The distance between point p1 and point p2 is: " << (*p1).Distance(*p2) << "\n";
	cout << "The distance between point p2 and point p3 is: " << (*p2).Distance(*p3) << "\n";
	cout << "The distance between point p1 and point p3 is: " << (*p1).Distance(*p3) << "\n";

	/*Delete the pointers
	*/
	delete p1;
	delete p2;
	delete p3;

	/*Get user input for size of the array as asked in the excercise	
	*/
	cout << "Enter size of the array \n";
	cin >> size;

	/* Check for compile error
	Error	C2131	 expression did not evaluate to a constant	
	*/
	//Point arr[size]; 

	/* Cannot call other than default constructor; DD notes 02-05, slide 9
	*/
	Point* arr = new Point[size]; 

	/*Assign value to the x-coordinate to first element of array
	*/
	arr[0].X(10);
	arr[0].Y(5);

	/*Print the value of arr using dereferencing
	*/
	cout << "The first element of array is: " << (arr[0]) << "\n";
	/*Delete the array using square brackets
	*/
	delete[] arr;
	return 0;
}


/*Reference
* https://quantnet.com/threads/regarding-exercise-1.35744/
*/

// READY FOR SUBMISSION
