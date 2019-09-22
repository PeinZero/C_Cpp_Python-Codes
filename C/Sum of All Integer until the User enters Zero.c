#include <stdio.h>
#include <stdlib.h>

void main() {
	int num,sum=0;
	printf("Enter a Integer\n");
	scanf("%d",&num);
	sum = sum + num;
	system("cls");
	printf("The SUM is = %d\n",sum);
	
	while (num != 0){
		printf("Enter a Integer\n");
        scanf("%d",&num);
        system("cls");
        sum = sum + num;
        printf("The SUM is = %d\n",sum);
	}
}
