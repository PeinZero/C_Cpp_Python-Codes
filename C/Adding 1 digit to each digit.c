#include <stdio.h>
#include <stdlib.h>

void main() {
	int num,numx,digit=0,div=1,x,a1,b1;
	printf("Enter a Number\n");
	scanf("%d",&num);
	numx = num ;
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
	a1 = num/div;
	a1 = a1 + 1 ;
	if (a1 == 10) {
		a1 = 0;
	}
	printf("%d",a1);
    while (div != 1) {
    	num = num % div ;
    	div = div / 10 ;
    	b1 = num /div;
    	b1 = b1 + 1;
    	if (b1 == 10) {
		b1 = 0 ;
	    }
    	printf("%d",b1);
	}
}
