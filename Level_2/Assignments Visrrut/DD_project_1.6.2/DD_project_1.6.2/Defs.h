/*Author: Vishrut Talekar; Nov 2020
*/

/*The Defs.h defines two macros
* MAX2 and MAX3
* MAX2 outputs the maximum of two numbers
* MAX3 outputs the maximum of three numbers
* It takes the user inputand call the macros
*/

#ifndef DEFS_H
#define DEFS_H

/*Define the MAX2 Macro
* args: Takes in two number arguments
* output: Returns maximum of the two input arguments
*/

#ifndef MAX2
#define MAX2(a, b) ((a > b) ? a : b) // Use the Ternary operator; short conditional expression
#endif //

/*Define the MAX3 Macro
* args: Takes in three number
* output: Returns maximum of the three input arguments
*/
#ifndef MAX3
#define MAX3(a, b, c) MAX2(MAX2(a , b), c) // Use MAX2 in sequence
#endif //

#endif //

/*Reference
* https://quantnet.com/threads/2-about-maximum.35314/
* DD notes 01-03, 16
*/
 

