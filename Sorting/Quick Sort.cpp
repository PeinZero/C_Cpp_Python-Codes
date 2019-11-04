#include <iostream>
using namespace std;

int partition(int *arr , int start , int end){
	int pivot = arr[end];
	int pivotIndex = start , temp;
		
	for (int i = start ; i < end ; i++){
		if (arr[i] <= pivot){
			temp = arr[i];
			arr[i] = arr[pivotIndex];
			arr[pivotIndex] = temp;
			pivotIndex++;
		}
	}
	
	temp = arr[pivotIndex];
	arr[pivotIndex] = arr[end];
	arr[end] = temp;
	
	return pivotIndex;	
}

void quicksort(int *arr , int start , int end){
	if (start < end){
		int pivotIndex = partition(arr,start,end);
		quicksort(arr, start , pivotIndex - 1 );
		quicksort(arr , pivotIndex + 1 , end);
	}
}

void display(int *arr , int n){
	for (int i = 0 ; i < n ; i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int n = 8;	                           
	int arr[n] = {5,4,16,7,1,67,3,8};
	quicksort(arr, 0 , n-1);
	display(arr,n);
	return 0;
}
