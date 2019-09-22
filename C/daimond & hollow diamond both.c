#include<stdio.h>

void main(){
	int i,j,n,c;
	
	printf("Enter N: ");                   // change the position * and space to make hollow diamond.
	scanf("%d",&n); 

	printf("\n");
	for (i=0;i<(n/2)+1 ;i++){
		for (j=1;j<=(2*n)-1;j++){
			if (j < n-i || j > n+i){
				printf(" ");
			}
			else printf("*");
		}
		printf("\n");
	}
	for (i=(n/2)-1;i>=0 ;i--){
		for (j=1;j<=(2*n)-1;j++){
			if (j < n-i || j > n+i){
				printf(" ");
			}
			else printf("*");
		}
		printf("\n");
	}
	
	printf("\n");
	for (i=0;i<(n/2)+1 ;i++){
		for (j=1;j<=(2*n)-1;j++){
			if (j < n-i || j > n+i){
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
	for (i=(n/2)-1;i>=0 ;i--){
		for (j=1;j<=(2*n)-1;j++){
			if (j < n-i || j > n+i){
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
	

}
