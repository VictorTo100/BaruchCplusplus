/*Author: Vishrut Talekar; Nov 2020
*/


/*The purpose of this program is to write a function to calcualate
* factorial of a given number and achieve this by using recursion
* Note: Calculation capped at factorial of 20
*/

#include<stdio.h>

long long int compute_factorial(int num)
{
	/* returns: factorial of an integer of type long
	*  name: compute_factorial
	*  arguments: number of type int
	*/
	int temp = 0;
	/* */
	if (num < 0)
	{
		printf("Number is less than 0, please run the program again with number 0 or greater than 0\n");
		return 0;
	}
	/* Check the condition for 0 and 1
	*/
	else if (num == 0 || num == 1)
	{
		return 1;
	}
	/* Call the function as part of recursion
	*/
	else
	{
		int temp = num - 1;
		return compute_factorial(num - 1) * num;
	}

}

int main()
{
	/* Declare and initialise the variables
	*/
	int input_number = 0;
	long long int factorial_result = 0;
	/* Get input from user
	*/
	printf("Enter a positive integer\n");
	scanf_s("%d", &input_number);

	/* Call the compute_factorial function
	*/
	factorial_result = compute_factorial(input_number);

	/* Print the results
	*/
	printf("The factorial of %d = %lld\n", input_number, factorial_result);
	return 0;
}

/*Reference
* https://quantnet.com/threads/exercise-1-5-2.38693/ // facing same restriction
*/

// READY FOR SUBMISSION