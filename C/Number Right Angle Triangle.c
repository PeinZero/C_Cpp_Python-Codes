#include <stdio.h>
#include <stdlib.h>

void main() {
	int num,c=0,x,i,j,temp1,a,div=1 ;
	printf("Enter A Num\n");
	scanf("%d", & num);
	system("cls");
	
	temp1 = num ;
	while (temp1 > 0){
		temp1 /= 10;
		c++;
	}
	for (x = 2; x <= c ; x++ ){
		div = div*10;
	}
	
	for (i = 1 ;i <= c; i++ ) 
	{
		for (j = 1 ;j <= i ;j++)
		{
			a = num/div ;
			printf("%d\n",a);
			div = div/10 ;
		}
	}
}
