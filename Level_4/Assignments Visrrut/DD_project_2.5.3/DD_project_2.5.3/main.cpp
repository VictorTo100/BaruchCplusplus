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
* Parameter Constructor: Constrcutor with Size arguments
* Copy Constructor, Destructor, 
* Member functions:
* Size, SetElements, GetElements
* Operator Overloading:
* Assignment Operator, Square bracket[] operator, 
* Const version of the square bracket operator
* 
* 
*/

#include "Point.h"
#include "Array.h"
#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	/*Initialize array with default constructor
	*/
	Array arr1; 

	/*The the default constructor of Array;
	* we expect 10 elements of Point with (0, 0)
	*/

	for (int i=0; i < 10; i++)
	{
		cout << arr1.GetElement(i);
	}

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

/*References
* https://quantnet.com/threads/2-5-3-const-point-operator-int-index-const-purpose-of-first-const.40417/
*/

// READY FOR SUBMISSION