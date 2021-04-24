/*Author: Vishrut Talekar; Nov 2020
*/
/*This file defines the Array Class. The Array class contains the following;
* Private data Members:
* 1. m_data - Dynamic C array of Template Type
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
* NOTE
* *************** Added in 4.2a.1 *************************************
* Make Array Class generic where it is able to store any type and not 
* only Point Objects
*/



#ifndef Array_H
#define Array_H

#include"Point.h"
using namespace std;


namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		template <typename T> 
		class Array
		{

		private:

			T* m_data;
			int m_size;
			
		public:

			/*Default Constructor
			*/
			Array();	
			/*Constructor with Size parameter
			*/
			Array(int size);			
			/*Destructor
			*/
			~Array();					
			/*Copy Constructor
			*/
			Array(const Array<T>& arr); 	

			/* Declare Getters and Setters
			*/
			/*Set the point for particular index of the array
			*/
			void SetElement(int index, const T& p); 
			T& GetElement(int index)const;          

			/*Member function decalration
			*/
			/*Function to return the size of the Array
			*/
			int Size() const;

			/*Operator Overloading
			*/

			/*Assignment Operator
			*/
			Array<T>& operator =  (const Array<T>& arr);

			/*Square bracket operator
			*/
			T& operator [] (int index);

			/*Const version of the Square bracket operator
			*/
			const T& operator [] (int index) const;

		};

	}
}
#ifndef Array_cpp // Must be the same name as in source file
#include "Array.cpp"
#endif

#endif