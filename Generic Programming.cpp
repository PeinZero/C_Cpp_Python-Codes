#include <iostream>
#include <cstring>

using namespace std;

template <class T , class T2>

class R{
	public:
		R(T a , T2 b){
			cout<<a+b<<endl;
		}

};

template<>
class R<float,float>
{
		public:
		R(float a,float b){

			cout<<a-b;
		}
};



int main(){
	R <int,double> r(10,0.23);
	R <float,float> r1(1.2,0.2);
} 
