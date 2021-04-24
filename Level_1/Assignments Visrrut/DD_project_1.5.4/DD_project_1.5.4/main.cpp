/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the program is get an integer input from the user
* and print the digits of the number in the given order
* also handle the negative sign appropriately
*/

#include<stdio.h>

void printnumber(int input_num)
{
	/*Condition for negative integer
	*/
	if (input_num < 0)
	{
		/* Print the negative sign first*/
		putchar('-');
		/*Make the number positive after print minus sign*/
		input_num = -1 * input_num;
	}
	/*Condition to check the digits*/
	if (input_num / 10 != 0)
	{	
		/* Pass the remaining digits as input of the recursion
		   Call to the function makes sure the print of digits are in 
		   correct order
		*/
		printnumber(input_num / 10);
		/* Print the remainder using modulus
		* Also use the '0' for ascii conversion for digits 0-9(48-57)
		*/
		putchar('0' + input_num % 10);
	}
	else
	{	
		putchar('0' + input_num);
	}
}

int main()
{

	int input_num = 0;

	/* Get user input*/
	printf("Please enter an integer\n");

	scanf_s("%d", &input_num);

	printf("The printed number is:\n");
	/* Call the function printnumber*/
	printnumber(input_num);

	return 0;
}

/*
https://quantnet.com/threads/question-on-problem-1-5-4.8090/
https://www.w3schools.com/charsets/ref_html_ascii.asp

*/