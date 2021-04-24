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
* **************** Tested in 2.4.1 *****************************
* Testing the Operator overloading for Point class primarily
*
* ***************** Test in 2.4.2 *****************************
* Testing implemenation of << operator to send data to the os input argument
*
* ***************** Test in 2.4.3 *****************************
* Testing the explicit constructor for Point with same 
* value for coordinates x and y 
*
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

	/*Testing the Constructor as implicit conversion operator
	Error	C2678	 binary '==': no operator found which takes a left - hand operand of type 'Point' (or there is no acceptable conversion)	
		DD_project_2.4.3	V : \Baruch C++\Actual Course\Level_4\Assignments Visrrut\DD_project_2.4.3\DD_project_2.4.3\main.cpp	45
	*/

	Point p(1.0, 1.0);
	if (p == (Point)1.0) cout << "Equal!" << endl;
	//if (p == 1.0) cout << "Equal!" << endl;
	else cout << "Not equal" << endl;

	return 0;
}