/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the program is predict the output when different assignment operators are used
*/

/* Assignment operators */
#include <stdio.h>
int main()
{
	int x = 2;
	int y;
	int z;
	x *= 3 + 2; 
	/*The output is x = 10; first 3+2 get evaluated; then the multiplication assignment operator results in 2*5 = 10
	*/
	printf("x=%d\n", x);
	x *= y = z = 4; 
	/*The output is x = 40 ; assignment operator results in z = 4 and y = 4; x then results in 10*4 = 40
	*/
	printf("x=%d\n", x);
	x = y == z; 	
	/*The output is x = 1 ; The comparison operator is evaluated which results in 1; then x get assigned
	*/
	printf("x=%d\n", x);
	return 0;
}

// READY FOR SUBMISSION