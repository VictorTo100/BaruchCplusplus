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
*  **************** Already tested in 2.3.4 *************************
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
	double r = 3;
	
	/*Declare Point objects
	*/
	Point p1, p2;

	/*Declare Line objects
	*/
	Circle c1;

	/*Set the coordinates of point p1 
	*/
	p1.X(2);
	p1.Y(4);
	/* Set the coordinates of point p2
	*/
	p2.X(3);
	p2.Y(6);

	/*Testing for the osstream change to print the Point object
	*/
	cout << "Point p1 is: " << p1 << endl;

	/*Declare Line objects
	*/
	Line l1(p1, p2);

	/*Testing for the osstream change to print the Line object
	*/
	cout << "Line l1 is: " << l1 << endl;

	c1.CenterPoint(p1);
	c1.Radius(r);

	/*Testing for the osstream change to print the Line object
	*/
	cout << "Circle c1 is: " << c1 << endl;

	return 0;
}