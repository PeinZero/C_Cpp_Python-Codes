#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(){
			
			data = 0;
			next = 0;
		}
		
		Node(int data_ , Node* next_){
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
			
			head = new Node();
			tail = new Node();
			
			head = NULL;
			tail = NULL;
		}
		
		
		void addAtHead(int data_){
			Node* newNode = new Node(data_,head);
			head = newNode;
		}
		
		void addAtTail(int data_){
			Node* newNode = new Node(data_,0);
			
			if (head == NULL){
				head = newNode;
				tail = newNode;
				newNode = 0;			
			}
			else{
				tail->next = newNode;
				tail = newNode;
			}
		}
		
		void add(int searchedData_ , int data_){
			Node* current = new Node();
			
			
			current = head;
			
			while(current->data != searchedData_){
				current = current->next;
			}
			
			Node* newNode = new Node(data_,current->next);
			current->next = newNode;
		}
		
		deleteAtHead(){	
		}
		deleteAtTail(){
		}
		deleteInBetween(){
		}
		
		search(){
		}
		
		void display()
		{
			Node *temp = new Node();
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
		}
	
};

int main(){
	SinglyLinkedList obj;
	obj.addAtTail(1);
	obj.addAtTail(2);
	obj.addAtTail(3);
	cout<<"Linked Link Created\n";
	obj.display();
	cout<<endl;
	cout<<"\n4 added between 2 and 3\n";
	obj.add(2,4);
	obj.display();
	cout<<endl;
	cout<<"\n5 added at Start\n";
	obj.addAtHead(5);
	obj.display();
	return 0;
}
