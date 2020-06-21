#include<iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(){
			data = 0;
			next = 0;
			prev = 0;
		}
			
		Node ( int data_ , Node *next_ , Node* prev_){
			data = data_;
			next = next_;
			prev = prev_;
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
				head = new Node(data_ , NULL , NULL);
			}
			else{
				head  = new Node (data_ , head , NULL);
				head->next->prev = head;
			}
		}
		
		void addAtTail (int data_){
			if (head == NULL){
				head = tail = new Node (data_ , NULL , NULL);
			}
			else {
				tail->next = new Node(data_ , NULL , tail);
				tail = tail->next;
			}
		}
		
		void add (int searchedData_ , int data_){
			Node *current = new Node();
			current = head;
			
			while ( current -> data != searchedData_){
				current = current->next;
			}
			Node *newNode =  new Node (data_ , current->next , current);
			current->next = newNode;
		}
		
		void FindingPairs(int sum_){
			int sum = 0;
			bool found = false;
			Node *current1 = new Node;
			Node *current2 = new Node;
			current1 = head;
			
			while (current1 != NULL){
				current2 = head;
				while (current2 != NULL){
					sum = current1->data + current2->data;
					if ( sum == sum_){
						cout<<"("<<current1->data<<", "<<current2->data<<")"<<endl;
						current2= current2->next;
						found = true;
					}
					else{
						sum = 0;
						current2 =  current2->next;
					}
				}
				current1 = current1->next;
			}
			if (found == false){
				cout<<"No Pairs Found."<<endl;
			}
		}
		
		void display(){
			Node *temp = new Node();
			temp = head;
			while (temp != NULL){
				cout<<temp->data<<"\t";	
				temp = temp->next;
				
			}
			cout<<endl<<endl;
		}
};

int main (){
	int num;
	SinglyLinkedList list;
	list.addAtTail(1);
	list.addAtTail(2);
	list.addAtTail(3);
	list.addAtTail(4);
	list.addAtTail(5);
	
	list.display();
	cout<<"Enter a Number: ";
	cin>> num;
	list.FindingPairs(num);
	
	
	return 0;	
}
