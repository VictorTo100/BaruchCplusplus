/*Author: Vishrut Talekar; Nov 2020
*/

/*The purpose of the program is to predict what will be printed on the screen
*/
#include<stdio.h>
#include"Article.h"


int main()
{
	/* Intialize the structure
	*/
	struct Article article = {1, 2, "What a description"}; 

	/*print function is called with address of article as argument
	*/
	print(&article);

	return 0;
}