#ifndef Stack_CPP
#define Stack_CPP

#include "Array.h"
#include"Stack.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include "StackException.h"
#include"StackEmptyException.h"
#include"StackFullException.h"
#include"ArrayException.h"

using namespace std;

namespace VISHRUTTALEKAR
{
	namespace Containers
	{
		/*Default Constructor
		*/
		template <typename T, int size>
		Stack<T, size>::Stack() : m_current(0), m_arr(Array<T>(size))
		{
			cout << "Default constructor for Stack is called" << endl;
		}

		/*Copy constructor
		*/
		template <typename T, int size>
		Stack<T, size>::Stack(const Stack<T, size>& source_arr) : m_current(source_arr.m_current), m_arr(source_arr.m_arr)
		{
			cout << "Copy constructor of Stack is called\n" << endl;
		}
		/*Destructor
		*/
		template <typename T, int size>
		Stack<T, size>::~Stack() // Destructor
		{
			cout << "Template Array Destructor is called" << endl;
		}

		/* Operator Overloading
		*Assingment operator
		*/
		template <typename T, int size>
		Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source_arr)
		{
			/*Preclude from assigning it to itself
			*/
			if (this == &source_arr)
			{
				return *this;
			}
			else
			{
				m_current = source_arr.m_current;
				m_arr = source_arr.m_arr; // Allocate C array with same size 
				return *this;
			}
		}

		/*
		function that decrements the current position and then returns the element at that position.
		Make sure the current index is not changed when the Array class throws an exception
		*/
		template <typename T, int size>
		T Stack<T, size>::Pop()
		{
			//If m_current == 0  is satisfied and exception will be thrown
			try
			{
				m_current = m_current--;
				return m_arr[m_current];
			}
			catch (ArrayException& err)
			{
				/*decrements the current position and then returns the element at that position
				*/
				m_current = 0;
				throw StackEmptyException();

			}

		}

		template <typename T, int size>
		void Stack<T, size>::Push(const T& value)
		{
			try
			{
				m_arr[m_current] = value;
			}
			catch (ArrayException& err)
			{
				throw StackFullException();
			}
			m_current++;

		}

	}
}

#endif

// https://quantnet.com/threads/exercise-4-push-and-pop-function.44743/
// https://quantnet.com/threads/pop-return-type-const-or-non-const.44484/
// https://quantnet.com/threads/4-2b-4-how-to-aviod-changing-m_current-when-push-and-pop-fails.42296/
// 