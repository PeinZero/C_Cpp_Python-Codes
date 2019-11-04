#include <iostream>
using namespace std;

int main(){
	int n = 8;	
	int arr[n] = {5,4,16,7,1,67,3,8};
	
	for ( int i = 0 ; i < n-1 ; i++){             // double for loop , Complexity = O(n^2).
		int indexMin = i;
		for (int j = i+1 ; j < n ; j++ ){
			if (arr[j] < arr[indexMin]){
				indexMin = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[indexMin];
		arr[indexMin] = temp;
	}
	
	
	for(int i = 0 ; i < 8 ; i++){
		cout<<arr[i]<<" ";
	}	
	
	return 0;
}
