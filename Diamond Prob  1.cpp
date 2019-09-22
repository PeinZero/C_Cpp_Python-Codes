#include<iostream> 
using namespace std; 
  
class A 
{ 
  int x; 
public:
	A(){
		cout<<"STUFF"<<endl;
		x++;
	} 
  	A(int i) { x = i; cout<<"A parametrised constructor is called"<<endl; } 
  void print() { cout << x; } 
}; 
  
class B: virtual public A 
{ 
public: 
  B():A(10) { cout<<"B constructor is called"<<endl; } 
}; 
  
class C:  virtual public A  
{ 
public: 
  C():A(20) { cout<<"C constructor is called"<<endl; } 
}; 
  
class D: public B, public C { 
	public:
		D() : A(15) {}
}; 
  
int main() 
{ 
    D d; 
    d.print(); 
    return 0; 
} 
