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
				tail->next = head;
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
		
		void addSorted (int data_){
			Node *current = new Node();
			current = head;
			if (current->data > data_){
				addAtHead(data_);
			}
			else if (tail->data < data_){
				addAtTail(data_);
			}
			else 
			{
				while ( current != NULL){
					if (current->data <= data_ && current->next->data >= data_){
						break;
					}
					else current = current->next;
				}	
				
				Node *newNode =  new Node (data_ , current->next);
				current->next = newNode;
			}
			
			
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
	int num ;
	SinglyLinkedList list;
	list.addAtTail(3);
	list.addAtTail(7);
	list.addAtTail(9);
	list.addAtTail(11);
	
	cout<<"Original List: "<<endl;
	list.display();
	cout<<"Enter a number to add to list: ";
	cin>>num;
	list.addSorted(num);
	cout<<endl<<"List After Adding: "<<endl;
	list.display();
	
	return 0;	
}
