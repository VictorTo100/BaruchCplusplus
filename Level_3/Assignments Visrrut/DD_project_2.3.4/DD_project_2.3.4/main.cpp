#include "Point.h"
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	/*
	This example shows that the copy constructor does not get called when the Distance function is called
	*/

	double x, y, x1, y1;

	cout << " Enter x coordinate for the point 1" << endl;
	cin >> x;

	cout << " Enter y coordinate for the point 1" << endl;
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

	/* Test the Distance function*/
	cout << " Enter x1 coordinate for the point 2" << endl;
	cin >> x1;

	cout << " Enter y2 coordinate for the point 2" << endl;
	cin >> y1;

	Point p2(x1, y1); // Intialize Point 2 using the custom constructor

	cout << std::fixed << setprecision(2) << " The distance between 2 point is: " << p1.Distance(p2) << endl;


	/* The program does not give an compiler error for cp.X(), because I have used 'const' in the earlier programs as well */

	const Point cp(1.5, 3.9);
	// cp.X(0.3);              This does give a compiler error
	cout << cp.X() << endl;

	return 0;
}

// READY FOR SUBMISSION