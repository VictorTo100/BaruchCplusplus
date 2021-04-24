/*Author: Vishrut Talekar; Nov 2020
*/
/*This file defines the Stack Template Class. This class contains the following;
* It uses the Array data members
* Private data Members:
* 1. m_arr - Array of type T
* 2. m_current -  current index of the array
*
* Default Constructor:
* Parameter Constructor: Constrcutor with Size arguments
* Copy Constructor, Destructor,
* Member functions:
* Pop() and Push()
* Operator Overloading:
* Assignment Operator
*
* ************* Added in 4.2b.6 **************************
* Pass the size as parameter from the Template
*
*/

#ifndef Stack_H
#define Stack_H

#include "Array.h"
using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		/*Define the canonical header file*/
		template<typename T, int size>
		class Stack
		{
		private:

			/*current index
			*/
			int m_current;
			/*Array of type T
			*/
			Array<T> m_arr;

		public:

			/* Default Constructor*/
			Stack();
			/*Destructor
			*/
			~Stack();
			/*Copy Constructor
			*/
			Stack(const Stack<T, size>& stk);

			/*Operator Overloading
			* Assignment Operator
			*/
			Stack<T, size>& operator=(const Stack<T, size>& arr);

			/*Member functions
			*/
			/* function that decrements the current position
			* and then returns the element at that position.
			* Make sure the current index is not changed whenthe Array class throws an exception.
			*/
			T Pop();
			/*It should store the element at the current position in the embedded array.
			* Increment the current position afterwards.
			*/
			void Push(const T& value);

		};

	}
}
#ifndef Stack_cpp // Must be the same name as in source file #define
#include "Stack.cpp"
#endif

#endif 
