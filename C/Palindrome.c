#include <stdio.h>
#include <stdlib.h>

void main() {
	int num,numx,digit=0,div=1,x,a,b;
	printf("Enter a Number\n");
	scanf("%d",&num);
	
    a = num%10;
    numx = num ;
	
    while (numx > 0){
       	numx = numx / 10;
    	digit = digit +1 ;
   	}	
	
	for (x=2; x <= digit ; x++) {
		div = div * 10;
	}	
	
	b = num/div ;
	
	if (a == b){
		printf("The Number is Palindrome") ;
	}
	else printf("The Number is NOT Palindrome");
}
