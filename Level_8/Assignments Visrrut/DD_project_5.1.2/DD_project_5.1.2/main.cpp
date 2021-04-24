/*Author: Vishrut Talekar; Nov 2020
* 
*/

/*The Purpose of this is to use the functionalities of Tuple
* create a typedef for a Person tuple that contains a name, age and length
*create a typedef for a Person tuple that contains a name, age and length.
* Create a few person tuple instances and print them
* increment the age of one of the persons
*/

#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"
#include <string>
#include <iostream>
using namespace std;

/*Definition of the function PrinPersonTuple
* To print the description of the function person tuple
*/
void PrintPersonTuple(const boost::tuple<string, int, double>& person)
{
	cout << "The name of the Person is: " << person.get<0>()
		<< " ; age is: " << person.get<1>() << " and length is: "
		<< person.get<2>() << "\n" << endl;
}

int main()
{
	
	/*Declaration
	*/
	using boost::tuple;

	/*Creating tuples; create Person tuple using typedef
	*/
	typedef tuple < string, int, double > Person;

	/*Create person Tuple instances
	*/
	Person p1 = boost::make_tuple(string("Tony"), 35, 42.5);
	Person p2 = boost::make_tuple(string("Thor"), 37, 45);
	Person p3 = boost::make_tuple(string("Banner"), 41, 40);
	Person p4 = boost::make_tuple(string("BlackWidow"), 30, 38);

	/*Use the get<T>() member functions the retrieve the data
	*/
	cout << "The name of the Person p1 is: " << p1.get<0>() << " ; age is: " << p1.get<1>() << " and length is: " << p1.get<2>() << "\n" << endl;
	cout << "The name of the Person p2 is: " << p2.get<0>() << " ; age is: " << p2.get<1>() << " and length is: " << p2.get<2>() << "\n" << endl;
	cout << "The name of the Person p3 is: " << p3.get<0>() << " ; age is: " << p3.get<1>() << " and length is: " << p3.get<2>() << "\n" << endl;
	cout << "The name of the Person p4 is: " << p4.get<0>() << " ; age is: " << p1.get<1>() << " and length is: " << p4.get<2>() << "\n" << endl;

	/*Increment the age of one of the persons
	*/
	p2.get<1>() += 5;

	/*Test print function
	*/
	PrintPersonTuple(p2);
	return 0;
}


// READY FOR SUBMISSION

