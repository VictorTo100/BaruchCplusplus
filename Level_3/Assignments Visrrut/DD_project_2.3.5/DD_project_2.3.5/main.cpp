#include "Point.h"
#include "Line.h"
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{

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
	cout << " Enter x coordinate for the point 2\n" << endl;
	cin >> x1;

	cout << " Enter y coordinate for the point 2\n" << endl;
	cin >> y1;

	Point p2(x1, y1); // Intialize Point 2 using the custom constructor


	/* Test if Point Copy Constructor works*/
	Point p3(6,8);
	Point p4(p3);
	if (p3.X() == p4.X() && p3.Y() == p4.Y()) {
		std::cout << "Point Copy Constructor works\n";
	}

	cout << "Initialize the Line\n" << endl;
	Line l1(p1, p2);
	cout << " The description of the Line is:" << l1.ToString() << "\n" << endl;

	cout << std::fixed << setprecision(2) << " The distance between 2 point is: " << p1.Distance(p2)  << "\n" << endl;
	cout << std::fixed << setprecision(2) << " The length between 2 point is: " <<  l1.Length() << "\n" << endl;

	cout << std::fixed << setprecision(2) << " Starting point of the line is: " << l1.start().ToString() << "\n" << endl;
	cout << std::fixed << setprecision(2) << " Ending point of the line is: " << l1.end().ToString() << "\n" << endl;

	return 0;
}

// READY FOR SUBMISSION