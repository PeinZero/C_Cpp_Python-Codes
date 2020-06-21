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
			if (head == NULL){
				head  = new Node (data_ , NULL);
			}
			else{
				head  = new Node (data_ , head);
			}
		}
		
		void addAtTail(int data_){
			
			if (head == NULL){	
				head = tail  = new Node (data_ , NULL);		
			}
			else{
				tail->next = new Node (data_ , NULL);
				tail = tail->next;
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
		
		deleteHead(){
			Node *temp = head;
			head = head->next;
			delete temp;
		}

		deleteTail(){
			Node *current = new Node();
			current = head;
			
			while (current->next->next != NULL){
				current = current->next;
			}
			
			delete tail;
			tail = current ;
			tail->next = NULL;
		}

		deteteSomewhereFromBetween(int dataToBeDeleted_){
			Node *current = new Node();
			Node *temp;
			
			current = head;
			
			while (current != NULL){
				if (current->next->data == dataToBeDeleted_){
					temp = current->next;
					current->next = current->next->next;
					delete temp;
					break;
				}
			}
		}
		
		void display()
		{
			Node *temp = new Node();
			temp=head;
			while(temp!=NULL)
			{
				if (temp == head){
					cout<<temp->data;
				}
				else cout<<" ----> "<<temp->data;
				temp=temp->next;
			}
			cout<<endl;
		}
	
};
