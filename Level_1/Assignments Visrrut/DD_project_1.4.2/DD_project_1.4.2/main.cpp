/*
Author: Vishrut Talekar; Nov 2020
*/

/*
Program freq.cpp
The purpose of the program is to count the number of characters, words and new line entered by the user
Checks:
1. Once count starts, multiple spaces are not counted as words
2. Multiple spaces and enter are counted characters
3. Uses the Do While construct
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	/* Declare and initialise variables
	*/
	int input_char = 0;
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
	*/
	do
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

		/*Intial condition; when there is no input
		*/
		if (previous_char == 0 && isspace(input_char) == false)
		{
			count_array[1]++;
		}

		/*Once there is initial input check for following
		*/
		if (isspace(input_char) == false && isspace(previous_char))
		{
			count_array[1]++; // it is start of new word; increment the count for words
		}
		/*Increment at start of new line to get total number of lines before ^D
		*/
		if (input_char == 10 || previous_char == 0)
		{
			count_array[2]++;
		}

		/* Count the characters irrespective of any condition*/
		count_array[0]++;
		previous_char = input_char;
	} while ((input_char = getchar()) != 4);

	/*Please note in do while 1 extra character, word and line is counted, 
	* this can be accounted for in post-processing as below
	*/
	count_array[0]--;
	count_array[1]--;
	count_array[2]--;


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