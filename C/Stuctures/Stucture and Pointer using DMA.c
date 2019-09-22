#include<stdio.h>
#include<stdlib.h>

typedef struct P{
	char name[30];
	int age;
	float weight;
} person ;

void main (){
	person *ptr;
	int n,i;
	
	printf("How many People are there? ");
	scanf("%d",&n);
	
	ptr = (person *) malloc (n * sizeof(person));
	
	for ( i = 0 ; i < n ; i++){
		printf("\nEnter Person %d details\n\n",i+1);
		printf("Enter Name: ");
		fflush(stdin);
		gets((ptr+i)->name);
		printf("Enter Age: ");
		scanf("%d",&(ptr+i)->age);
		printf("Enter Weight: ");
		scanf("%f",&(ptr+i)->weight);
	}
	
	for ( i = 0 ; i < n ; i++){
		printf("\nPerson %d details\n\n",i+1);
		printf("Name: %s\nAge: %d\nWeight: %0.2f",(ptr+i)->name,(ptr+i)->age,(ptr+i)->weight);
	}
}
