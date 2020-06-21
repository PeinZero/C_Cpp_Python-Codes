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
				tail->next = new Node(data_ , NULL);
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
			nodeToBeSwapped2->next->next = temp->next;
			
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
				while (current2 != NULL){
					pos2 = pos1 + 1;
					if ( current1->data  > current2->data){
						swap(pos1 , pos2);
						temp->next = current1->next;
						current1 = current2;
						current2 = temp->next;
					}
					else {
						current2 = current2->next;
					}
					pos2++;
				}
				current1 = current1->next;
				pos1++;
			}	
		}
		
		void callSwap(int X , int Y){
			int size = 0;
			Node *current = new Node;
			current = head;
			
			while ( current != NULL){
				size++;
				current = current->next;
			}
			
			if (X <= size && Y<= size && X>0  && Y>0){
				swap(X,size-Y+1);
			}
			
		}
		
		void display(){
			Node *temp = new Node();
			temp = head;
			cout<<endl;
			while (temp !=  NULL){
				cout<<temp->data<<"\t";
				temp = temp->next;
			}
			cout<<endl<<endl;
		}
};

int main (){
	int x , y;
	SinglyLinkedList list;
	list.addAtTail(1);
	list.addAtTail(2);
	list.addAtTail(3);
	list.addAtTail(4);
	list.addAtTail(5);
	
	cout<<"Enter Kth Node from beginning (X): ";
	cin>>x;
	cout<<"Enter Kth Node from ending (Y): ";
	cin>>y;
	
	cout<<endl<<"List befor Swapping: "<<endl;
	list.display();
	list.callSwap(x,y);
	cout<<"List After Swapping: "<<endl;
	list.display();

	return 0;	
}
