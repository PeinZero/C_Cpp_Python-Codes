#include <stdio.h>
#include <stdlib.h>

void main() {
	int term,x,prev = 0 ,next =1 , sum =0 ;
	printf("How many Terms are there? \n");
	scanf("%d",&term);
	printf("The Fibonacci Sequence is: ");
	for (x=1 ; x<=term ; x++)
	{
		printf("%d,\t",prev);
		sum = prev + next;
		prev = next;
		next = sum ;
	}
}
