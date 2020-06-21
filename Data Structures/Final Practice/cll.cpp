#include <iostream>
using namespace std;

class node {
	public:
		int data;
		node *next;
	
		node(int data_ = 0 , node *next_ = NULL){
			data = data_;
			next = next_;
		}
};

class cll{
	public:
		node *head;
		node *tail;
		
		cll(){
			head = new node;
			tail = new node;
			
			head = NULL;
			tail = NULL;
		}
		
		void addtohead(int data){
			if (head == NULL){
				head = tail = new node(data , NULL);
				tail->next = head;
			}
			else{
				head = new node (data , head);
				tail->next = head;
			}
		}
		
		void addtotail(int data){
			if (head == NULL){
				head = tail = new node(data , head);
			}
			else {
				tail->next = new node (data , head);
				tail = tail->next;
			}
		}
		
		void addinbetween(int sdata , int data){
			if (head == NULL){
				return ;
			}
			else if (tail->data == sdata){
				addtotail(sdata);
			}
			else{	
				node *temp;
				temp = head;
				while(temp->data != sdata){
					temp = temp->next;
				}
				temp->next = new node(data,temp->next);	
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
				node *temp = head;
				head = head->next;
				tail->next = head;
				delete temp;
				temp = NULL;
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
				node *temp = head;
				while (temp->next != tail){
					temp = temp->next;
				}
				delete temp->next;
				temp->next = head;
				tail = temp;
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
				node *temp = head;
				while (temp->next->data != ddata){
					temp = temp->next;
					if (temp->next == tail){
						cout<<"data not found"<<endl;
						return;
					}
				}
				temp->next = temp->next->next;
			}
		}
		
		void display(){
			if (head == NULL){
				
				return;
			}
			else{
				node *temp = head->next;
				cout<<head->data<<" ";
				while (temp != head){
					cout<<temp->data<<" ";
					temp = temp->next;
				}
				cout<<endl;
			}
		}
};

int main(){
	cll l1;
	l1.addtohead(5);
	l1.addtohead(4);
	l1.addtotail(7);
	l1.addinbetween(5,6);
	l1.display();
	l1.deletefromhead();
	l1.display();
	l1.deleteinbetween(6);
	l1.display();
	l1.deletefromtail();
	l1.display();
	l1.deletefromhead();
	l1.display();
	l1.deletefromtail();
	l1.display();
	return 0;
}
