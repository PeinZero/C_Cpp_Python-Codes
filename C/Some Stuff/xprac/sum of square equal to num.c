#include <stdio.h>

void main()
{
	int num,i,j;
	printf("Enter A Number\n");
	scanf("%d",&num);
	
	for (i =1 ; i <= num ; i++)
	{
		for (j = 1 ; j <= num ; j++)
		{
			if ( (i*i) + (j*j) == num )
			{
				printf("%d*%d + %d*%d = %d\n",i,i,j,j,num);
			}
		}
	
	}
}
