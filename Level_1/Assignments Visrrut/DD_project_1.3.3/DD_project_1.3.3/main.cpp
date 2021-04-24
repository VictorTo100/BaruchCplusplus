/*Author: Vishrut Talekar; Nov 2020 
*/


/* The purpose of the program is to predict the output
* and provide comment for each line
*/

/* Operators */
#include <stdio.h>
int main()
{
	int x;
	x = -3 + 4 * 5 - 6;
	printf("x=%d\n", x); // output x = 11; Applying the precedence; multiplication gives 20 and then subtraction from left to right
	x = 3 + 4 % 5 - 6;
	printf("x=%d\n", x); // Output x = 1; Applying the precedence; modulo gives 4 as remainder, then addition and subtraction from left to right
	x = -3 * 4 % -6 / 5;
	printf("x=%d\n", x); // Output x = 0; Applying the precedence; multiplication gives -12, then modulo gives 2 and division gives 0.4, however since assigned to int the output is 0
	x = (7 + 6) % 5 / 2;
	printf("x=%d\n", x); // Output x = 1; Applying the precedence; Addition in bracket gives 13, then modulo gives 3 as remainder, then division gives 1.5, however since assigned to int the output is 1
	return 0;

}