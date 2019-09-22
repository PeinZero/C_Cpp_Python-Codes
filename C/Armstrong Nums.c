#include <stdio.h>
#include <stdlib.h>

void main() {
	int num,numx,numy,digit=0,div=1,x,a,b,sum;
	printf("Enter a Number\n");
	scanf("%d",&num);
	numx = num ;
	numy = num ;
	if (numx == 0) {
    	digit++;
	}
    while (numx > 0){
    
    	numx = numx / 10;
    	digit = digit +1 ;
   	}	
	for (x=2; x <= digit ; x++) {
		div = div * 10;
	}	
	a = num/div;
	sum = (a*a*a);
    
	while (num/10 != 0) {
    	b = num % 10 ;
    	num = num/10;
    	sum = sum + (b*b*b);
   	}
   	
    if (sum == numy){
   		printf("\nThe Number is Armstrong !!!");
	}
	else printf("\nThe Number is NOT Armstrong !!!");
}
