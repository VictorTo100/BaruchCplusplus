/*Author: Vishrut Talekar; Nov 2020
*/


/*The purpose of the program is to reads a string of max length 30 characters
* from the user. Implement function Length() to calculate the length of the
* inputted string. 
* The line ends with ctrl z(^Z)
* The testing program is given
*/


/* 
Calculate the length of a string 

*/
#include <stdio.h>
#include <string.h>

/*Define maximum length
*/
#define MAXLINE 30


/* Implement the Length() function here 
*/
int Length(char str[])
{
	/*arguments: character string
	* return: count of characters(upto 30)
	*/
	/* Decalre and initialise variables
	*/
	/*Declare character pointer
	*/
	char* p;
	/*Pointer points to the first element  of the character string
	*/
	p = str;
	int count = 0;
	/*while loop to increment through the character string
	* Thi is achieved by using the pointer arithmatic - DD notes 01-07; 13
	*/
	while ((*(p + count)) != '\0')
	{
		count++;
	}

	return count;
}

int main()
{	/*Declare and initialise variables
	*/
	char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
	int input_char; // The input character
	int count = 0; 

	/*Get input from user
	*/
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
	
	/*Read input characters until end of line is entered or reaches max line 
	*/
	while ((input_char = getchar()) != EOF && count < MAXLINE)
	{
		/*Append entered character to string
		*/
		string[count++] = (char)input_char;
	}
	string[count] = '\0'; // String must be closed with \0

	/*Calling the function Length and printing the output
	*/
	printf("String length with Length is %d\n", Length(string));
	/*Validating with internal function strlen
	*/
	printf("String length with inbuilt strlen is %zu\n", strlen(string));
	return 0;
}



