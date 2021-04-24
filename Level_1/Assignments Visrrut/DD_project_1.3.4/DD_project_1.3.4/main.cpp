
/*Author: Vishrut Talekar; Nov 2020
*/

/* The purpose of the program is to use zero('0') and non-zero number(1) to create boolean output
* Also use the ?: operator for condition
*/

#include<stdio.h>

int main()
{
	/*Declare and initialise variables
	*/
	int married = 0;
	/*Get user input*/
	printf(" Enter 0 if you are married and 1 if you are married:\n");

	scanf_s("%d", &married);

	printf(married ? "Yes, you are married" : "No, you are not married");


	return 0;
}

// READY FOR SUBMISSION