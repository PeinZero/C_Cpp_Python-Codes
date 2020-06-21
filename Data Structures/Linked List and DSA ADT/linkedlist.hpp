#include <iostream>
using namespace std;

template <typename S> 

class Node{
	public:
		S data;
		Node* next;
		
		Node(){
			
			data = 0;
			next = 0;
		}
		
		Node(S data_ , Node* next_){
			data = data_;
			next = next_;
		}
};

template <typename S> 

class SinglyLinkedList{
	public:
		Node <S> *head;
		Node <S> *tail;
			
		SinglyLinkedList(){
			head = new Node <S> ();
			tail = new Node <S> ();
			
			head = NULL;
			tail = NULL;
		}
		
		SinglyLinkedList(int size, const S& e1 = 0){
			head = new Node <S> ();
			tail = new Node <S> ();
			
			head = NULL;
			tail = NULL;
			
			int count = 0;
			while(count < size){
				addAtTail(e1);
			}
		}
		
		SinglyLinkedList(Node <S> *first, Node <S> *last){
			head = new Node <S> ();
			tail = new Node <S> ();
			
			head = NULL;
			tail = NULL;
			
			while(first != last->next){
				addAtTail(first->data);
				first = first->next;
			}
		}
		
		void addAtHead (S data_){
			if (head == NULL){
				head  = tail = new Node <S> (data_ , NULL);
			}
			else{
				head  = tail = new Node <S> (data_ , head);
			}
		}
		
		void addAtTail (S data_){
			
			if (head == NULL){	
				head = tail  = new Node <S> (data_ , NULL);		
			}
			else{
				tail->next = new Node <S> (data_ , NULL);
				tail = tail->next;
			}
		}
		
		void add (S searchedData_ , S data_){
			Node <S> *current = new Node <S> ();
			current = head;
			
			while(current->data != searchedData_ ){
				if (current->next == NULL){
					cout<<"Data not found!"<<endl;
					return;
				}
				current = current->next;
			}
			
			Node <S> *newNode = new Node <S> (data_,current->next);
			current->next = newNode;
		}
		
		void swap (S nodeNo1 , S nodeNo2){
			Node <S> *nodeToBeSwapped1 = new Node <S>;
			Node <S> *nodeToBeSwapped2 = new Node <S>;
			Node <S> *temp = new Node <S>;
			
			if (nodeNo1 == 1){
				nodeToBeSwapped1->next = head;
			}
			else{
				nodeToBeSwapped1 = head;
				for (int i = 1 ; i < nodeNo1-1 ; i++){
					nodeToBeSwapped1 = nodeToBeSwapped1->next;
				}
			}
			
			if (nodeNo2 == 1){
				nodeToBeSwapped2->next = head;
			}
			else{
				nodeToBeSwapped2 = head;
				for (int i = 1 ; i < nodeNo2-1 ; i++){
					nodeToBeSwapped2 = nodeToBeSwapped2->next;
				}
			}
	
			temp->next = nodeToBeSwapped1->next;
			nodeToBeSwapped1->next = nodeToBeSwapped2->next;
			nodeToBeSwapped2->next = temp->next;
			
			temp->next = nodeToBeSwapped1->next->next;
			nodeToBeSwapped1->next->next = nodeToBeSwapped2->next->next;
			nodeToBeSwapped2->next->next = temp->next;
			
			if (nodeNo1 == 1){
				head = nodeToBeSwapped1->next;
			}
			if (nodeNo2 == 1){
				head = nodeToBeSwapped2->next;
			}	
		}
		
		void sorting (){
			int pos1 = 1 , pos2 = 0;
			
			Node <S> *current1 = new Node <S>;
			Node <S> *current2 = new Node <S>;
			Node <S> *temp = new Node <S>;
			
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
			ResetTail();			
		}
		
		void ResetTail(){
			Node <S> *temp = head;
			while (temp->next != NULL){
				temp = temp->next;
			}
			tail = temp;	
		}
		
		void deleteHead (){
			Node <S> *temp = head;
			head = head->next;
			delete temp;
		}

		void deleteTail (){
			Node <S> *current = new Node <S>;
			current = head;
			
			while (current->next->next != NULL){
				current = current->next;
			}
			
			delete tail;
			tail = current ;
			tail->next = NULL;
		}

		void deteteSomewhereFromBetween (S dataToBeDeleted_){
			Node <S> *current = new Node <S>;
			Node <S> *temp;
			
			current = head;
			
			while (current->next != NULL){
				if (head->data == dataToBeDeleted_){
					deleteHead();
					break;
				}
				else if (current->next->data == dataToBeDeleted_){
					temp = current->next;
					if (current->next->next == NULL){
						current->next = NULL;
						delete temp;
						break;
					}
					current->next = current->next->next;
					delete temp;
					break;
				}
				current = current->next;
			}
		}
		
		void assign(const Node<S> *first, const Node<S> *last){
			head = tail = NULL;
			while(first != last->next){
				addAtTail(first->data);
				first = first->next;
			}
		}
		
