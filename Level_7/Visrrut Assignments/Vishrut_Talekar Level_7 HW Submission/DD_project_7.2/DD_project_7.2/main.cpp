/*Author: Vishrut Talekar; Nov 2020
*/

/*Test the sum function created in SumContainers header file 
*/



#include<map>
#include<vector>
#include<list>
#include<iostream>
#include "SumContainers.h"

using namespace std;

int main()
{
	/*Test the sum for the list
	* Example list from the DD's sample code
	*/

	list<double> lst1;
	int a[10] = { 12, 3, 25, 7, 11, 213, 7, 123, 29, -31 }; // example list from the DD's sample code

	for (int i = 0; i < 10; i++)
	{
		lst1.push_back(a[i]);
	}

	cout <<" Output for the sum of list\n" << Sum(lst1) << "\n";

	/*Define iterators i and j
	* for sum between iterators
	*/
	list<double>::const_iterator i;
	list<double>::const_iterator j;
	i = ++lst1.begin();
	j = --lst1.end();
	
	/*Print the sum
	*/
	cout << " Output for the sum between iterators\n" << Sum<list<double>>(++i, --j) << "\n" << endl;

	vector<double> vector1(10);

	for (int i = 0; i < 10; i++)
	{
		vector1[i] = a[i];
	}

	/*Define Vector iterators
	*/
	vector<double>::const_iterator k;
	vector<double>::const_iterator l;
	k = vector1.begin();
	l = vector1.begin();

	/*Test with Random access iterator
	*/
	cout << Sum<vector<double>>((k), (l += 4)) << "\n" << endl; 
	/*Print the sum
	*/
	cout << " Output for the sum of vector\n" << Sum(vector1) << "\n" << endl;

	/*Testing for maps
	*/
	/*Declare and assign values to map container
	*/
	map<int, double> map1;

	map1[0] = 2.5;
	map1[1] = 3.5;
	map1[2] = 4.5;
	map1[3] = 5.5;

	/*Print the sum
	*/
	cout << " Output for the sum of map\n" << Sum(map1) << "\n" << endl;

	map<int, double>::const_iterator m;
	map<int, double>::const_iterator n;
	m = map1.begin();
	n = ++map1.begin();

	/*Print the sum
	*/
	cout << " Output for the sum of map between iterator\n" <<Sum<int, double>(m, ++n) << "\n" << endl;


	
	return 0;
}

/*References
* https://quantnet.com/threads/function-overloading.39475/#post-248957
* https://quantnet.com/threads/create-a-sum-function-that-calculates-the-sum-between-two-iterators.33426/

*/

//READY FOR SUBMISSION