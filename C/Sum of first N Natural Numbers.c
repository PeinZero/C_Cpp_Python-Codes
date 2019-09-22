#include <stdio.h>
#include <stdlib.h>

void main (){
	int n,x,sum=0;
	printf("Sum of Natural Numbers from 1 to N\n");
	printf("Enter N\n");
	scanf("%d",&n);
	for (x=1; x<=n ; x++)
	{
		sum = sum + x;
	}
	printf("\nSum = %d !!!",sum);
}

