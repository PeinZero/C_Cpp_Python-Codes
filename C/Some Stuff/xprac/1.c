#include <stdio.h>

int temp;

void fact(int *ptr){
	
	temp--;
	*ptr = *ptr * temp;
	if (temp > 1){
		fact(ptr);
	}
	
	
}

void main () {
	int num;
	
	scanf("%d",&num);
	temp = num;
	fact(&num);
	printf("Factorial is %d!",num);
	
	
}
