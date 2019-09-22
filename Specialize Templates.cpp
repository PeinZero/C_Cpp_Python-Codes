#include <iostream> 
using namespace std; 

template <class T>
void me(T X){
	cout<<"X = "<<X<<endl;
}

template <>
void me(int X){
	cout<<"INT X = "<<X<<endl;
}
template <>
void me(double X){
	cout<<"Double X = "<<X<<endl;
}

int main(){
	me<char>('a');
	me<int>(5);
	me<double>(69.0);
	return 0;
}
