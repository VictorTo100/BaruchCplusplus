/*
In the previous exercise, you saw that the point passed to the Distance() method was copied. Since creating a copy is unnecessary in this case, 
change this function so that it passes the input point “by reference” so that no copy is made. Pass it as “const reference” to make it impossible to
change the input point from within the Distance() function. Run the program again. It should call the copy constructor fewer times than before. 
Also test if you can change the input point in the Distance() function. This should result in a compiler error.
*/


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

	Point p2(x1, y1); // Intialize Point 2 using the custom constructor

	cout << std::fixed << setprecision(2) << " The distance between 2 point is: " << p1.Distance(p2) << endl;

	return 0;
}

// READY FOR SUBMISION

