#include <stdio.h>
#include <stdlib.h>

void main (){
	
	int x,i,j,counter=0,temp;
	int a[100],b[100];	
	FILE *fptr ;
	
	fptr = fopen("C:\\Users\\Monster\\Desktop\\devv\\Filing\\P1.txt","w+");

	
	printf("Input in the File P1 and Array A\n");
	printf("Press Any Key to Start\n");
	
	for (i = 0 ; scanf("%d",&x) != EOF; i++){
			
		fflush(stdin);
		printf("Enter A Num: ");
		scanf("%d",&a[i]);
		fprintf(fptr,"%d",a[i]);
		fprintf(fptr,"\n");
		printf("\nEnter CTRL + Z to end\n");
		counter++;
	}
	
	fprintf(fptr,"%d",x);
	
	printf(" \nContent of Array a\n\n");
	
	for (i = 0 ; i < counter ; i++){
		printf("%d ",a[i]);
	}
	
	
	rewind(fptr);
	counter = 0;
	
	
	printf("\n\nOutput From the File P1 and Input in Array B\n\n");
	
	for ( i = 0 ; !feof(fptr) ; ++i ){                                      // loop running 1 extra time..???
		if( feof(fptr) ) { 
		 printf("\nin here\n");
         break ;
      	}
		fscanf(fptr,"%d",&b[i]);
		counter++;
		printf("counter=%d\t",counter);
	}
	
	
	printf("\n\nThe Above is lopp is running 1 extra time...i have no idea why. \n");
	
	printf("\nThe Value of Counter after decrementing \n");
	counter--;
	printf("\n\ncounter = %d\n\n",counter);
	
	printf("\nContent of Array b\n\n");
	for (i = 0 ; i < counter ; i++){
		printf("%d ",b[i]);
		
	}
	
	
	for (i = 0 ; i < counter ; i++){
		for (j = 0 ; j < counter ; j++){
			if ( b[i] < b[j] ){
				temp = b[j];
				b[j] = b[i];
				b[i] = temp;
			}
		}
	}
	
	printf("\nContent of Array b after Sorting\n\n");
	for (i = 0 ; i < counter ; i++){
		printf("%d ",b[i]);
	}
	
	fclose(fptr);
	fptr = fopen("C:\\Users\\Monster\\Desktop\\devv\\Filing\\P1.txt","w");	
	
	for ( i = 0 ; i < counter ; i++ ){     
		fprintf(fptr,"%d",b[i]);
		fprintf(fptr,"\n");
	}
	
	fclose(fptr);
}

