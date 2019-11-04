#include <iostream>
using namespace std;

void combSort(int *arr, int n) 
{ 
    // Initialize gap 
    int gap = n; 
  
    // Initialize swapped as true to make sure that 
    // loop runs 
    bool swapped = true; 
  
    // Keep running while gap is more than 1 and last 
    // iteration caused a swap 
    while (gap != 1 || swapped == true) 
    { 
        // Find next gap 
        gap = (gap*10)/13;
        if (gap < 1){
        	gap = 1;
		}
  
        // Initialize swapped as false so that we can 
        // check if swap happened or not 
        swapped = false; 
  
        // Compare all elements with current gap 
        for (int i=0; i<n-gap; i++) 
        { 
            if (arr[i] > arr[i+gap]) 
            { 
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] =  temp;
                swapped = true; 
            } 
        } 
    } 
} 

int main() 
{ 
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    combSort(arr, n); 
  
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
	}
    return 0; 
}
