#include <iostream>
using namespace std;
void prime(int num, int count, bool prime_check){
	
	if(num % count == 0){
		prime_check = false;
	}
	if(num == 1 || num == 2){
		cout << num << " :is a prime number" << endl;
		return;
	}
	if(count == (num - 1)){
		if(prime_check == false){
			cout << num << " :is not a prime number" << endl;
		}
		else{
			cout << num << " :is a prime number" << endl;
		}
	 	return; 
	}
	prime(num, count+1, prime_check);
}
	
int main(){
	
	int N;
	cout << "Enter when to stop: ";
	cin >> N;
	for(int i = 1; i <= N; i++){
		prime(i, 2, true);
	}
	return 0;
}
