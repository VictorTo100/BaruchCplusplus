/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the Array class defined in Array Header file
*
*/

#ifndef Stack_CPP
#define Stack_CPP

#include "Array.h"
#include"Stack.h"
#include<iostream>
#include<sstream>
#include<iomanip>

using namespace std;

namespace VISHRUTTALEKAR
{
	/*Reference
	* 
	*/
	
	namespace Containers
	{
		/*Default Constructor
		*/
		template <typename T>
		Stack<T>::Stack(): m_current(0)
		{
			cout << "Default constructor for Stack is called" << endl;
		}

		/*Custom constructor with intialization parameters
		*/
		template <typename T>
		Stack<T>::Stack(int size) : m_current(0), m_arr(size)
		{
			cout << "Intialize Stack using custom constructor\n" << endl;
		}

		/*Copy constructor added
		*/
		template <typename T>
		Stack<T>::Stack(const Stack<T>& arr): m_current(arr.m_current), m_arr(arr.m_arr)
		{
			cout << "Copy constructor of Stack is called\n" << endl;
		}

		/*Destructor
		*/
		template <typename T>
		Stack<T>::~Stack() 
		{
			cout << "Template Array Destructor is called" << endl;
		}

		/*Operator Overloading
		* Assignment operator
		*/
		template <typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& source)
		{
			/*Preclude from assigning it to itself
			*/
			if (this == &source)
			{
				return *this;
			}
			else
			{
				m_current = source.m_current;
				m_arr = source.m_arr; // Allocate C array with same size 
				return *this;
			}
		}
		 
		/*
		function that decrements the current position and then returns the element at that position. 
		Make sure the current index is not changed whenthe Array class throws an exception
		*/
		template <typename T>
		T Stack<T>::Pop()
		{
			/*Check the condition for not changing the index of exception thrown
			If m_current == 0 and below the condition is satisfied and exception will be thrown
			*/
			if (m_current == 0)
			{
				return m_arr[m_current -1];
			}
			else
			{
				/*decrements the current position and then returns the element at that position
				*/
				m_current = m_current--;
				return m_arr[m_current];
			}
		}

		template <typename T>
		void Stack<T>::Push(const T& value)
		{
			m_arr[m_current] = value;
			m_current++;
		}

	}
}

#endif

/*References
* https://quantnet.com/threads/4-2b-4-regular-constructors.37408/#post-272566
* https://quantnet.com/threads/exercise-4-push-and-pop-function.44743/
* https://quantnet.com/threads/pop-return-type-const-or-non-const.44484/
* https://quantnet.com/threads/4-2b-4-how-to-aviod-changing-m_current-when-push-and-pop-fails.42296/
*/