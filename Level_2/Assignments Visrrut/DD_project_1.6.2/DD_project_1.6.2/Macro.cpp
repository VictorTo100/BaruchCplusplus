/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the program is to define two macros MAX2 and MAX3 respectively.
* MAX3 should make use of MAX2 to return the correct maximum value of the 
* given arguments
* 
* The Macro.cpp take tests the macros.
* It takes the user input and call the macros
*/


#include<stdio.h>
#include "Defs.h"

int main()
{
	/*Declaring and initialising variables
	* Assuming type double
	*/
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;

	/*Get input from user
	*/
	printf("Please input number: a \n");
	/*Assign user input to the variable
	*/
	scanf_s("%lf", &a);

	/*Get input from user
	*/
	printf("Please input number: b \n");
	/*Assign user input to the variable
	*/
	scanf_s("%lf", &b);
	/*Get input from user
	*/
	printf("Please input number: c \n");
	/*Assign user input to the variable
	*/
	scanf_s("%lf", &c);

	/*call MAX2; Prints the value of maximum between two numbers a and b
	*/
	printf("The max of %lf and %lf is %lf \n", a, b, MAX2(a, b));

	/*call MAX3; Prints the value of maximum between two numbers a, b and c
	*/
	printf("The max of %lf,  %lf and %lf is %lf \n", a, b, c, MAX3(a, b, c));

	return 0;
}

//READY FOR SUBMISSION
