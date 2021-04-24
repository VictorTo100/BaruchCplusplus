/*Author: Vishrut Talekar; Nov 2020
*/


/*This program contains two print macro calls.
* The first prints the variable a, the second prints the variables a and b.
* Printing happens by the use of the PRINT1 and PRINT2 macros that accept arguments.
*/

#include<stdio.h>
#include"Defs.h"


int main()
{
	/*Declare and initialise variables
	* Assuming a type hence not checking for a particular type
	*/
	int a = 0;
	int b = 0;
	/*Get input from user for variable a
	*/
	printf("Please input integer: a \n");
	/*Assign user input to the variable a
	*/
	scanf_s("%d", &a);
	/*Get input from user for variable b
	*/
	printf("Please input integer: b \n");
	/*Assign user input to the variable b
	*/
	scanf_s("%d", &b);

	/* Call PRINT1
	*/
	PRINT1(a);

	/* Call PRINT2
	*/
	PRINT2(a, b);

	return 0;
}

// https://quantnet.com/threads/1-6-1-1-6-2-int-vs-float.44567/ 
// https://quantnet.com/threads/question-regarding-1-6-1-and-1-6-2.43509/#post-274216
// https://quantnet.com/threads/1-6-1-question-for-ifndef-define-endif.32211/

// READY FOR SUBMISSION