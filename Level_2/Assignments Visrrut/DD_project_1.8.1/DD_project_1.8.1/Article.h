/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of this file is to define structure arcticle and 
* function print
*/

#ifndef Article_H
#define Article_H

#include <iostream>
using namespace std;

/* Define struct Article with 3 data memebers, Article_number
*  
*/
struct Article
{ 
	int Article_number;
	int Quantity;
	char Description[21];
};

/* Define the print function*/
void print(struct Article* input)
{
	/*arguments: address of the struct
	* return: prints the construct 
	*/
	printf("The arcticle has Number:%d \nQuantity:%d and\nDescription:%s\n ", input->Article_number, input->Quantity, input->Description);
}

#endif
