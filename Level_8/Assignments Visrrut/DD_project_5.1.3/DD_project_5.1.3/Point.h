/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this header file is to define the Point class
* The Point Class:
* The purpose of the class is define a point in a two dimensional space
* Has two private data member to represent the X and Y coordinates of the Point
* Has Default constructor and the destructor
* Getter and Setters for X and Y coordinates
* Member function:
* ToString: To return a string description of the point

********** Already tested in 2.2.2 **********************
* DistanceOrigin:calculates the Euclidean distance of point from the origin
* Distance: Calculates the distance between two points
*
* ******** Already added in 2.3.1 ****************
* 1. Add Copy Constructor and Paramter Constructor
* 2. Test the application and role of Copy Constructor
* 3. The the Constructor with parameters
*
* ************* Already added in 2.3.2 **************
* Pass the point object as reference to the Distance function
* to avoid the call to copy constructor, const is added to make
* state of the passed object is not changed
*
* ************** Already added in 2.3.3 **************
* Function overloading for geters, setter and Distance function
*
* ************** added in 2.3.4 **************
* Make geters, setter, Distance, ToString function const
* NOTE: I had already made most of the const in previous versions
* Added const to Distance function in this version
*
* ************** Added in 2.3.4 ***********************
* Inline Getter and setters
*
* ************* Added in 2.4.1 ************************
* Added operator overloading for addition, scaling, assignment, scale and assign,
* negation and comparator operator
*
* ************* Added in 2.4.2 ************************
* The implementation uses the << operator to send data to the os input argument
*
* ************* Added in 2.4.3 ************************
* Make the Point constructor with same x and y coordinate as explicit
*
* ************* Added in 2.4.4 ************************
* make the ostream << operator friend function
*
* ************* Added in 2.6.1 ************************
* Putting Point class in the in VISHRUTTALEKAR::CAD

*/

#ifndef Point_H
#define Point_H

#include<iostream>
#include"Shape.h"
using namespace std;


namespace VISHRUTTALEKAR
{
	namespace CAD
	{
		class Point : public Shape
		{

			/*Declare the data members of Point
			*/
			/* X coordinate of type double
			*/
			double m_x;
			/* Y coordinate of type double
			*/
			double m_y;

		public:
			/* Default constructor
			*/
			Point();
			/*Destructor
			*/
			~Point();
			/*Constructor with parameters
			*/
			Point(const double& m_x, const double& m_y);

			/*Constructor with same parameter for x and y coordinates
			*/
			explicit Point(const double& value);

			/*Copy constructor
			*/
			Point(const Point& p);

			/* Declare Getters and Setters
			*/

			/*Function to get coordinate
			* declared as const to make the state of the object is not changed
			*/

			double X() const;
			/*Set the value of X coordinate
			* Default inline function
			*/
			void X(const double& newX) { m_x = newX; }

			double Y() const;
			/*Set the value of X coordinate
			* Default inline function
			*/
			void Y(const double& newY) { m_y = newY; }

			/*Member functions
			*/

			/*ToString: to describe the Point object
			*/
			std::string ToString() const;

			/*Distance function to calculate Euclidean distance from origin
			*/
			double Distance() const;

			/*Distance function to calculate Euclidean distance between two points
			* Pass the point as 'const reference'
			*/
			double Distance(const Point& p) const;

			/* Operator Overlaoding
			*/

			/*Negate the coordinates of Point object
			*/
			Point  operator - () const;

			/*Assignment Operator
			*/
			Point& operator =  (const Point& p);

			/*Scale the coordinates by a factor of Point object
			*/
			Point operator * (const double& factor) const;

			/*Add coordinates of Point object
			*/
			Point operator + (const Point& p) const;

			/*Equally compare operator
			*/
			bool operator == (const Point& p) const;

			/*Scale the coordinates of Point object & assign
			*/
			Point& operator *= (const double& factor);

			/*The implementation uses the << operator to send data to the os input argument
			* Declared as friend in this excercise
			* std::ostream class had to be a global function and thus can’t access the private members
			*/
			friend ostream& operator << (ostream& os, const Point& p);

			/* To be overriden from the abstract base class Shape
			*/
			void Draw() const;

		};
		/*Normal Inline functions for Getters of X and Y coordinate
		*/
		inline double Point::X() const { return m_x; }
		inline double Point::Y() const { return m_y; }
	}
}
#endif

