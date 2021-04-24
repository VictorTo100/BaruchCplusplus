/*Author: Vishrut Talekar; Nov 2020
*/

/* Following is implemented and tested in excercise 7.1
* Create a list of doubles and add some data. Use the front() and back() functions to access the first and last element.
* Create a vector of doubles and add some data.
* Then use the index operator to access some elements. Also make the vector grow.
* Create a map that maps strings to doubles.
*  Fill the map and access elements using the square bracket operator.
*/

#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main()
{

	/*Create a list of doubles, add some data and use front and back functions to access the data
	*/
	std::list<double> lst1;

	for (int i = 0; i < 5; i++)
	{
		lst1.push_back(i*2.5);
	}
	/*Access the elements of the list using front and back member functions
	*/
	cout << "The first element of the list is: " << lst1.front() << endl;
	cout << "The last element of the list is: " << lst1.back() << endl;

	/*Create a map that map strings to doubles
	*/
	std::map<std::string, double> map1;

	map1["0"] = 1.5;
	map1["1"] = 2.5;

	/*Access the elements of the map by using square brackets
	*/
	cout << "The fist element of the map is: " << map1["0"] << endl;
	cout << "The second element of the map is: " << map1["1"] << endl;



	/*https://quantnet.com/threads/map-syntax.29427/ also trying the iterator following comments in this post
	*/
	std::map<std::string, double>::iterator it;

	for (it = map1.begin(); it != map1.end(); it++)
	{
		cout << "The Elements of map are: " <<  it -> first << ":" << it -> second << endl;
	}
	
	/*Create Vector of doubles add some data; use index operators to access elements; make the vector grow
	*https://quantnet.com/threads/question-for-make-the-vector-grow.32702/ 
	*/
	
	vector<double> vec1;

	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i *2.5);
	}

	/*Check the capacity of the vector
	*/
	cout << "The capacity if the vec1 is: " << vec1.capacity() << endl;

	/*Grow the vector
	*/
	for (int i = 5; i < 10; i++)
	{
		vec1.push_back(i*2.5);
	}

	/*Check the capacity
	*/
	cout << "The capacity if the vec1 is: " << vec1.capacity() << endl;

	return 0;
}