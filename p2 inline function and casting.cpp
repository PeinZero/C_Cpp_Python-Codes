#include <iostream>

using namespace std;

class practice {
	private:
		int x,z;
	public:
		practice (){
			x = 5;
			z = 10;
			cout<<"Null Constructor is called.\n";
			cout<<"X = "<<x<<"\nZ = "<<z<<endl;
		}
		practice (practice &p){
			x = p.x;
			z = p.z;
			cout<<"Copy Constructor is called.\n";
			cout<<"X = "<<x<<"\nZ = "<<z<<endl;			
		}
		 inline int IL2(int a, int b){
			x = a;
			z = b;
			cout<<"IL2 Function is called.\n";
			cout<<"X = "<<x<<"\nZ = "<<z<<endl;
			return 0;
		}
		void IL(int a ,int b);

};

 inline void  practice ::   IL(int a, int b){ 
	cout<<"IL Function is called.\n";
	cout<<"A = "<<a<<"\nB = "<<b<<endl;
}
 int inline cube(int s) 
{ 
    cout<<s*s*s; 
    return 0;
}

int main(){
	float q = 15.0;
	char w = 'd';
	int a,b;
	practice p1;
	practice p2 = p1;
	a = int(q);
	b = (int)w;
	cout<<"IN MAIN\nA = "<<a<<"\nB = "<<b<<endl;
	p1.IL(a,b);	
	p1.IL2(a,b);
	cube(a);
}
