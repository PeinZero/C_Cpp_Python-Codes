#include <iostream>
using namespace std;

void display(int *arr , int n){
	
	for(int i = 0 ; i < 8 ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	
	int arr[] = {9,8,7,6,5,4,3,2};
	int n = 8 , i , j ;
	int gap = n/2;
	display(arr,n);
	
    while(gap > 0) {                     // improved version of insertion sort , time Complexity = O(n^2)
    	cout<<"GAP = "<<gap<<endl;
		i = gap;
		
		while(i < n) {
			
      		int temp = arr[i];
      		j = i;
//      		if ( (j>= gap) && (arr[j-gap] > temp) ){
//      			arr[j] = arr[j-gap];
//				 j = j - gap;	
//			}
      		
	      	for(j = i; (j >= gap) && (arr[j - gap] > temp); j -=gap) {
	       	 	arr[j] = arr[j - gap];
			}
			
     		arr[j] = temp;
     		i++;
     		display(arr,n);
	 	}
    
	gap = gap / 2;							
	}	

	
return 0;
}
