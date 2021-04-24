/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this file is to define the Function Object header file
* Implement the class to pass is to the count_if function as functor
* This is to replace the global function used earlier for comparison
*/

#ifndef FunctionObject_H
#define FunctionObject_H

template<typename T>
class FunctionObject
{
private:
	/*Value of Type T
	*/
	T value;

public:

	/*Default Constructor
	*/
	FunctionObject();
	/*Custom constructor with value
	*/
	FunctionObject(const T& v);
	/*Copy Constructor
	*/
	FunctionObject(const FunctionObject<T>& ft);
	/*Destructor
	*/ 
	virtual ~FunctionObject();

	/*Operator Overloading
	* Assignment Operator
	*/ 
	FunctionObject<T>& operator = (const FunctionObject<T>& ft);

	/*Overload the () operator 
	* same signature as global function
	*/
	bool operator()(const T& v) const;

};

#endif // 


