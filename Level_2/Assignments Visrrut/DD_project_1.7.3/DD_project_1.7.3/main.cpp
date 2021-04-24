#include<iostream>
using namespace std;
/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the program is to predict what will be printed on the screen 
*/

#include <stdio.h>
#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line
// Create and initialse array
int a[] = { 0, 1, 2, 3, 4 };
int main()
{
	int i;
	int* p;
	for (i = 0; i <= 4; i++) PRD(a[i]); // The result will be: 01234 will be printed on screen. i goes from 0 to 4 in loop and PRD print a[i] with %d format
	NL;
	/* Below: The result will be: 01234 will be printed on screen. The int pointer p starts at address of a[0] and increments  
	* till address of a[4] in loop and resulted is printed using dereference of pointer
	*/
	for (p = &a[0]; p <= &a[4]; p++) PRD(*p);
	NL;
	NL;
	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]); //The result will be: 01234 will be printed on screen; indexing with pointer
	NL;
	/*Below:The result will be: 024 will be printed on screen; both p and i are incremented also hence intermediate location are skipped
	*/
	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); 
	NL;
	NL;
	for (p = a + 4; p >= a; p--) PRD(*p); //The result will be: 43210 will be printed on screen; derefering the pointer and iterating from the end to the begining
	NL;
	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]); //The result will be: 43210 will be printed on screen; pointer indexing from the last index
	NL;
	for (p = a + 4; p >= a; p--) PRD(a[p - a]); //The result will be: 43210 will be printed on screen; p is assigned to last address, difference in location is used as index
	NL;
	return 0;
}

// READY FOR SUBMISSION