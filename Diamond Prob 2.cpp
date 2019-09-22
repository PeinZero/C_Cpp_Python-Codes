#include <iostream>

using namespace std;

class employee{
	protected:
		string name,code;
		employee(string n , string c):name(n),code(c){}
};

class consultant : virtual protected employee {
	protected:
		int yoe;
	public:
		consultant(string n , string c , int yoex) : employee(n,c) , yoe(yoex){}
			

};

class manager : virtual protected employee{
	protected:
		int noOfteams;
		manager(string n , string c , int team) : employee(n,c) , noOfteams(team){}
};

class consultantmanager : protected consultant ,protected manager{
	public:
		consultantmanager( string n , string c, int yoex , int team) : employee(n,c), manager(n,c,team) , consultant(n,c,yoex){}

		void display() const{
			cout<<"Name: "<<name;
			cout<<"\nCode: "<<code;
			cout<<"\nYears of Experience: "<<yoe;
			cout<<"\nNo of Teams: "<<noOfteams;
		}
};

int main(){
	consultantmanager obj("Ali","S-123",17,5);
	obj.display();
	return 0;
}
