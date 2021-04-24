/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this file is to define the Function Object header file
* Implement the class to pass is to the count_if function as functor
* This is to replace the global function used earlier for comparison
*/


#ifndef FunctionObject_CPP
#define FunctionObject_CPP

#include "FunctionObject.h"
#include<iostream>
using namespace std;


/*Default Constructor
*/
template<typename T>
FunctionObject<T>::FunctionObject()
{
	std::cout << "Default Constructor of FunctionObject is called\n" << endl;
}

/*Custom Constructor with value of type T for comparison
*/
template<typename T>
FunctionObject<T>::FunctionObject(const T& t):value(t)
{
	std::cout << "Custom Constructor of FunctionObject is called\n" << endl;
}
/*Copy Constructor
*/
template<typename T>
FunctionObject<T>::FunctionObject(const FunctionObject<T>& ft) : value(ft.value)
{
	std::cout << "Copy Constructor of FunctionObject is called\n" << endl;
}

/*Destructor
*/
template<typename T>
FunctionObject<T>::~FunctionObject()
{
	std::cout << "Destructor of FunctionObject is called\n" << endl;
}

/*Assignment Operator
*/
template<typename T>
FunctionObject<T>& FunctionObject<T>::operator =(const FunctionObject<T>& ft)
{
	if(this == &ft)
	{
		return *this;
	}
	else
	{
		value = ft.value;
		return *this;
	}
}

/*Overloaded () operator
*/

/*This is a class that overload the round bracket operator that in this case has the same signature
* and functionality as the global function you created previously
*/
template<typename T>
bool FunctionObject<T>::operator() (const T& t) const
{
	return t < value;
}

#endif