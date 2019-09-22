#include <iostream>
#include <fstream>

using namespace std;

class A{
	public:
		int a ,b;

};

int main(){
	A x;
	x.a = 1;
	x.b = 2;
	
	fstream file;
	file.open("bfile.bin" , ios :: out | ios :: binary );
	file.write((char*)&x,sizeof(x));
	file.close();
	
	A y;
	
	file.open("bfile.bin", ios :: in | ios :: binary);
	file.read((char*)&y,sizeof(y));
	cout<<y.a<<" "<<y.b;
	file.close();
	
	return 0;
}
