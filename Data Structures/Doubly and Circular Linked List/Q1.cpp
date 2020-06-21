#include<iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
		
		Node(){
			data = 0;
			next = 0;
		}
			
		Node ( int data_ , Node *next_){
			data = data_;
			next = next_;
		}
};

class SinglyLinkedList{
	private:
			Node* head;
			Node* tail;
	
	public:
		SinglyLinkedList(){
			head = new Node;
			tail = new Node;
			
			head = NULL;
			tail = NULL;
		}
		
		void addAtHead ( int data_){
			if (head == NULL){
				head = new Node(data_ , NULL);
			}
			else{
				head  = new Node (data_ , head);
			}
		}
		
		void addAtTail (int data_){
			if (head == NULL){
				head = tail = new Node (data_ , NULL);
			}
			else {
				tail->next = new Node(data_ , head);
				tail = tail->next;
			}
		}
		
		void add (int searchedData_ , int data_){
			Node *current = new Node();
			current = head;
			
			while ( current -> data != searchedData_){
				current = current->next;
			}
			Node *newNode =  new Node (data_ , current->next);
			current->next = newNode;
		}
		
		void EvenOdd(){
			SinglyLinkedList list2;
			Node *current = new Node;
			current = head;
			
			if(current->data % 2 == 0){
					list2.addAtTail(current->data);
			}
			
			while ( current->next != head){
				current = current->next;
				if(current->data % 2 == 0){
					list2.addAtTail(current->data);
				}
			}
			
			current = head;
			if(current->data % 2 != 0){
					list2.addAtTail(current->data);
			}
			
			while ( current->next != head){
				current = current->next;
				if(current->data % 2 != 0){
					list2.addAtTail(current->data);
				}
			}
			
			list2.display();
		}
		
		void display(){
			Node *temp = new Node();
			temp = head;
			cout<<temp->data<<"\t";
			while (temp->next !=  head){	
				temp = temp->next;
				cout<<temp->data<<"\t";
			}
			cout<<endl<<endl;
		}
};

int main (){
	SinglyLinkedList list;
	list.addAtTail(11);
	list.addAtTail(14);
	list.addAtTail(13);
	list.addAtTail(9);
	list.addAtTail(10);
	list.addAtTail(7);
	list.addAtTail(8);
	
	cout<<"Original List: "<<endl;
	list.display();
	cout<<"List (Even First Odd Later): "<<endl;
	list.EvenOdd();
	
	return 0;	
}
