#include <iostream>
#include <cmath>
using namespace std;

int armstrong (int num , int sum ){
	const int digits = 3;
	if ( num == num%10){
		return sum + pow(num%10,3);
	}
	else{
		armstrong (num/10 , (sum + pow(num%10,3)) );
	}
}

int main() {
	int num,num2;
	cin>>num;
	num2 = armstrong(num,0);
	if (num ==  num2){
		cout<<"Number is armstrong"<<endl;
	}
	else cout<<"Number is Not armstrong"<<endl;
}
