/*
Inline functions can speed up the execution of short functions because the code of such function will be copied in place instead of calling that function. 
Make the setters and getters of the Point class inline functions. Use normal inline (outside the class declaration) 
for the getters and default inline (inside the class declaration) for the setters. 
Note that the implementation of the normal inline functions must be in the header file; else they will not be inlined.

*/


#include "Point.h"
#include "Circle.h"
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	
	double x, y, r;

	cout << " Enter X coordinate for the Center Point of the Circle" << endl;
	cin >> x;

	cout << "Enter Y coordinate for the Center Point of the Circle" << endl;
	cin >> y;

	Point p1(x, y); // Intialize Point 1 using the custom constructor

	cout << " The description of the point is:" << p1.ToString() << endl;
	cout << std::fixed << setprecision(2) << " X coordinate of point is: " << p1.X() << endl;
	cout << std::fixed << setprecision(2) << " Y coordinate of point is: " << p1.Y() << endl;


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