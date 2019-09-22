#include <stdio.h>

void main(){
	int num,last,temp;
	
	printf("Enter A Number\n");
	scanf("%d",&num);
	temp = num;
	while ( temp > 9){
		last = (temp%10)*2;
		temp = temp/10;
		temp = temp - last;
		if (temp < 0){
			temp = -1 * temp;
		}
	}
	
	if ( temp == 7 || temp == 0 ){
		printf("number is divisibe");
	}
	else printf("number is not divisibe");
}
