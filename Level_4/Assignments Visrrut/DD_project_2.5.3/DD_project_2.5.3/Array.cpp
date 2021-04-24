/*Author: Vishrut Talekar; Nov 2020
*/

/*The Purpose of this file is to implement the Array class defined in Array Header file
*/

#include "Array.h"
#include "Point.h"
#include<iostream>
#include<sstream>
#include<iomanip>

using namespace std;

	/*Default Constructor for Array with size 10
	* Colon syntax is used
	* Please note I could use new Point[m_size];
	* however that initiates the x and y coordinates to 
	* garbage values and not '0'
	*/
	Array:: Array(): m_data(new Point[10]), m_size(10) 
	{
		cout << "Default constructor for Array is called\n";
	}

	/*Custom constructor with intialization parameters
	* Colon Syntax is used
	*/
	Array::Array(const int& size) : m_data(new Point[size]), m_size(size)
	{
		cout << "Intialize Array using custom constructor\n";
	}

	/*Copy constructor added
	*/
	Array::Array(const Array& source_arr)
	{
		m_size = source_arr.m_size;
		/*Allocate C array with same size 
		*/
		m_data = new Point[source_arr.m_size]; 

		/*Copy each element separately
		*/
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = source_arr.m_data[i];
		}

		cout << "Copy constructor of Array is called\n";
	}

	/*Destructor*/
	Array::~Array() 
	{
		delete[] m_data;	
		cout << "Destructor of Array is called\n";
	}

	/* Operator Overloading
	*/
	/*Assignment operator
	*/
	Array& Array::operator = (const Array& source)
	{
		// Avoid doing assign to myself
		if (this == &source)
		{ 
			return *this;
		}
		else
		{
			/*Delete old C array before allocation, as C arrays cannot grow
			*/
			delete[] m_data;				   

			m_size = source.m_size;
			/*Allocate C array with same size 
			*/
			m_data = new Point[source.m_size]; 

			/*Copy each element separately
			*/
			for (int i = 0; i < m_size; i++)
			{
				m_data[i] = source.m_data[i];

			}
			return *this;
		}
	}
	
	/*Get elements of Array using square bracket operator
	*/
	Point& Array::operator [](int index)
	{
		/*argument:
		*	1. index of type double: Index of the Array object
		*returns: Point object as reference
		*/
		/*Condition for out of bounds index
		* Error handling will be added later
		*/
		if (index < m_size && index >= 0)
		{	
			return m_data[index];
			
		}
		else
		{
			return m_data[0];
		}
	}

	/*Const version of square bracket Operator
	*/
	const Point& Array::operator [](int index) const
	{
		/*argument:
		*	1. index of type double: Index of the Array object
		*returns: Point object as const reference
		*/
		/*Condition for out of bounds index
		* Error handling will be added later
		*/
		cout << "Const version is used" << endl;
		if (index < m_size && index >= 0)
		{
			return m_data[index];
			
		}
		else
		{
			cout << "Index is out of bounds returning '0'th element\n";
			return m_data[0];
		}
	}

	/*Get elements of Array
	*/
	const Point& Array::GetElement(int index) const
	{
		/*argument:
		*	1. index of type double: Index of the Array object
		*returns: Point object as const reference 
		*/
		/*Condition for out of bounds index
		* Error handling will be added later
		*/
		
		if (index < m_size && index >= 0)
		{
			return m_data[index];
			
		}
		else
		{
			cout << "Index is out of bounds for get elements\n";
			return m_data[0];
		}
	}

	/*Set elements of Array
	*/
	void Array::SetElement(int index, const Point& p)
	{
		/* argument:
		*	1. index of type double: Index of the Array object 
		*	2. Point object as const reference
		*returns: void
		*/
		
		if (index < m_size&& index>=0)
		{
			m_data[index] = p;
		}
		else
		{
			cout << "Index is out of bounds for set elements\n";
		}
			
	}
	/*Get Size of the Array
	*/
	int Array::Size() const
	{
		/*argument:None
		*returns: Size of the array of type double
		*/
		return m_size;
	}