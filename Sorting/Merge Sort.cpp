#include <iostream>
using namespace std;

void merge(int *left , int *right , int *arr , int llen , int rlen ){
	int i=0,j=0,k=0;
	while (i< llen && j < rlen){
		if (left[i] < right[j] ){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < llen){
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < rlen){
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergesort(int *arr , int n){
	
	if (n < 2){
		return;
	}
	else{
		int mid  = n /2;
		int left[mid] = {0};
		int right[n - mid] = {0};
		
		for (int i = 0 ; i < mid ; i++ ){
			left[i] = arr[i];
		}
		
		for (int i = mid ; i < n ; i++){
			right[i-mid] = arr[i];
		}
			
		mergesort(left , mid);
		mergesort(right, n - mid);
		merge(left,right,arr, mid , n-mid );
		
	}
}

void display(int *arr , int n){
	for (int i = 0 ; i < n ; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int n = 8;	                           // The Complexity is O(nlogn) in worst case.But the space complexity is not constant n its is O(n).
	int arr[n] = {5,4,16,7,1,67,3,8};      // Other sorting space complexity is constant n;
	
	mergesort(arr,n);
	display(arr,n);	
	return 0;
}
