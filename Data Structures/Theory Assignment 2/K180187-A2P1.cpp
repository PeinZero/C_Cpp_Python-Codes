#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct term {
	int co_efficient;
	char base;
	int exponent;
};

class Node{
	public:
		
		term data;
		Node* next;
		
		Node(){
			
			data.co_efficient = 0;
			data.base = '0';
			data.exponent = 0;
			next = 0;
		}
		
		Node(int co_efficient_ , char base_ , int exponent_ , Node* next_){
			data.co_efficient = co_efficient_;
			data.base = base_;
			data.exponent = exponent_;
			next = next_;
		}
};

class SinglyLinkedList{
	public:
			Node* head;
			Node* tail;
			
		SinglyLinkedList(){
			
			head = new Node();
			tail = new Node();
			
			head = NULL;
			tail = NULL;
		}
		
		
		void addAtHead(int co_efficient_ , char base_ , int exponent_ ){
			if (head == NULL){
				head  = new Node (co_efficient_ , base_ , exponent_, NULL);
			}
			else{
				head  = new Node (co_efficient_ , base_ , exponent_, head);
			}
		}
		
		void addAtTail(int co_efficient_ , char base_ , int exponent_ ){
			
			if (head == NULL){	
				head = tail  = new Node (co_efficient_ , base_ , exponent_, NULL);		
			}
			else{
				tail->next = new Node (co_efficient_ , base_ , exponent_, NULL);
				tail = tail->next;
			}
		}		
		
		void display()
		{
			Node *temp = new Node();
			temp=head;
			while(temp!=NULL)
			{
				if (temp->data.exponent > -1) {
					cout<<temp->data.co_efficient<<temp->data.base<<temp->data.exponent<<" ";
				}
					temp=temp->next;
			}
			cout<<endl;
		}
	
};

void ExtractingString(SinglyLinkedList &list , string equation){
	
	char charBase;
	string strCo_efficient = "+" , strExponent;
	int multiplier , co_efficient , exponent , lenght = 0;
	bool beforeBase = true , isConstant = true , nextExponent = false;;
	
	for (int i = 0 ; equation[i] != '\0' ; i++){
		
		if (equation[i] != '='){
			
			if (beforeBase == true && (equation[i] != 'X' && equation[i] != '^') ){
				if ( equation[i] == '-'){
					strCo_efficient = "\0";
					strCo_efficient = "-";
					continue;
				}	
				strCo_efficient = strCo_efficient + equation[i];
				continue;	
			}
	
			if (equation[i] == 'X'){
				if (strCo_efficient == "+" || strCo_efficient == "-"){
					strCo_efficient = strCo_efficient + '1';
				}
				beforeBase = false;
				charBase = equation[i];
				continue;
			}

			if (equation[i] == '^' && beforeBase == false){
				nextExponent = true;
				continue;
			}
			
			if (nextExponent == true && ( equation[i] != '+' && equation[i] != '-') ){
				strExponent = strExponent + equation[i];
				continue;
			}
		}
		
		if (equation[i] == '+' || equation[i] == '-' || equation[i] == '=' ){
			beforeBase = true;
			nextExponent = false;
			
			co_efficient =  atoi( strCo_efficient.c_str() );
			exponent =  atoi( strExponent.c_str() );

			list.addAtTail(co_efficient,'X',exponent);
			
			strCo_efficient = "\0";
			strCo_efficient = equation[i];
			strExponent = "\0";
		}
		
	}
	
}

void PolynomialAddition(SinglyLinkedList &list1 , SinglyLinkedList &list2 , SinglyLinkedList &list3){
	Node *current1 = new Node;
	Node *current2 = new Node;
	
	current1 = list1.head;
	current2 = list2.head;
	
	while (current1 != NULL || current2 != NULL){
		
		if (current1 == NULL){
			list3.addAtTail(current2->data.co_efficient , 'X' , current2->data.exponent);
			current2 = current2->next;
			continue;
		}
		else if (current2 == NULL){
			list3.addAtTail(current1->data.co_efficient , 'X' , current1->data.exponent);
			current1 = current1->next;
			continue;
		}

		if (current1->data.exponent > current2->data.exponent){
			list3.addAtTail(current1->data.co_efficient , 'X' , current1->data.exponent);
			current1 = current1->next;
		}
		else if (current1->data.exponent < current2->data.exponent){
			list3.addAtTail(current2->data.co_efficient , 'X' , current2->data.exponent);
			current2 = current2->next;
		}
		else if (current1->data.exponent == current2->data.exponent){
			list3.addAtTail(current1->data.co_efficient + current2->data.co_efficient , 'X' , current1->data.exponent);
			current1 = current1->next;
			current2 = current2->next;
		}
	}
}

void PolynomialDifferentiation(SinglyLinkedList &list){
	Node *current = new Node;
	current = list.head;
	
	while (current != NULL){
		current->data.co_efficient = current->data.co_efficient * current->data.exponent;
		current->data.exponent--;
		current = current->next;
	}
}

void OutputInFile(SinglyLinkedList &list , int whichFile ){
	fstream file;
	if (whichFile == 2){
		file.open("OutputP1_Differentiation.txt" , ios::out);
	}
	else file.open("OutputP1.txt" , ios::out);
	
	Node *current = new Node;
	current = list.head;
	
	while (current != NULL){
		
		if (current == list.head){
			file<<current->data.co_efficient;
		}
		else
		{
			if (current->data.co_efficient > 0){
				
				if (current->data.co_efficient == 1){
					file<<"+";
				}
				else file<<"+"<<current->data.co_efficient;
			}
			
			else if (current->data.co_efficient == 0){
				current = current->next;
				continue;
			}
			else
			{	
				if (current->data.co_efficient == -1){
					file<<"-";
				}
				else file<<current->data.co_efficient;
			} 
		}
		
		file<<current->data.base<<"^";
		if (current->data.exponent >= 0){
			file<<current->data.exponent;
		}
		current = current->next;
	}
	
	file<<"=0";
}

int main(){
	SinglyLinkedList list1,list2,list3,list4;
	fstream file;
	string equation;
	
	file.open("InputP1.txt" , ios::in);
		file>>equation;
		ExtractingString (list1 , equation);
		file>>equation;
		ExtractingString (list2 , equation);
	file.close();
	
	list1.display();
	cout<<endl;
	list2.display();
	cout<<endl;
	
	PolynomialAddition(list1,list2,list3);
	OutputInFile(list3,1);
	list3.display();
	cout<<endl;
	
	file.open("OutputP1.txt" , ios::in);
		file>>equation;
		ExtractingString (list4 , equation);
	file.close();
	
	list4.display();
	cout<<endl;
	
	PolynomialDifferentiation(list4);
	OutputInFile(list4,2);
	list4.display();
	
	return 0;
}
