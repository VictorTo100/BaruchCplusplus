/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the program is to prints two columns on the screen with the
* temperature in degrees Celsius in the left column and degrees Fahrenheit in the right column.
* Start with 0 degrees Celsius and proceed until 19 degrees Celsius.
* Take steps of 1 degree. Print degrees Fahrenheit with 1 position after the comma.
* Also print a header text
*/
#include<stdio.h>

int main()
{
	/*Declare and initialise variables
	*/
	double fahrenheit = 0;
	int step_size = 1;

	printf("Celcius\t\t");
	printf("Fahrenheit\n");

	/*Use the for construct to loop through the increments of temperature
	*/
	 for(double celcius=0.0; celcius <= 19; celcius++)
	{
		fahrenheit =  (9.0/5.0) * (celcius + (double)32.0);

		printf("%10.1f\t", celcius);
		printf("%10.1f\n", fahrenheit);

	}
}

// READY FOR SUBMISSION