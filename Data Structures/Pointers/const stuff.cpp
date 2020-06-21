#include <iostream>

using namespace std;

main(){
	int y = 10,x=2;
	const int  *  p = &y ;
	p = &x;
	cout<<*p;
	
}
