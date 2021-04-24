/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the program is to print two columns on screen displaying 
* temperature in Fahrenheit(left column) and Celcius(Right Column).
* Start with 0 degree Fahrenheit and proceed untill 300 with a step of 20 degrees
* The program is maintenance insensitive as user input is
* taken for start and end temperature as well as step_size
*/

# include<stdio.h>

int main()
{
	/*Declare and initialise variables*/
	double fahrenheit_start = 0;
	double fahrenheit_end = 20;
	double celcius = 0;
	int step_size = 20;

	printf("Enter starting Fahrenheit temperature: ");
	scanf_s("%lf", &fahrenheit_start);

	printf("Enter end Fahrenheit temperature: ");
	scanf_s("%lf", &fahrenheit_end);

	printf("Enter step size for incremental fahrenheit temperature: ");
	scanf_s("%d", &step_size);

	printf("Fahrenheit\t");
	printf("Celcius\n");
	
	/*While construction to loop through the increments of Fahrenheit
	* and calculate the corresponding Celcius
	*/
	while (fahrenheit_start <= fahrenheit_end)
	{
		celcius = (5.0 / 9.0) * (fahrenheit_start - (double)32);
		/*using tab for formatting*/
		printf("%10.1f\t", fahrenheit_start);
		printf("%10.1f\n", celcius);

		fahrenheit_start += step_size;

	}

}

/*Reference
* https://quantnet.com/threads/exercise-1-4-4-and-1-4-5.43849/
*/

//READY FOR SUBMISSION