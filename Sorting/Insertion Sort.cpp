#include <iostream>
using namespace std;

int main(){
	
	int arr[] = {5,4,16,7,1,67,3,8};
	int n = 8;
	
	for (int i  = 1 ; i < n ; i++){					 // this loop for (n-1) times.
		int temp = arr[i];
		int j = i;
		while (j > 0 && arr[j-1] > temp){              // for best case, this loop is nt used. so for best case complexity in O(n) .
			arr[j] = arr[j-1];							// for worst case, this loop will be used for  [ n(n-1)/2 ] times
			j--;
		}
		arr[j] = temp;						// so for worse case , complexity is (n-1) + (n^2/2 - n/2) =  n^2/2 + n/2 -1 = O(n^2).
	}										// same for average case O(n^2) , but still less comparisons than selection and bubblesort.
											
	for(int i = 0 ; i < 8 ; i++){
		cout<<arr[i]<<" ";
	}
return 0;
}
