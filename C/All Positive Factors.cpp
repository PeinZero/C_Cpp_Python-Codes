#include <stdio.h>
#include <stdlib.h>

int main() {
	int num,factor;
	printf("Enter a Positive Integer\n");
	scanf("%d",&num);
	factor = num;
	system("cls");
	printf("THE FACTOR is = %d\n",factor);
	
	if (num%2 == 0){
		while (factor != 1){
			factor = factor/2;
			printf("THE FACTOR is = %d\n",factor);
		}
	}
	return 0 ;
	
}
