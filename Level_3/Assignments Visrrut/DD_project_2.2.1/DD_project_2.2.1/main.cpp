/*Author: Vishrut Talekar; Nov 2020
*/

/*Testing:
* 1. Include the point header file.
* 2. Ask the user for the x- and y-coordinates using the std::cin object (needs the “iostream” header file).
* 3. Then create a Point object using the default constructor.
* 4. Set the coordinates entered by the user using the setter functions.
* 5. Print the description of the point returned by the ToString() function.
* 6. Print the point coordinates using the get functions.
*/

#include "Point.h"
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	/*Initialize a point p1
	*/
	Point p1; 

	/*Declare and initialise variables
	*/
	/*Intialise x and y coordinates of point p1
	*/
	double x = 0.0;
	double y = 0.0;
	
	/*Get user input for coordinates of Point
	*/
	/*Get x coordinate
	*/
	cout << "Enter x coordinate for the point\n" << endl;
	/*Assign the input to x variables
	*/
	cin >> x;
	/*Get x coordinate
	*/
	cout << "Enter y coordinate for the point\n" << endl;
	/*Assign the input to x variables
	*/
	cin >> y; 

	/*Test Setters
	*/
	/*Set the value of x-coordinate
	*/
	p1.SetX(x);
	/*Set the value of y-coordinate
	*/
	p1.SetY(y);

	/*Test ToString function for description
	*/
	cout << "The description of the point is:" << p1.ToString() << endl;

	/*Test the Getters
	*/
	/*Get the value of x-coordinate
	*/
	cout << std::fixed <<setprecision(2) << "X coordinate of point is: " << p1.GetX() << endl;
	/*Get the value of y-coordinate
	*/
	cout << std::fixed << setprecision(2) << "Y coordinate of point is: " << p1.GetY() << endl;

	return 0;
}

//READY FOR SUBMISSION//
