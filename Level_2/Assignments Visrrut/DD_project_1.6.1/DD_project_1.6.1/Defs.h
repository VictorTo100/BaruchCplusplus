/*Author: Vishrut Talekar; Nov 2020
*/

/*The Defs.h defines two macros
* PRINT1 and PRINT2
* PRINT1 takes 1 argumement and outputs prints it
* PRINT2 takes 2 argumement and outputs prints it
* It takes the user inputand call the macros
*/

#ifndef Defs_H
#define Defs_H

/*Define the PRINT1 Macro
* args: Takes in 1 number as argument
* output: Printa the number
*/
#ifndef PRINT1
#define PRINT1(a) printf("a = %d\n", a) // Assuming fixed type int
#endif //
/*Define the PRINT1 Macro
* args: Takes in two numbers as argument
* output: Prints the numbers
*/
#ifndef PRINT2
#define PRINT2(a, b) printf("a = %d, b = %d\n",  a, b) // Assuming fixed type int
#endif //

#endif

// https://quantnet.com/threads/1-6-1-1-6-2-int-vs-float.44567/ 
// https://quantnet.com/threads/question-regarding-1-6-1-and-1-6-2.43509/#post-274216