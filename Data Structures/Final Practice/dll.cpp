#include <iostream>
using namespace std;

class node {
	public:
		int data;
		node *next;
		node *prev;
	
		node(int data_ = 0 , node *next_ = NULL , node *prev_ = NULL){
			data = data_;
			next = next_;
			prev = prev_;
		}
};

class dll{
	public:
		node *head;
		node *tail;
		
		dll(){
			head = new node;
			tail = new node;
			
			head = NULL;
			tail = NULL;
		}
		
		void addtohead(int data){
			if (head == NULL){
				head = tail = new node(data , NULL , NULL);
			}
			else{
				head = new node (data , head , NULL);
				head->next->prev = head;
			}
		}
		
		void addtotail(int data){
			if (head == NULL){
				head = tail = new node(data , NULL , NULL);
			}
			else {
				tail->next = new node (data,NULL,tail);
				tail = tail->next;
			}	
		}
		
		void addinbetween(int sdata , int data){
			if (head == NULL){
				return ;
			}
			else if (tail->data == sdata){
				addtotail(data);
			}
			else{	
				node *temp;
				temp = head;
				while(temp->data != sdata){
					temp = temp->next;
				}
				temp->next = new node(data,temp->next,temp);
				temp->next->next->prev = temp->next;	
			}	
		}
		
		void deletefromhead(){
			if (head == tail){
				delete head;
				head = NULL;
				tail = NULL;
				return;
			}
			else{
				head = head->next;
				delete head->prev;
				head->prev = NULL;
			}
		}
		
		void deletefromtail(){
			if (head == tail){
				delete head;
				head = NULL;
				tail = NULL;
				return;
			}
			else{
				tail = tail->prev;
				delete tail->next;
				tail->next = NULL;
			}
		}
		
		void deleteinbetween(int ddata){
			if (head == NULL){
				delete head;
				return;
			}
			else if(head->data == ddata){
				deletefromhead();
			}
			else if (tail->data == ddata){
				deletefromtail();
			}
			else{
				node *temp = head->next;
				while (temp->data != ddata){
					temp = temp->next;
					if (temp == tail){
						cout<<"data not found"<<endl;
						return;
					}
				}
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
		}
		
		void display(){
			if (head == NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			else{
				node *temp;
				temp = head;
				while (temp != NULL){
					cout<<temp->data<<" ";
					temp = temp->next;
				}
				cout<<endl;
			}
		}
};

int main(){
	dll l1;
	l1.addtohead(5);
	l1.addtohead(4);
	l1.addtotail(7);
	l1.addinbetween(7,8);
	l1.display();
	l1.deletefromhead();
	l1.display();
	l1.deleteinbetween(6);
	l1.display();
	l1.deleteinbetween(5);
	l1.display();
	l1.deleteinbetween(8);
	l1.display();
	l1.deletefromtail();
	l1.display();
	l1.deletefromhead();
	l1.display();
	return 0;
}
