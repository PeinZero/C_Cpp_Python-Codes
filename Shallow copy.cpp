#include <iostream>

using namespace std;

class construct {
    private:
    	int *clas;
        int *sec ;
		
    public:
        construct (int x=0 , int y=0){
        	clas = new int;
            *clas = y;
        	sec = new int;
            *sec = x;
            
        }

        void display(){
        	
            cout<<"\nThe Pointer Sec points to value: "<<*sec;
            cout<<"\n\nThe Pointer Clas points to value: "<<*clas;
            cout<<"\nThe Pointer Sec value: "<<sec;
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
//    construct a1 = construct (10,10); //explicit call
    construct a1(10,10); //implicit call 
    construct a2=a1;
    cout<<"\n\nObject A1 Address: "<<&a1;
    cout<<"\n\nObject A2 Address: "<<&a2;
    a1.display();
    a2.	display();
    a1.input();
    cout<<"\n\nObject A1 Address: "<<&a1;
    cout<<"\n\nObject A2 Address: "<<&a2;
    a1.display();
    a2.display();
    return 0;
}
