/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to Test the boost variant and create visitor class
* Also create overload operator () to change the coordinates of the shape
*/

#include "PointArray.h"
#include "Stack.h"
#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include "boost/variant.hpp"
#include "Point.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Visitor.h"


using namespace std;
using namespace VISHRUTTALEKAR;

using CAD::Point;
using CAD::Line;
using CAD::Circle;
using CAD::Shape;
using Containers::Array;
using CAD::Visitor;


/*Define the shape type function which return a variant
*/
boost::variant<Point, Line, Circle> getShapeType()
{
	boost::variant<Point, Line, Circle> shape_type;
	
	int shapeType;
	/*Get user input for the shape
	*/
	cout << "Please enter a shape Point-> 1, Line-> 2, Circle-> 3\n";
	cin >> shapeType;
	
	switch (shapeType)
	{
	case(1):
		shape_type = Point(); break;
	case(2):
		shape_type = Line(); break;
	case(3):
		shape_type = Circle(); break;

	}
		
	return shape_type;

}
int main()
{
	/*Declare a Typedef
	*/
	typedef boost::variant<Point, Line, Circle> ShapeType;

	ShapeType shape_type_1 = getShapeType();

	/*Print the Shape 
	*/
	cout << "The Shape is: " << shape_type_1 << endl;

	/* Assign variant Line variable by using the global boost:get<T>() function.
	* 
	*/
	Line l;

	try
	{
		l = boost::get<Line>(shape_type_1);
	}
	catch(boost::bad_get& v_err)
	{
		cout << "The Error is: " << v_err.what() << endl;
	}

	boost::apply_visitor(Visitor(3, 6), shape_type_1);

	cout << "The result after moving the shape is: " << shape_type_1 << endl;

	return 0;
}
 
/*References
* https://quantnet.com/threads/question-about-operator.44277/
* https://quantnet.com/threads/purposes-of-using-the-visitors.40138/
* https://quantnet.com/threads/visitor-class.39954/
* https://quantnet.com/threads/confirming-my-understanding-of-the-static_visitor-function.39197/
* https://quantnet.com/threads/changing-the-object-stored-by-boost-variant-t.39233/
* https://quantnet.com/threads/error-c2664.18862/#post-179506
* https://quantnet.com/threads/create-an-instance-of-the-visitor.40324/
* https://quantnet.com/threads/understanding-of-this-exercise.26157/
* https://quantnet.com/threads/changing-the-object-stored-by-boost-variant-t.39233/
*/