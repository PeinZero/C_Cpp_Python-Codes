#include <iostream>

using namespace std;

class construct {
    private:
    	int *sec ;
    	int *clas;
        
		
    public:
        construct (int x , int y){
        	clas = new int;
            *clas = y;
        	sec = new int;
            *sec = x;
            
        }
        
		construct (construct &a){
        	clas = new int;
            *clas = *a.clas;
        	sec = new int;
            *sec = *a.sec;
            
        }
        
//        ~ construct(){
////        	delete sec;
////        	delete clas;
//        	cout<<"\n\nDestructor has been called\n\n";
//		}
        void display(){
        	
            cout<<"\n\nThe Pointer Sec points to value: "<<*sec;
            cout<<"\n\nThe Pointer Clas points to value: "<<*clas;
            cout<<"\n\nThe Pointer Sec value: "<<sec;
            cout<<"\n\nThe Pointer Clas value: "<<clas;
            cout<<"\n\nThe Address of Pointer Sec: "<<&sec;
            cout<<"\n\nThe Address of Pointer Clas: "<<&clas;
        }
        void input(){
        	cout<<"\n\nEnter value of x: ";
        	cin>>*sec;
        	cout<<"\n\nEnter value of y: ";
        	cin>>*clas;
            
        }
};

int main()
{
    construct a1(10,10);
    construct a2 = a1 ;
    cout<<"\n\nObject A1 Address: "<<&a1;
    a1.display();
	cout<<"\n\nObject A2 Address: "<<&a2;
    a2.	display();
    a1.input();
//    a2.~construct();
    cout<<"\n\nObject A1 Address: "<<&a1;
    a1.display();
    cout<<"\n\nObject A2 Address: "<<&a2;
    a2.display();
    return 0;
}
