#include <iostream>
using namespace std;

void interpolationSearch(int *a , int n , int d){
	int s = 0, e = n - 1 , mid;
	
	while (s <= e){
		mid = s + (((e-s)/(a[e] - a[s])) * (d - a[s]));
		if (d == a[mid]){
			cout<<d<<" found at a["<<mid<<"]"<<endl;
			return;
		}
		else if (d < a[mid]){
			e = mid - 1;
		}
		else s = mid + 1;
	}
}

int main(){
	int a[] =  {1,2,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);
	interpolationSearch(a,n,6);
	return 0;
}
