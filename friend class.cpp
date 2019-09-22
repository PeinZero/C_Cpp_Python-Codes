#include <iostream> 
using namespace std; 

class A{
	int x;
	public:
		void SHOWAX(){
			cout<<"A :: x = "<<x;
		}
		friend class B;
};

class B{
	int b;
	public:
		B (int i){
			b = i;
		}
		void SETAX	(A &obj){
			obj.x = b;
			obj.SHOWAX();
		}
};

int main(){
	A yz;
	B zy(5);
	zy.SETAX(yz);
	return 0 ;
}
