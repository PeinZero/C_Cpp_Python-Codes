#include <stdio.h>
#include <stdlib.h>

void main (){
	int i,j,temp,digit,n,div,first=0;
	printf("how many nums ?\n");
	scanf("%d",&n);
	int a[n],b[n];
	int d[n];
	
	for (i = 0 ; i < n; i++){
		scanf("%d",&a[i]);
	}
	
	
	for (i = 0 ; i < n; i++){
		temp = a[i];
		digit=0;
		while (temp >= 1){
			temp = temp /10;
			digit++;
		}
		d[i] = digit;
		if (digit != 1){
		
			for (j = 1 ; j < digit ; j++){
				div = 10 * j;
			}
		}
		else div = 1;
		temp = a[i];
		first = temp/div;
		b[i] = first;
	}				
	
	for (i = 0 ; i < n; i++){
		for (j=i+1 ; j<n ; j++){
			if (b[i] < b[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				
				temp = d[i];
				d[i] = d[j];
				d[j] = temp;
				
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			
			}
		}
	}
	
//	for (i = 0 ; i < n; i++){
//		printf("%d  %d %d\n",a[i],d[i],b[i]);
//	}
			
	for (i = 0 ; i < n; i++){
		for (j=i+1 ; j<n ; j++){
			if (b[i] == b[j]  && d[i] > d[j]){
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					
					temp = d[i];
					d[i] = d[j];
					d[j] = temp;
					
					temp = b[i];
					b[i] = b[j];
					b[j] = temp;
					
			}
		}
	}
		

	for (i = 1 ; i < n; i++){
		for (j=i+1 ; j<n ; j++){
			if (b[i] == b[j]  && a[i] < a[j]){
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					
					temp = d[i];
					d[i] = d[j];
					d[j] = temp;
					
					temp = b[i];
					b[i] = b[j];
					b[j] = temp;
					
			}
		}
	}
	
	printf("\n\n");				
	
//	for (i = 0 ; i < n; i++){
//		printf("%d  %d %d\n",a[i],d[i],b[i]);
//	}
	
	printf("\n\n");
	for (i = 0 ; i < n; i++){
		printf("%d",a[i]);
	}
}
