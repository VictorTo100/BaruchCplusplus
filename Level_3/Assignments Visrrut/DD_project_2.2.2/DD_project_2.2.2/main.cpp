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
* ************** Additions from previous exercise(2.2.1)****************************
* 
*/


#include "Point.h"
#include <iostream>
#include<iomanip>

using namespace std;

int main() 
{
	/*Initialize two points p1 and p2
	*/
	Point p1, p2;
	/*Declare and initialise variables; x and y coordinates for point p1 and p2
	*/
	double x = 0;
	double y = 0; 
	double x1 = 0; 
	double y1 = 0;

	/*Get user input for coordinates of Point
	*/
	/*Get x coordinate
	*/
	cout << "Enter x coordinate for the point" << endl;
	/*Assign the input to x variables
	*/
	cin >> x;
	/*Get user input for coordinates of Point
	*/
	/*Get y coordinate
	*/
	cout << "Enter y coordinate for the point" << endl;
	/*Assign the input to y variables
	*/
	cin >> y;

	/*Test Setters
	*/
	/*Set the value of x-coordinate of point p1
	*/
	p1.SetX(x);
	/*Set the value of y-coordinate point p1
	*/
	p1.SetY(y);

	/*Test ToString function for description
	*/
	cout << "The description of the point is:" << p1.ToString() << endl;

	/*Test the Getters
	*/
	/*Get the value of x-coordinate
	*/
	cout << std::fixed << setprecision(2) << "X coordinate of point is: " << p1.GetX() << endl;
	/*Get the value of y-coordinate
	*/
	cout << std::fixed << setprecision(2) << "Y coordinate of point is: " << p1.GetY() << endl;
	
	/*Test the DistanceOrigin function
	* calculate the distance of point p1 from origin
	*/
	cout << std::fixed << setprecision(2) << "The distance from origin is: " << p1.DistanceOrigin() << endl;

	// Initialize another POint and test the Distance function*/

	/*Get user input for coordinates of Point
	*/
	/*Get x coordinate for point p2
	*/
	cout << "Enter x coordinate for the second point" << endl;
	/*Assign the input to x1 variables
	*/
	cin >> x1;

	/*Get user input for coordinates of Point
	*/
	/*Get y coordinate for point p2
	*/
	cout << "Enter y coordinate for the second point" << endl;
	/*Assign the input to y1 variables
	*/
	cin >> y1;

	/*Set the value of x-coordinate of point p2
	*/
	p2.SetX(x1);
	/*Set the value of y-coordinate of point p2
	*/
	p2.SetY(y1);

	/*Test the DistanceOrigin function
	* calculate the distance of point p1 from origin
	*/
	cout << std::fixed << setprecision(2) << "The distance between 2 point is: " << p1.Distance(p2) << endl;

	return 0;
}


// READY FOR SUBMISSION