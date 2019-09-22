#include<stdio.h>

int count5(int num){
	static int digit=0,c=0,last;
	last = num %10;
	if (last  == 5 && c == 1){
		digit = digit+2 ;
	}
	else if (last == 5){
		digit++;
		c = 1;
	}
	else c = 0;
	num = num/10;
	
	if (num > 1){
		count5(num);
	}
	else return digit;
	
}


void main (){
	int num,five;
	printf("Enter A Number\n");
	scanf("%d",&num);
	five = count5(num);
	printf("The Number of 5s in this number are = %d",five);	
}
