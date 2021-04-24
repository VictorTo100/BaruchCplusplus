/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to Test the functionality of Shared Pointers
*/

#include "PointArray.h"
#include "Stack.h"
#include<iostream>
#include<sstream>
#include <vector>
#include "boost/shared_ptr.hpp"
#include "Point.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"


using namespace std;
using namespace VISHRUTTALEKAR;
 

int main()
{

	using CAD::Point;
	using CAD::Line;
	using CAD::Circle;
	using CAD::Shape;
	using Containers::Array;

	typedef boost::shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;

	ShapeArray shapeArr(6);

	/*Memory created on Heap when new is used
	* Shared pointers help to deleted the memory
	*/
	shapeArr[0] = ShapePtr(new Point);
	shapeArr[1] = ShapePtr(new Line);
	shapeArr[2] = ShapePtr(new Circle);
	shapeArr[3] = ShapePtr(new Point(2,4));
	shapeArr[4] = ShapePtr(new Line(Point(3,6), Point(2,4)));
	shapeArr[5] = ShapePtr(new Circle(Point(2,2), 3));

	/*Note:
	* Yes, Shapes are automatically deleted
	* Destructors are called
	*/

	return 0;
}

// READY FOR SUBMISSION