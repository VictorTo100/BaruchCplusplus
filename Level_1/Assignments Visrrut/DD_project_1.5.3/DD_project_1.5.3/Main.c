/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the program is to get the input from the user
* call the function print to print the multiplication of input with 2
*/

#include<stdio.h>

void print(double input_variable);

int main()
{
	double input_variable;
	/*Get user input*/
	printf("Please enter a number for and get result of multiplication with 2\n");

	scanf_s("%lf", &input_variable);
	/*Call print function*/
	print(input_variable);

	return 0;
}


/*
Reference
https://quantnet.com/threads/exercise-1-5-3.17879/
https://quantnet.com/threads/exercise-1-5-3.17879/page-2
*/

// READY FOR SUBMISSION