		void assign(int n, const S& e1 = 0){
			int count = 0;
			head = tail = NULL;
			while(count < n){
				addAtTail(e1);
				count++;
			}
		}
		S& back(){
			return tail->data;
		}
		
		const S& back() const{
			return tail->data;
		}
		
		Node <S>* begin(){
			return head;
		}
		
		const Node <S>* begin() const{
			return head;
		}
		
		void clear(){
			head = tail = NULL;
		}
		
		bool empty() const{
			if(head == NULL){
				return true;
			}
			return false;
		}	
		
		Node <S>* end(){
			return tail;
		}
		
		const Node <S>* end() const{
			return tail;
		}
		
		
		Node <S>* erase (Node <S>* i){
			if (head == NULL){
				return NULL;
			}
			else if(i == tail){
			 	deleteTail();
			 	return NULL;
			}
			else if(i == head){
				i =  head->next;
			 	deleteHead();
			 	return i;
			}
			else{
				Node <S> *current = new Node <S> ;
				current = head;
				while (current->next != i && current != tail){
					current = current->next;
				}
				current->next = current->next->next;
				return current->next;
			}
		}
		
		Node <S>* erase (Node <S>* first, Node <S>* last){
			if(head==NULL){
				return NULL;
			}
			else if(first == head && last == tail){
				head = tail = NULL;
				return NULL;
			}
			else if(first == head){
				while (first != last->next){
					deleteHead();
					first = first->next;
				}
				return head;
			}
			else{
				Node <S> *current = new Node <S>;
				current = head;
				while (current->next != first){
					current = current->next;
				}
				
				if (last == tail){
					current->next = NULL;
					return NULL;
				}
				else{
					current->next = last->next;
				}
				
				return current->next;
			}
		}
		
		S& front(){
			return head->data;
		}
		
		const S& front() const{
			return head->data;
		}
		
		Node <S>* insert(Node <S> *i = NULL, const S& e1 = 0){
			if(i == head){
				addAtHead(e1);
				i = head;
			}

			else{
				Node <S> *current = new Node <S>;
				current = head;
				while (current != tail && current->next != i ){
					current = current->next;
				}
				current->next = new Node <S> (e1 , current->next);
				i = current->next;
			}
			return i;
		}
		
		void insert (Node <S> *i = NULL, int n = 0, const S& e1 = 0){
			if(i == head){
				for (int x = 1 ; x <= n ; x++){
					addAtHead(e1);
				}
			}

			else{
				Node <S> *current = new Node <S>;
				current = head;
				while (current != tail && current->next != i ){
					current = current->next;
				}
				for (int x = 1 ; x <= n ; x++){
					current->next = new Node <S> (e1 , current->next);
					current = current->next;
				}
			}
		}
		
		void insert (Node <S> *i = NULL, Node <S> *first = NULL, Node <S> *last = NULL){
			Node <S> *current = new Node <S>;
			
			if(i == head){
				addAtHead(first->data);
				first = first->next;
				current = head->next;
				while (first != last->next){
					current->next = new Node <S> (first->data , current->next);
					first = first->next;
					current = current->next;
				}
			}
			else{
				current = head;
				while (current != tail && current->next != i ){
					current = current->next;
				}
				while (first != last->next){
					current->next = new Node <S> (first->data , current->next);
					first = first->next;
					current = current->next;
				}
			}
		}
		
	
		void display ()
		{
			Node <S> *temp = new Node <S> ;
			temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<endl<<endl;
		}
};

/******************************************Circular Linked List**************************************************/
/*--------------------------------------------------------------------------------------------------------------*/

template <typename C> 

class NodeC{
	public:
		C data;
		NodeC* next;
		
		NodeC(){
			
			data = 0;
			next = 0;
		}
		
		NodeC(C data_ , NodeC* next_){
			data = data_;
			next = next_;
		}
};

template <typename C> 

class CircularLinkedList{
	public:
		NodeC <C> *head;
		NodeC <C> *tail;
			
		CircularLinkedList(){
			
			head = new NodeC <C> ();
			tail = new NodeC <C> ();
			
			head = NULL;
			tail = NULL;
		}
		
		void addAtHeadC (C data_){
			if (head == NULL){
				head = tail = new NodeC <C> (data_ , NULL);
				tail->next = head;
			}
			else{
				head  = new NodeC <C> (data_ , head);
				tail->next = head;
			}
		}
		
		void addAtTailC (C data_){
			if (head == NULL){
				head = new NodeC <C> (data_ , NULL);
				tail = head;
				tail->next = head;
			}
			else {
				tail->next = new NodeC <C> (data_ , head);
				tail = tail->next;
			}
		}
		
		void addC (C searchedData_ , C data_){
			NodeC  <C> *current = new NodeC  <C> ();
			current = head;
			
			while ( current -> data != searchedData_){
				if (current->next == NULL){
					cout<<"Data not found!"<<endl;
					return;
				}
				current = current->next;
			}
			NodeC <C> *newNode =  new NodeC <C> (data_ , current->next);
			current->next = newNode;
		}
		
		void deleteHeadC (){
			NodeC <C> *temp = head;
			head = head->next;
			delete temp;
		}

