
using namespace std;
#include<iostream>

int Swap(int, int);

int main()
{
	int a = 0, b = 0;

	if (a < b) a = 10; b = 20;

	printf("%d, %d\n", a, b);
}

int Swap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;

	return a;
}
