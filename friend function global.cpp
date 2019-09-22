#include <iostream> 
using namespace std; 

class A{
	int x;
	public:
		void SHOWX(){
			cout<<"A :: x = "<<x;
		}
		friend void SETX(int i , A &obj);
};

void SETX(int i ,A &obj){
	obj.x = i;
}

int main(){
	A yz;
	SETX(5,yz);
	yz.SHOWX();
	return 0 ;
}
