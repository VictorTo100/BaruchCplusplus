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
* * ***************** Test in 2.5.2 *****************************
* • Create an array of Point pointers with 3 elements on the heap.
* • Create for each element in the array a point on the heap.
* • Iterate the array and print each point in the array.
* • Iterate the array again and delete each point in the array.
* • Delete the array itself.
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
	
	int size = 3;

	/*Forum references
	*/
	Point** arr = new Point *[size];

	arr[0] = new Point(3, 4);
	arr[1] = new Point(6, 8);
	arr[2] = new Point(6, 4);

	/*Iterate the array and print each point in the array
	*/
	for (int i = 0; i < size; i++)
	{
		cout << *arr[i] << endl;
	}

	/*Iterate the array again and delete each point in the array
	*/
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}

	/*Iterate the array and print each point in the array
	*/
	for (int i = 0; i < size; i++)
	{
		cout << *arr[i] << endl;
	}

	/*Delete the array
	*/
	delete[] arr;

	


	return 0;
}

/*Reference
* https://quantnet.com/threads/regarding-exercise-1.35744/
* https://quantnet.com/threads/2-5-2-create-for-each-element-in-the-array-a-point-on-the-heap.43141/
*/

// READY FOR SUBMISSION