		void deleteTailC (){
			NodeC <C> *current = new NodeC <C>();
			current = head;
			
			while (current->next->next != head){
				current = current->next;
			}
			
			delete tail;
			tail = current ;
			tail->next = head;
		}

		void deteteSomewhereFromBetweenC (C dataToBeDeleted_){
			NodeC <C> *current = new NodeC <C> ();
			NodeC <C> *temp;
			
			current = head;
			
			while (current->next != NULL){
				if (head->data == dataToBeDeleted_ ){
					deleteHeadC();
					break;
				}
				else if (current->next->data == dataToBeDeleted_){
					if (current->next->next == head){
						current->next =  head;
						break;
					}
					temp = current->next;
					current->next = current->next->next;
					delete temp;
					break;
				}
				current = current->next;
			}
		}
			
		void displayC (){
			NodeC  <C> *temp = new NodeC <C> ();
			temp = head;
			cout<<temp->data<<"\t";
			while (temp->next !=  head){	
				temp = temp->next;
				cout<<temp->data<<"\t";
			}
			cout<<endl<<endl;
		}
};

/******************************************Doubly Linked List**************************************************/
/*--------------------------------------------------------------------------------------------------------------*/


template < typename D >

class NodeD {
	public:
		D data;
		NodeD* next;
		NodeD* prev;
		
		NodeD(){
			data = 0;
			next = 0;
			prev = 0;
		}
			
		NodeD ( D data_ , NodeD *next_ , NodeD* prev_){
			data = data_;
			next = next_;
			prev = prev_;
		}
};

template < typename D >

class DoublyLinkedList{
	private:
			NodeD <D> *head;
			NodeD <D> *tail;
	
	public:
		DoublyLinkedList(){
			head = new NodeD <D> ;
			tail = new NodeD <D> ;
			
			head = NULL;
			tail = NULL;
		}
		
		void addAtHeadD ( D data_){
			if (head == NULL){
				head = tail = new NodeD <D> (data_ , NULL , NULL);
			}
			else{
				head  = new NodeD <D> (data_ , head , NULL);
				head->next->prev = head;
			}
		}
		
		void addAtTailD (D data_){
			if (head == NULL){
				head = tail = new NodeD <D> (data_ , NULL , NULL);
			}
			else {
				tail->next = new NodeD <D> (data_ , NULL , tail);
				tail = tail->next;
			}
		}
		
		void addD (D searchedData_ , D data_){
			NodeD <D> *current = new NodeD <D> ();
			current = head;
			
			while ( current -> data != searchedData_){
				if (current->next == NULL){
					cout<<"Data not found!"<<endl;
					return;
				}
				current = current->next;
			}
			NodeD <D> *newNode =  new NodeD <D>  (data_ , current->next , current);
			current->next = newNode;
			newNode->next->prev = newNode;
		}
		
		void swapD (D nodeNo1 , D nodeNo2){
			NodeD <D> *nodeToBeSwapped1 = new NodeD <D> ;
			NodeD <D> *nodeToBeSwapped2 = new NodeD <D> ;
			NodeD <D> *temp = new NodeD <D> ;
			
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
		
		void sortingD(){
			int pos1 = 1 , pos2 = 0;
			
			NodeD <D> *current1 = new NodeD <D> ;
			NodeD <D> *current2 = new NodeD <D> ;
			NodeD <D> *temp = new NodeD <D> ;
			
			current1 = head;
			
			while (current1 != NULL){
				current2 = current1->next;
				pos2 = pos1 + 1;
				while (current2 != NULL){
					if (current1->data > current2->data){
						swapD(pos1, pos2);
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
			NodeD <D> *current = new NodeD <D> ();
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
		
		void deleteHeadD (){
			NodeD <D> *temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
		}

		void deleteTailD (){
			NodeD <D> *current = new NodeD <D> ();
			current = head;
			
			while (current->next->next != NULL){
				current = current->next;
			}
			
			delete tail;
			tail = current ;
			tail->next = NULL;
		}
		
		void deteteSomewhereFromBetweenD (D dataToBeDeleted_){
			NodeD <D> *current = new NodeD <D> ();
			NodeD <D> *temp;
			
			current = head;
			
			while (current->next != NULL){
				if (head->data == dataToBeDeleted_){
					deleteHeadD();
					break;
				}
				else if (current->next->data == dataToBeDeleted_){
					temp = current->next;
					if (current->next->next == NULL){
						current->next = NULL;
						delete temp;
						break;
					}
					current->next = current->next->next;
					current->next->prev = current;
					break;
				}
				current = current->next;
			}
		}
		
		void displayD(){
			NodeD <D>  *current = new NodeD <D> ();
			current = head;
			while (current != NULL){
				cout<<current->data<<"\t";	
				current = current->next;
				
			}
			cout<<endl<<endl;
		}
		
		void displayReverse(){
			NodeD <D> *current = new NodeD <D> ();
			current = tail;
			while (current != head->prev){
				cout<<current->data<<"\t";
				current = current->prev;
			}
			cout<<endl<<endl;
		}
};

