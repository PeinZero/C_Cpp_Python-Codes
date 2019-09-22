#include <iostream> 
using namespace std; 

class B;
class A{
	int x;
	public:
		void SHOWAX(B &obj1);

};

class B{
	int b;
	public:
		B (int i){
			b = i;
		}

		
		friend void A :: SHOWAX(B &obj1);
};

void A :: SHOWAX(B &obj1){
	cout<<"A::x = "<<obj1.b;
}

int main(){
	A yz;
	B zy(5);
	yz.SHOWAX(zy);
	return 0 ;
}
