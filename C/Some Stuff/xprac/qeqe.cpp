#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	
	printf("Address of a = %d\n", &a);
	printf("Address of b = %d\n", &b);
	int **p;
	p = (int**) malloc(10*sizeof(int * ));
	printf("Address of p = %d\n", &p);
	printf("Address held by p = %d\n", &p);
	
	
}
