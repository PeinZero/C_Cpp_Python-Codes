#include <stdio.h>

void main(){
	int i,j,n,temp = 1;
	
	printf("Enter N: ");
	scanf("%d",&n);
	printf("\n");
	
	for (i = 1 ; i <= (n/2)+1 ;i++){
		
		if ( i == (n/2)+1){
			for(j = 1 ; j <= temp ;j++){
				if (j == temp ){
					printf("********************\n");
				}
				else printf(" ");
			}
			temp++;	
		}
		else{
		
			for(j = 1 ; j <= temp ;j++){
					
				if (j == temp){
					printf("*  *  *            *\n");
				}
				else printf(" ");
			}
		}
		
	temp++;	
	}
	temp = temp -2;
	for (i = (n/2)+2 ; i < n ;i++){
		temp--;
		for(j = 1 ; j <= temp ;j++){
			if (j == temp){
				printf("*  *  *            *\n");
			}
			else printf(" ");
		}
		
	}
}
	

