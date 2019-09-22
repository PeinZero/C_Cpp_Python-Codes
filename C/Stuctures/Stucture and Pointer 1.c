#include<stdio.h>

typedef struct n{
	int age;
	float weight;
} aw ;

void main (){
	aw *nameptr , temp;
	
	nameptr = &temp;
	
	printf("Enter Your Age: ");
	scanf("%d",&nameptr->age);

	printf("Enter Your Weight: ");
	scanf("%f",&nameptr->weight);	
	
	printf("%d\n%0.2f",nameptr->age , nameptr->weight);
}
