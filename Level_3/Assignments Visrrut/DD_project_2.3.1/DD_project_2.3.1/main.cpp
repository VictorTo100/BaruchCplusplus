/*
Requirements
In this exercise we are going to add extra constructors. But first we do a little experiment. In the Point class constructor and destructor, 
add some code that displays some text. In the main program, make sure you use the Distance() function to calculate the distance between two points.
Run the program and count how many times the constructor and destructor are called. Are they the same? 
Now add a copy constructor to the Point class that also displays some text. Also add a constructor 
that accepts x- and y-coordinates so you can create a point with the right values without using the set functions. 
Use this constructor to create the point from the user input. Run the program again and count the number of times the constructors and destructor are called. 
Is the copy constructor called and is the number of constructor calls now the same as the number of destructor calls? We can derive two things from these results:
1. When calling the Distance() function, the input point is copied (call by value).
2. You will get the copy constructor 'for free' when you do not create one yourself.

*/


#include "Point.h"
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	//Point p1, p2; // Initialize 2 points

	double x, y, x1, y1; //, distOrigin, distBetween;

	cout << " Enter x coordinate for the point 1" << endl;
	cin >> x;

	cout << " Enter y coordinate for the point 1" << endl;
	cin >> y;

	Point p1(x, y); // Intialize Point 1

	cout << " The description of the point is:" << p1.ToString() << endl;
	cout << std::fixed << setprecision(2) << " X coordinate of point is: " << p1.GetX() << endl;
	cout << std::fixed << setprecision(2) << " Y coordinate of point is: " << p1.GetY() << endl;

	/* Test the DistanceOrigin function */

	cout << std::fixed << setprecision(2) << " The distance from origin is: " << p1.DistanceOrigin() << endl;

	/* Test the Distance function*/
	cout << " Enter x coordinate for the point 2" << endl;
	cin >> x1;

	cout << " Enter y coordinate for the point 2" << endl;
	cin >> y1;

	Point p2(x1, y1); // Intialize Point 2

	cout << std::fixed << setprecision(2) << " The distance between 2 point is: " << p1.Distance(p2) << endl;

	return 0;
}

// READY FOR SUBMISION