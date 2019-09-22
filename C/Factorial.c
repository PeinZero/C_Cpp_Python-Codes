#include <stdio.h>
#include <stdlib.h>

void main (){
	int fact,x,sum=1;
	printf("you want factorial of ?\n");
	scanf("%d",&fact);
	
	if (fact > 0) {
	 	for (x=fact; x > 0 ; x--)
		{
			sum = sum * (x);
		}  
		printf("\n%d! = %d",fact,sum);
	}
	else if (fact == 0) 
	{
		printf("\n%d! = %d",fact,sum);
	}
	else printf("ERROR !!!");
}


