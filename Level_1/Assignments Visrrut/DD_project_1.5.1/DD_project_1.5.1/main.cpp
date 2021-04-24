/*Author: Vishrut Talekar; Nov 2020
*/

/*
The purpose of the program is to define a function minus() and call it in the main 
This function receives two arguments and returns the difference (regular subtraction, not absolute). 
This difference should be printed on screen

Note: I have preferred to use user input and have selected double data type
*/

#include<stdio.h>


double minus(double num1, double num2)
{
	/*The function 'minus' calculates subtraction of 2 number of type double
	* returns: value of type double
	* name: minus
	* arguments: number 1 and number 2
	*/
	return num1 - num2;
}

int main()
{
	/*Declare and initialise variables
	*/
	double num1 = 0;
	double num2 = 0;

	/*Get the input from the user
	*/
	printf(" Please enter 2 numbers, the program will return the difference between number 1 and number 2\n");

	printf("number 1: \n");
	scanf_s("%lf", &num1);

	printf("number 2: \n");
	scanf_s("%lf", &num2);

	/*Calculate the subtraction and print the value on the console
	*/
	printf("The difference between Number:1 %lf and Number:2 %lf is: %lf", num1, num2, minus(num1, num2));

	return 0;
}


// https://quantnet.com/threads/1-clarification-of-minus-functionality.9628/page-2#post-182751
// READY FOR SUBMISSION