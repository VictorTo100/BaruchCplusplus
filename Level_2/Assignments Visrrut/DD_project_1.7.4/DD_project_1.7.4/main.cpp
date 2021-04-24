/*Author: Vishrut Talekar; Nov 2020
*/

/*
The purpose of the program is to define function DayName() which can print the day of a given day-number. 
For example: 1 gives: Day 1 is a Sunday 7 gives: Day 7 is a Saturday. 
*/

#include<stdio.h>
/* Definition of DayName
*/

/*The day - name(1 - 7) should be written "hard-coded” into the program using an array of strings.
*/
void DayName(unsigned int dayNum)
{
	/*arguments: Unsigned int from 1-7
	* output: print the day name
	*/
	 
	/*Declare an 2D- array character for 7 days and 10(9 and '/0' characters
	*/
	char dayName[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	/*printf to print the day number and the day name by accessing appropriate element of the array
	*/
	printf("Day %d is a %s", dayNum, dayName[dayNum - 1]);

}


int main()
{
	/*Declare and initialse variables
	*/
	unsigned dayNum = 1; // Day Number
	/*Get user input
	*/
	printf("Please enter number of weekday from 1 to 7\n");
	/*use scanf_s to assign user input to a variable
	*/
	scanf_s("%d", &dayNum);

	/*Print the day by calling the function DayName with 
	appropriate parameter argument
	*/
	DayName(dayNum);

	return 0; 
}

/*Reference
* https://quantnet.com/threads/1-7-4-an-array-of-strings.35061/
* 
*/