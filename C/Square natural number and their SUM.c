#include <stdio.h>
#include <stdlib.h>

void main() {
	int term,x,sum=0 ;
	printf("Enter No of Terms\n");
	scanf("%d", & term);
	system("cls");
	printf("THE SERIES IS :");
	
	for (x=1; x <= term ; x++){
		printf("%d  ", x*x);
		sum = sum + (x*x);
	}
	printf("\n\nSUM = %d",sum);
}
