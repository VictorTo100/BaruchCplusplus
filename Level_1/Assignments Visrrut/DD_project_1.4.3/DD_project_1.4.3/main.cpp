/*
Author: Vishrut Talekar; Nov 2020
*/


/*
The purpose of the program is to count the number of characters, words and new line entered by the user
Checks: The purpose is to write the 1.4.1 using switch instead of if blocks. 
1. Once count starts, multiple spaces are not counted as words
2. Multiple spaces and enter are counted characters
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	/* Declare and initialise variables
	*/
	int input_char = 0 ;
	int previous_char = 0;
	/* Declare an array to store the count of characters, words and lines;
		Array of 3 integers
	*/
	int count_array[3];
	count_array[0] = 0; // Count for characters
	count_array[1] = 0; // Count for words
	count_array[2] = 0; // Count for Line 


	/*Check the first character, if it a space or an enter key
	*/
	/*Print intro text
	*/
	printf("Please enter characters. Exit with ^D\n");
	/* Get the characters
	* cntl D works fine for me hence checking only for this condition
	*/
	while ((input_char = getchar()) != 4)
	{
		/*Check for following conditions to count words
		1. Start of new word
		2. Start of new line
		3. Multiple white spaces(space, enter, tab) should not be multiple words
		*/

		/*Increment at start of new word to get total number of words before^ D
		  Check if current character is not a space and previous character is a space; also
		  account for the first character
		*/

		/*Intial condition; when there is not input; use switch to create conditions
		*/
		bool input_char_bool = isspace(input_char);
		bool previous_char_bool = isspace(previous_char);

		/*Check the conditions for counting the number of words
		*/
		switch (previous_char)
		{
		case 0:
			switch (input_char_bool)
			{
			case false:
				count_array[1]++; break;
			}
			break;
		}
		/*Check the conditions for counting the number of words
		* If the there is new inout character and previous character isspace is true
		*/
		switch (input_char_bool)
		{
		case false:
			switch (previous_char_bool)
			{
			case true:
				count_array[1]++; break;
			}
			break;
		}
		/*Check the conditions for counting the number of lines
		* Increment line when enter key is used and for the initial
		* starting condition when there is no input
		*/
		switch (input_char)
		{
		case 10:
			count_array[2]++; break;
		default:
			switch(previous_char)
			{ 
			case 0:
				count_array[2]++; break;
			} 
		}

		/* Count the characters irrespective of any condition
		*/
		count_array[0]++;
		previous_char = input_char;
	}

	/*
	Print the respective count for the characters, words and lines
	*/
	printf("The count of 'Characters' is:%d\n", count_array[0]);
	printf("The count of 'Words' is:%d\n", count_array[1]);
	printf("The count of 'Lines' is:%d\n", count_array[2]);

	return 0;
}

/*Reference
	https://quantnet.com/threads/exercise-1-4-1-1-4-6%EF%BC%9Adetails-on-counting-characters.43941/
	https://quantnet.com/threads/ctrl-d-and-ctrl-z-issues-1-4.8655/#post-75426
	https://quantnet.com/threads/1-4-6-use-default-to-count-the-number-of-other-char.44823/
	https://quantnet.com/threads/1-4-6-question.40056/
	https://quantnet.com/threads/1-4-1-newline-count.45307/
	https://quantnet.com/threads/1-4-1-how-to-count-lines.36495/
*/

// READY FOR SUBMISSION
