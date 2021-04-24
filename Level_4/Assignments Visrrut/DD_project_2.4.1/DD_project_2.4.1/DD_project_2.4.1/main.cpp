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

	/*Declare and initialise variables; x and y coordinates for point p1 and p2
	*/
	double x = 0;
	double y = 0;
	double x1 = 0;
	double y1 = 0;
	double r = 0;
	/*Declare Point objects
	*/
	Point p1, p2;

	/*Declare Line objects
	*/
	Line l1;

	/*Declare Line objects
	*/
	Circle c1;

	/*Test if the inline functions are working
	*/
	/*Set coordinate of Point
	*/
	/*Point p1
	*/
	p1.X(2);
	p1.Y(4);
	/* Point p2
	*/
	p2.X(3);
	p2.Y(6);

	/*Set start and end of Line
	*/
	l1.start(p1);
	l1.end(p2);

	/* Initialize the Circle using setters*/
	/*Set center and radius of Circle
	*/
	c1.CenterPoint(p1);
	c1.Radius(3);


	/*Testing the Operator Overloading for point
	*/

	/*Testing the Negation Operator for Point Object
	*/
	Point p3 = -p1;
	cout << "The output for p3 should result in negative of each coordinate of p1" << p3.ToString() << "\n" << endl;

	/*Test the scale and assign operator for Point object
	*/
	p2 *= 10;
	cout << "The output for p2 should result in negatively scaled by factor of " << p2.ToString() << "\n" << endl;

	/*Test the scale operator
	*/
	p3 = p1*-10;

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
	cout << "Comparator check for p1 and p2; 1 if true:  " << (p1==p2) << "\n" << endl;

	
	/*Test assignment operator for Circle
	*/ 
	Circle c2 = c1;

	cout << "check for c1 assigned to c2 " << c2.ToString() << "\n" << endl;

	/*Test  the assignment operator for Line
	*/
	Line l2 = l1;

	cout << "check for l1 assigned to l2 " << l2.ToString() << "\n" << endl;

	return 0;
}