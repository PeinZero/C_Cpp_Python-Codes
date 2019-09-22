#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct student
{
	int id;
	char name[20];
	float per;
}S;

int main()
{
	int n,i;
	char temp[20];
	
	printf("enter how many students are there: ");
	scanf("%d",&n);
	
	S *ptr;
	
	ptr = (S *)calloc(n,sizeof(S));
	
	for (i =0 ; i < n ; i++){
		printf("Enter Student %d ID: ",i+1);
		scanf("%d",& ptr[i].id);
		fflush(stdin);
		printf("Enter Student %d Name: ",i+1);
		gets((ptr + i)->name);
		printf("Enter Student %d Percentage: ",i+1);
		scanf("%f",&(ptr + i)->per);
	}
	
	for (i =0 ; i < n ; i++){
		strcpy( temp , (ptr + i)->name );
		if (temp[0] == 'A'){
			printf("Student ID = %d\n",(ptr + i)->id);
			printf("Student Name = %s\n",(ptr + i)->name);
			printf("Student Per = %0.2f",(ptr + i)->per);
			
		}
		
	}
    return 0;
}
