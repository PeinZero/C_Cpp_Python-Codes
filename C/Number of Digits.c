#include <stdio.h>
#include <stdlib.h>

void main (){
	int num,digit=0;
	printf("Enter a Number\n");
	scanf("%d",&num);
	
    if (num == 0) {
    	digit++;
	}
    while (num > 0){
    
    	num = num / 10;
    	digit = digit +1 ;
    	
	}
    printf("%d Digit Number",digit);
}





















