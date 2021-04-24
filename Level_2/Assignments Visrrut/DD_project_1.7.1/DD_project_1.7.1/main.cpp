/*Author: Vishrut Talekar; Nov 2020
*/

#include<stdio.h>

/*The purpose of the program is to write a swap function to swap two numbers and test this in the main
* This function exchanges the value of two variables. 
* For example: if i=123 and j=456, then i=456 and j=123 after the Swap() function has been called.
* This problem has been solved by using pointers as arguments for the Swap()function.
* 
*/

/*Define the PRINT1 Macro
* arguments: Takes in 1 number as argument
* output: Printa the number
*/
void swap_integers(int* pt_int_1, int* pt_int_2)
{
	/*arguments: Two pointers for the numbers to be swaped
	* returns: Swaped numbers 
	*/
	/*Declare and initialise variables
	*/
	int temp; 
	/*Dereference the pointer_1 to temp variables
	*/
	temp = *pt_int_1;
	/*Dereference the pointer_2 to pointer_1
	*/
	*pt_int_1 = *pt_int_2;
	/*Assign the value held by temp to pointer_2
	*/
	*pt_int_2 = temp;
}


int main()
{
	/*Declare two int pointer
	* Assuming swapping of two int variables in this case
	*/
	int* p;
	int* m;

	/*Declare and 
	* Assuming swapping of two int variables in this case
	*/
	int i = 0;
	int j = 0;
	/*Get input from user for variable i
	*/
	printf("enter the value of integer a \n");
	/*Assign user input to the variable i
	*/
	scanf_s("%d", &i);

	/*Get input from user for variable j
	*/
	printf("enter the value of integer b \n");
	/*Assign user input to the variable j
	*/
	scanf_s("%d", &j);

	/*Print the values of i and j before the swap
	*/
	printf("the value of i before the swap is %d\n", i);
	printf("the value of j before the swap is %d\n", j);
	
	/*Assign the address of i and j to the pointers p and m
	*/
	p = &i;
	m = &j;

	/*Print the memory address of p and m before the swap
	*/
	printf("the value where p is pointing before swap is %p\n", p);
	printf("the value where m is pointing before swap is %p\n", m);

	/*Call the swap function
	*/
	swap_integers(p, m); 
	
	/*Print the memory address where p and m is pointing after the swap
	*/
	printf("the value p after is %p\n", p);
	printf("the value m after is %p\n", m);
	/*Print the values of  i and j after the swap
	*/
	printf("the value i after is %d\n", i);
	printf("the value j after is %d\n", j);

	return 0;
}

