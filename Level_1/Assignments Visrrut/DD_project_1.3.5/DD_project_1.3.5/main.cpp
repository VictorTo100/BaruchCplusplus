
/*Author: Vishrut Talekar; Nov 2020
*/
/*The purpose of the program is to show the difference between the --i and i-- operator
*/

#include<stdio.h>

int main()
{
	/*Decalre and initialise variables
	*/
	int i = 4;
	int j = 0;

	/* i is incremented and then multiplied with 5 and output is j = 25 and i = 5
	*/
	j = ++i * 5; 
	printf("i = %d and j = %d \n", i, j);

	/*i is multiplied with 5 and hence of output is j = 20 and i = 5
	*/
	i = 4;
	j = i++ * 5; // 
	printf("i = %d and j = %d", i, j);

	return 0;

}

// READY FOR SUBMISSION