/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the excercise is to predict the  output 
for the following lines in the given code
*/


/* Conditional expressions */
#include <stdio.h>

int main()
{
	int x = 1;
	int y = 1;
	int z = 1;
	
	/* y is assigned 2(y = y + x); then x is assigned 3(x = x +y)
	*/
	x += y += x;

	/* Since x > y value of x '3' is printed
	*/
	printf("%d\n\n", (x < y) ? y : x); 
	
	/* Since x > y value of y '2' is printed and then incremented
	*/
	printf("%d\n", (x < y) ? x++ : y++);
	/* Value of x '3' is printed
	*/
	printf("%d\n", x);
	/* Value of y '3' is printed
	*/
	printf("%d\n", y);
	return 0;
}

// READY FOR SUBMISSION