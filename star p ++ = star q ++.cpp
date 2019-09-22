#include <iostream>
using namespace std;

main(){
	int arr[] = {1,2,3,4,5};
	int *pa,*pb;
	pa = &arr[0];
	pb = &arr[1];
	cout<<"before\n"<<*pa<<endl<<*pb<<endl;
	*pa++ = *pb++;
	cout<<"after\n"<<pa<<endl<<pb<<endl;
	
}
