/*Author: Vishrut Talekar; Nov 2020
*/
/*This file defines the Array Class. The Array class contains the following;
* Private data Members:
* 1. m_data - Dynamic C array of Point objects
* 2. m_size - Size of the array
*
* Default Constructor: Constructor that allocates 10 elements
* Parameter Constructor: Constrcutor with Size arguments
* Copy Constructor, Destructor,
* Member functions:
* Size, SetElements, GetElements
* Operator Overloading:
* Assignment Operator,  Square bracket[] operator,
* Const version of the square bracket operator
*
*/

#ifndef Array_H
#define Array_H

#include"Point.h"
using namespace std;


namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		class Array
		{

		private:
			/*data member for dynamic C array of point objects
			*/
			CAD::Point* m_data;

			/*Data member for size array
			*/
			int m_size;

		public:

			/*Default Constructor
			*/
			Array();
			/*Constructor with Size parameter
			*/
			Array(const int& size);

			/*Destructor
			*/
			~Array();
			/*Copy Constructor
			*/
			Array(const Array& source_arr);
			/* Declare Getters and Setters
			*/
			/*Set the point for particular index of the array
			*/
			void SetElement(int index, const CAD::Point& p);
			const CAD::Point& GetElement(int index)const;

			/*Member function decalration
			*/
			/*Function to return the size of the Array
			*/
			int Size() const;

			/*Operator Overloading
			*/

			/*Assignment Operator
			*/
			Array& operator =  (const Array& arr);

			/*Square bracket operator
			*/
			CAD::Point& operator [] (int index);

			/*Const version of the Square bracket operator
			*/
			const CAD::Point& operator [] (int index) const;
		};


	}
}

#endif



