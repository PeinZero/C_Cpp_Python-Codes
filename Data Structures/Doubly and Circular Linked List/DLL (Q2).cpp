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
				head = tail = new Node(data_ , NULL , NULL);
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
			newNode->next->prev = newNode;
		}
		
		void swap (int nodeNo1 , int nodeNo2){
			Node *nodeToBeSwapped1 = new Node;
			Node *nodeToBeSwapped2 = new Node;
			Node *temp = new Node;
			
			if (nodeNo1 == 1){
				nodeToBeSwapped1 -> next = head;
			}
			else{
				nodeToBeSwapped1 = head;
				for (int i = 1 ; i < nodeNo1 - 1 ; i++){
					nodeToBeSwapped1 = nodeToBeSwapped1 ->next;
				}
			}
			
			if (nodeNo2 == 1){
				nodeToBeSwapped2->next = head;
			}
			else{
				nodeToBeSwapped2 = head;
				for (int i = 1 ; i < nodeNo2 - 1 ; i++){
					nodeToBeSwapped2 = nodeToBeSwapped2 ->next;
				}
			}
			
			temp->next  = nodeToBeSwapped1->next;
			nodeToBeSwapped1->next =  nodeToBeSwapped2->next ;
			nodeToBeSwapped2->next = temp->next;
			
			temp->next  = nodeToBeSwapped1->next->next;
			nodeToBeSwapped1->next->next =  nodeToBeSwapped2->next->next ;
			nodeToBeSwapped2->next->next = temp->next;;
			
			
			if (nodeNo1 == 1){
				head = nodeToBeSwapped1->next;
			}
			if (nodeNo2 == 1){
				head = nodeToBeSwapped2->next;
			}
		}
		
		void sorting(){
			int pos1 = 1 , pos2 = 0;
			
			Node *current1 = new Node;
			Node *current2 = new Node;
			Node *temp = new Node;
			
			current1 = head;
			
			while (current1 != NULL){
				current2 = current1->next;
				pos2 = pos1 + 1;
				while (current2 != NULL){
					if (current1->data > current2->data){
						swap(pos1, pos2);
						temp->next = current1->next;
						current1 = current2;
						current2 = temp->next;
					}
					else{
						current2 = current2->next;
					}
					pos2++;
				}
				current1 = current1->next;
				pos1++;
			}				
			ResetTailAndPrev();
			
		}
		
		void ResetTailAndPrev(){	
			Node *current = new Node();
			current = head;
			while (current->next != NULL){
				current = current->next;
			}
			tail = current;
			
			current = head;
			while (current != NULL){
				
				if (current == head){
					current->prev = NULL;
					current->next->prev = current;
					current = current->next;
				}

				if (current->next != NULL){
					current->next->prev = current;
					current = current->next;
				}
				else{
					current = current->next;
				}
			}
		}
		
		void display(){
			Node *current = new Node();
			current = head;
			while (current != NULL){
				cout<<current->data<<"\t";	
				current = current->next;
				
			}
			cout<<endl<<endl;
		}
		
		void displayReverse(){
			Node *current = new Node();
			current = tail;
			while (current != head->prev){
				cout<<current->data<<"\t";
				current = current->prev;
			}
			cout<<endl<<endl;
		}
};

int main (){
	SinglyLinkedList list;
	list.addAtTail(11);
	list.addAtTail(10);
	list.addAtTail(9);
	list.addAtTail(8);
	list.addAtTail(5);
	cout<<"List Before Sorting:"<<endl;
	list.display();
	list.sorting();
	cout<<"List After Sorting:"<<endl;
	list.display();
	cout<<"Reverse List After Sorting:"<<endl;
	list.displayReverse();
	
	return 0;	
}
