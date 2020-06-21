#include <iostream> 
#include <cmath>
using namespace std;

int palindrome(int n , int d , int p){
	if (n%10 == n){
		return (p + ( n * pow(10,d)));
	}
	else
	{
		palindrome(n/10 , d-1 , p + ( (n%10) * pow(10,d) ) ); 
	}
}


int main (){
	int n,p, d=1;
	cin >> n ;
	p = n;
	while ( p/10 != 0){
		d++;
		p = p/10;
	}
	
	p = palindrome (n,d-1,0);
	if (p == n){
		cout<<"Number is Palindrome"<<endl;
	}
	else cout<<"Number is not Palindrome"<<endl;
}
