/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this file is to test the count_if with different functors
* 1. Global fucntion 
* 2. Function object
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include "FunctionObject.cpp"

using namespace std;


/*Part 1: Global function that checks the double input is smaller than a certain value.
* Hard coded value for comparison
*/

bool SmallerThan(double input)
{
	/*argument: value of type double
	* return: bool
	*/
	/*const value 
	*/
	const double value = 5.0;
	/*return boolean
	*/
	return value < input;
}


int main()
{
	/* Declare vector with size
	*/
	vector<double> myVec(10);

	for (int i = 0; i < 10; i++)
	{
		myVec[i] = (i+2) * 0.5;
	}

	/*Test the count_if with global function
	*/
	int output = 0;
	output = count_if(myVec.begin(), myVec.end(), SmallerThan);

	std::cout << output << "\n" << endl;

	/*Value for comparison
	*/
	double value = 0;
	std::cout << "Enter the value to be compared with \n " << endl;
	std::cin >> value;

	/*Test the count_if function with function object
	*/
	int output_1 = 0;
	output_1 = count_if(myVec.begin(), myVec.end(), FunctionObject<double> (value));
	cout << "number of values less than comparison: "<< output_1 << "\n" << endl;

	return 0;

}

/*Reference 
* https://quantnet.com/threads/hard-coded-for-part-i.26206/
* https://quantnet.com/threads/general-questions-regarding-ex3.23902/#post-265195 
* https://quantnet.com/threads/function-objects-aka-functors.38664/
* 
*/














