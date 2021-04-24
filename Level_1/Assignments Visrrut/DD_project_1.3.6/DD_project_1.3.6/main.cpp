/*
 Author: Vishrut Talekar; Nov 2020
*/


/*The pupose of this program is to check whether;
  the right shift is logical shift or a arithmatic shift
*/

#include<stdio.h>
#include<string.h>


int main()
{
	/*Declare and initialise variables
	*/
	int input_num = 0;
	int shifted_num = 0;

	printf("Please enter an integer\n");

	scanf_s("%d", &input_num);

	/*Apply right hand shift to the inputted integer*/

	shifted_num = input_num >> 2;

	printf("The shifted output is %d:\n", shifted_num);

	/*Check if the sign of the input and output to determine 
	whether it is logical shift or arithmatic shift
	*/

	if (input_num < 0)
	{
		/* Check if the shifted number is negative */
		if (shifted_num < 0)
		{
			printf("Arithmatic shift was done\n");
		}
		/* Check if the shifted number is positive */
		else if (shifted_num > 0)
		{
			printf("Logical shift was done\n");
		}
	}
	else if (input_num > 0)
	{
		if (shifted_num > 0)
		{
			printf("Logical shift was done\n");
		}
	}
	 
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

// READY FOR SUBMISSION