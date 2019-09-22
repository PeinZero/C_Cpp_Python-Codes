#include <stdio.h>

void bubblesort(int *ptr);
void main (){
	int i,arr[] = {5,1,7,3,9};
	printf("The Numbers Unsorted:");
	for (i=0;i<5;i++){
		printf("%3d  ",arr[i]);
	}
	bubblesort(arr);
	printf("\nThe Numbers Sorted:  ");
	for (i=0;i<5;i++){
		printf("%3d  ",arr[i]);
	}
}
void bubblesort(int *ptr){
	int i ,j,temp;
	for (i=0;i<5;i++){
		for (j=i+1;j<5;j++){
			if (ptr[i] > ptr[j]){
				temp = ptr[j];
				ptr[j]=ptr[i];
				ptr[i]=temp;
			}
		}
	}
}
