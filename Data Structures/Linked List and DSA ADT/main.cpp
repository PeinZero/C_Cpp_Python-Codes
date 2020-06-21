#include "linkedlist.hpp"
#include "dsa.hpp"

int main(){
	SinglyLinkedList <int> sll;
	CircularLinkedList <float> cll;
	DoublyLinkedList <char> dll;
	
	cout<<"Checking Some SLL mehtods: "<<endl;
	// all the member functions in the image have also been implemented and tested.
	sll.addAtHead(8);
	sll.addAtTail(9);
	sll.add(8,11);
	sll.add(11,10);
	sll.sorting();
	sll.display();
	sll.deleteTail();
	sll.deteteSomewhereFromBetween(9);
	sll.display();
	
	Node <int> *a = sll.head;
	sll.insert(a,3,7);
	sll.display();
	
	Node <int> *b = sll.head->next;
	sll.erase(b);
	sll.display();
	
	cout<<"Checking CLL mehtods: "<<endl;
	cll.addAtHeadC(1.5);
	cll.addAtTailC(6.9);
	cll.addAtHeadC(0.7);
	cll.addC(1.5,3.2);
	cll.deleteTailC();
	cll.deteteSomewhereFromBetweenC(1.5);
	cll.displayC();
	
	cout<<"Checking CLL mehtods: "<<endl;
	dll.addAtHeadD('y');
	dll.addAtTailD('u');
	dll.addD('y' , 'z');
	dll.sortingD();
	dll.displayD();
	dll.deleteTailD();
	dll.deteteSomewhereFromBetweenD('u');
	dll.displayD();
	
/****************************************Dynamic Safe Array ******************************************************/	

	DynamicSafeArray <char> d1(5),d2(5);
	DynamicSafeArray <char> d3 = d1;
	d1 = d2;
	
	return 0;
}
