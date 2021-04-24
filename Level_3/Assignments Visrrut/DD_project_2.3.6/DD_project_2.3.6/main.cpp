/*
Requirements
Create a Circle class. It has a center point and radius. Create the proper constructors, destructor, selector and modifier functions. 
Also add functions for getting the diameter, area and circumference. Don’t forget a ToString() function.
In further exercises, all optimizations requested for Line should also be implemented for Circle

*/

#include "Point.h"
#include "Circle.h"
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	/*
	This example shows that the copy constructor does not get called when the Distance function is called
	*/

	double x, y, r;

	cout << " Enter X coordinate for the Center Point of the Circle" << endl;
	cin >> x;

	cout << "Enter Y coordinate for the Center Point of the Circle" << endl;
	cin >> y;

	Point p1(x, y); // Intialize Point 1 using the custom constructor

	/*
	Test the Getter and Setter Overloading
	*/

	p1.X(4);
	p1.Y(8);

	cout << " The description of the point is:" << p1.ToString() << endl;
	cout << std::fixed << setprecision(2) << " X coordinate of point is: " << p1.X() << endl;
	cout << std::fixed << setprecision(2) << " Y coordinate of point is: " << p1.Y() << endl;

	/*
	Test the Distance function
	Function Overloading for DistanceOrigin() to Distance()
	*/

	cout << std::fixed << setprecision(2) << " The distance from origin is: " << p1.Distance() << endl;

	/* Initialize the Circle using parameterized constructor*/
	cout << " Enter Radius of the Circle: \n" << endl;

	cin >> r;
	
	cout << "Initialize the Circle\n" << endl;
	Circle c1(p1, r);

	cout << "The description of the Circle:" << c1.ToString() << "\n" << endl;

	cout << "The Diameter of the Circle is:" << c1.Diameter() << "\n" << endl;

	cout << "The Area of the Circle is:" << c1.Area() << "\n" << endl;

	cout << "The Circumference of the Circle is:" << c1.Circumference() << "\n" << endl;

	return 0;
}

// READY FOR SUBMISSION