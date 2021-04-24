
/*Author: Vishrut Talekar; Nov 2020
*/

/*This is extension of 1.9.1
* The program reads the characters from the keyboard and
* when the user hits 'enter', line by line the text is writtent to a file
* When  CRTL+SHIFT+A is entered, the program exits. 
* Then the following message will appear: “CTRL + A is a correct ending.”
* Tip: getchar() reads and putchar() writes the type int. The value of ^A is 1.
* 
*/


#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*Declare and initialise variables
	*/
	int input_char = 0;
	char filename[21] = {'\0'};
	/*Declare file Handle
	*/
	FILE *fp;
	/*Declare for return of fopen_s
	*/
	errno_t err_status;
	
	/*Get user input
	*/
	printf("Please enter name of the file <>.txt to save the text\n");
	/*Get user input
	*/
	gets_s(filename);

	/*Get text input from user*/
	printf("Please enter text, and CTRL+SHIFT+A to exit. To view the output press enter\n");

	/*Use fopen_s to open a file in the write mode
	*/
	err_status = fopen_s(&fp, filename, "w+");
	if (err_status == 0)
	{
		printf("File is open\n");
	}
	else
	{
		printf("Failed to open the file\n");
	}

	
	/*Buffered out, display when enter is used
	*/
	while ((input_char = getchar()) != 1)
	{
		/*using fputc to input the characters
		*/
		fputc(input_char,  fp);
	}

	/*
	* Used CRTL+SHIFT+A
	* Display the ending
	*/
	printf("CTRL + A is a correct ending.\n");
	/*Close the file Handle
	*/
	fclose(fp);
	return 0;
}

/*Reference
* https://quantnet.com/threads/1-9-1-int-1-9-2-fopen_s-concerns.42016/
* https://quantnet.com/threads/1-9-2-the-file-to-write-to-must-be-specified-by-the-user.45464/
* https://quantnet.com/threads/1-9-1-a-solution-to-ctrl-a-select-all-issue.26358/
* https://quantnet.com/threads/1-9-2-fopen-and-fopen_s.35176/
* https://quantnet.com/threads/1-9-2-way-to-dynamically-get-filename.34290/
* https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-s-wfopen-s?redirectedfrom=MSDN&view=msvc-160&viewFallbackFrom=vs-2019
*/

// READY FOR SUBMISSION