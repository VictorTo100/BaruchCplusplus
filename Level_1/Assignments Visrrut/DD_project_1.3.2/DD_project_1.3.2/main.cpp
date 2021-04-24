/*Author: Vishrut Talekar;Nov 2020
*/

/*The purpose of the program is to calculate surface area of a 
right angle traingle and return the value to the user
* The value of height and base are taken from the user
*/

# include <stdio.h>

int main() {

	/* Declare and initialise the variables for height, base and 
	surface area for the triangle respectively
	*/
	double height = 0.0;
	double base = 0.0 ;
	double surface_area = 0.0;

	/*User input for height*/
	printf("Enter value of height a positive number upto 2 decimals: ");
	scanf_s("%lf", &height);
	/*User input for base*/
	printf("Enter value of base a positive number upto 2 decimals: ");
	scanf_s("%lf", &base);

	/*Calculate the surface area of a right angle traingle */
	surface_area = 0.5 * base * height;

	/*Print the area to the console*/
	printf("The area of the triangle = %lf ", surface_area);

	return 0;
}

// READY FOR SUBMISSION