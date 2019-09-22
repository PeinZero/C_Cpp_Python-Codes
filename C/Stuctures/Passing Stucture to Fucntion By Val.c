#include <stdio.h>
struct student
{
    char name[10];
    int roll;
};

void display(struct student stu);
// function prototype should be below to the structure declaration otherwise compiler shows error

int main()
{
    struct student stud;

    printf("Enter student's name: ");
    scanf ("%[^\n]%*c", stud.name);

    printf("Enter roll number:");
//    fflush(stdin);
    scanf("%d", &stud.roll);
    
    display(stud);   // passing structure variable stud as argument
    
    return 0;
}
void display(struct student stu){
  printf("Output\nName: %s",stu.name);
  printf("\nRoll: %d",stu.roll);
}
