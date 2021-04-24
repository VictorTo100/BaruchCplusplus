
/*
Program freq.cpp
The purpose of the program is to count the number of time 0,1,2,3,4 are entered and
the count of all other entries(except ^Z) is counted together
Checks:
1. count does not start if space of enter in entered
2. Once count starts, space and enter is considered as 'Others'
3. Multiple spaces and enter are counted
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// String lenght declaration

int main()
{
	/* The input character
	*/
	int input_char;
	/* Declare an array to store the count of 0-4 and default characters entered
	   Array of 6 integers
	*/
	int count_array[6];

	count_array[0] = 0;
	count_array[1] = 0;
	count_array[2] = 0;
	count_array[3] = 0;
	count_array[4] = 0;
	count_array[5] = 0;

	/*Print intro text
	*/
	printf("Please enter characters. Exit with ^Z\n");
	/* Get the characters
	*/
	while ((input_char = getchar()) != EOF && input_char != 26)
	{
		switch (input_char)
		{
			/* Checks for '0'
			*/
		case 48:
			count_array[0]++; break;
			/* Checks for '1'
			*/
		case 49:
			count_array[1]++; break;
			/* Checks for '2'
			*/
		case 50:
			count_array[2]++; break;
			/* Checks for '3'
			*/
		case 51:
			count_array[3]++; break;
			/* Checks for '4'
			*/
		case 52:
			count_array[4]++; break;
			/* Checks for 'Others'
			*/
		default:
			count_array[5]++;

		}

	}

	/*
	Print the respective frequency/count for the characters
	*/
	printf("The count of '0' is:%d\n", count_array[0]);
	printf("The count of '1' is:%d\n", count_array[1]);
	printf("The count of '2' is:%d\n", count_array[2]);
	switch(count_array[3])
	{
	case 0:
		printf("Number three appears zero times\n"); break;
	case 1:
		printf("Number three appears one time\n"); break;
	case 2:
		printf("Number three appears two times\n"); break;
	default:
		printf("Number three appears more than times\n"); break;
	}
	printf("The count of '4' is:%d\n", count_array[4]);
	printf("The count of 'others' is:%d\n", count_array[5]);

	return 0;
}


/*Reference
	https://quantnet.com/threads/exercise-1-4-1-1-4-6%EF%BC%9Adetails-on-counting-characters.43941/
	https://quantnet.com/threads/ctrl-d-and-ctrl-z-issues-1-4.8655/#post-75426
	https://quantnet.com/threads/1-4-6-use-default-to-count-the-number-of-other-char.44823/
	https://quantnet.com/threads/1-4-6-question.40056/

*/

// READY FOR SUBMISSION
