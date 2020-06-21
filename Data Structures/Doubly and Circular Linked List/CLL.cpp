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
	public:
			Node* head;
			Node* tail;
	
		SinglyLinkedList(){
			head = new Node;
			tail = new Node;
			
			head = NULL;
			tail = NULL;
		}
		
		void addAtHead ( int data_){
			if (head == NULL){
				head = tail = new Node(data_ , NULL);
				tail->next = head;
			}
			else{
				head  = new Node (data_ , head);
				tail->next = head;
			}
		}
		
		void addAtTail (int data_){
			if (head == NULL){
				head = tail = new Node (data_ , NULL);
				tail->next = head;
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
	list.addAtHead(5);
	list.addAtTail(14);
	list.addAtTail(13);
	list.addAtTail(9);
	list.addAtTail(10);
	list.addAtTail(7);
	list.addAtTail(8);
	
	cout<<"Original List: "<<endl;
	list.display();
	cout<<list.tail->next->data;
	
	
	return 0;	
}
