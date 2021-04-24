/*Author: Vishrut Talekar; Nov 2020
*/

/* The Purpose of this class is to define the PointArray
*template class derived from the Array class using concrete inheritance.
* Where template type is fixed to a certain type
* Contains:
* Default Constructor, Destructor, Copy Constructor
* Operator Overloading:
* Assignment Operator
* Member function: Length()
*/

#ifndef PointArray_H
#define PointArray_H

#include "Point.h"
#include "Array.h"
#include "Array.cpp"

using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{

		class PointArray :public Array<CAD::Point>
		{

		public:

			/*Default Constructor
			*/
			PointArray();
			/*Parameter Constructor with size parameter of type int
			*/
			PointArray(int size);
			/*Copy Constructor
			*/
			PointArray(const PointArray& ptarr);

			virtual ~PointArray();

			/*Assignment operator
			*/
			PointArray& operator = (const PointArray& ptarr);

			/*Member function length
			* to return the sum of the length between the contibuous points
			*/
			double Length() const;

		};


	}

}

#endif //


