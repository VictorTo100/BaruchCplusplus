/*
 Author: Vishrut Talekar; Nov 2020
*/

/*The pupose of this program is multiply a
  number with 2 to power n and achieve this by using left shift operator
*/

#include<stdio.h>
#include<string.h>


int main()
{
	/*Declare and initialise variables
	*/
	int input_num = 0;
	int power_num = 0;

	/*Get user input
	*/
	printf("Please enter an integer\n");
	scanf_s("%d", &input_num);

	/*Get user input
	*/
	printf("Please enter an integer to get the product of the entered number multiplied to 2 to the power n \n");
	scanf_s("%d", &power_num);

	/*Apply right hand shift to the inputted integer*/

	input_num = input_num << power_num;

	printf("The result of the multiplication is %d:\n", input_num);

	return 0;
}

/* References
* https://quantnet.com/threads/summary-of-1-3-6.45349/
* https://docs.microsoft.com/en-us/cpp/cpp/left-shift-and-right-shift-operators-input-and-output?view=msvc-160
* https://www.sanfoundry.com/c-tutorials-logical-arithmetic-shifts-uses/
* https://quantnet.com/threads/question-on-1-3-6-negative-input-arithmetic-shift-positive-input-logical-shift.36493/
* https://quantnet.com/threads/1-3-6-indication-if-logical-or-arithmetic-shifts.10172/page-2
*
*/