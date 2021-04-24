/*Author: Vishrut Talekar; Nov 2020
*/
/*The Purpose of the file is to define 
* template function Sum()
*argument: Template T 
* return: double
*/

#ifndef SumContainers_H
#define SumContainers_H

#include<map>
#include<vector>
#include<list>
#include<iostream>

using namespace std;

/*Implement of template function Sum()
* for iterators
*/
template <typename T>
double Sum(const T& t)
{ /*argument: Template type T
    return: type double
  */
	typename T::const_iterator i;
	/*Declare variable to store sum
	*/
	double sum = 0.0;
	/*Iterate over the container
	*/
	for (i = t.begin(); i != t.end(); i++)
	{
		sum += *i; // Use the dereference 
	}

	return sum;
}

/*Implement of template function Sum()
* for maps
*/
template <typename T1, typename T2>
double Sum(const map<T1, T2>& m)
{ /*argument: Template type T, map container
    return: type double
  */
	typename map<T1, T2>::const_iterator i;
	/*Declare variable to store sum
	*/
	double sum = 0.0;
	/*Iterate over the container
	*/
	for (i = m.begin(); i != m.end(); i++)
	{
		sum += i->second; // Use the dereference 
	}

	return sum;
}


/*Definition for sum between iterators  for container(except for map)
*/

template <typename T>
double Sum(const typename T::const_iterator& start_iter, const typename T::const_iterator& end_iter)
{ 
	/*argument: iterator reference for start and end of container of type T
	* return: double
	*/
	typename T::const_iterator i;

	double sum = 0.0;

	for (i = start_iter; i != end_iter; i++)
	{
		sum += *i; // Use the dereference 
	}

	return sum;
}


/*Definition for sum between iterators for a map
*/
template <typename T1, typename T2>
double Sum(const typename map<T1, T2>::const_iterator& start_iter, const typename map<T1, T2>::const_iterator& end_iter)
{ 
	/*argument: iterator reference for start and end of container of type T
	* return: double
	*/
	typename map<T1, T2>::const_iterator i;

	double sum = 0.0;

	for (i = start_iter; i != end_iter; i++)
	{
		sum += i->second; // Use the dereference 
	}

	return sum;
}

/* Reference
https://quantnet.com/threads/function-overloading.39475/#post-248957
https://quantnet.com/threads/create-a-sum-function-that-calculates-the-sum-between-two-iterators.33426/
https://quantnet.com/threads/exercise-2-template-specialization.21581/
https://quantnet.com/threads/issues-in-sum-header-file.23761/#post-171189
https://quantnet.com/threads/exercise2-sum-iter-iter-functor-for-list-and-vector.39067/
*/
#endif //

