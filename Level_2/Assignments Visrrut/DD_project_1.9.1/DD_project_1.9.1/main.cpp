/*Author: Vishrut Talekar; Nov 2020
*/

/*The program reads the characters from the keyboard and shows them on screen
* the inputted characters are only be displayed when the user hits 'enter', line by line).
* When  CRTL+SHIFT+A is entered, the program exits. 
* Then the following message will appear: “CTRL + A is a correct ending.”
* Tip: getchar() reads and putchar() writes the type int. The value of ^A is 1.
*/


#include<stdio.h>
int main()
{
	/*Declare and initialise variables
	*/
	int input_char = 0; 
	/*Get user input
	*/
	printf("Please enter text, to end press control A. To view the output press enter\n");

	/*Conditional loop until  CRTL+SHIFT+A is entered
	*/
	while ((input_char = getchar()) != 1)
	{
		/*Buffered output, displayed when enter is used
		* using the putchar function
		*/
		putchar(input_char);
	}
	
	/*https://quantnet.com/threads/1-9-1-a-solution-to-ctrl-a-select-all-issue.26358/
	* Used CRTL+SHIFT+A
	* Display the ending
	*/
	printf("CTRL + A is a correct ending.\n");

	return 0;
}

/*Reference
* https://quantnet.com/threads/1-9-1-a-solution-to-ctrl-a-select-all-issue.26358/
*/
// READY FOR SUBMISSION