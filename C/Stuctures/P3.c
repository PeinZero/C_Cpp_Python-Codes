#include <stdio.h>

struct rectangle{
	float lenght;
	float width ;
};

int check(struct rectangle X){
	
	int flag = 1;
	
	if ((X.lenght > 0 && X.lenght < 20) && (X.width > 0 && X.width < 20)){
		flag = 1;
	}
	else{
		printf("Lenght and Width must be greater than 0.0 and less than 20.0\n\n");
		flag = 0;
	}
	
	
	return flag;		
}

void member(struct rectangle X, float *area, float *perimeter){
	*area = X.lenght * X.width;
	*perimeter = 2*(X.lenght + X.width);
}


void main (){
	int flag = 0;
	float area,perimeter;
	struct rectangle X;
	X.lenght = 1;
	X.width = 1;
	do
	{ 
	printf("Enter Lenght of Rectangle\n");
	scanf("%f",&X.lenght);
	printf("Enter Width of Rectangle\n");
	scanf("%f",&X.width);
	flag = check(X);
	}while (flag == 0);
	
	member(X,&area,&perimeter);
	
	printf("\nTHE AREA OF THE RECTANGLE IS = %0.2f\n",area);
	printf("THE PERIMETER OF THE RECTANGLE IS = %0.2f\n",perimeter);
	
			
}
