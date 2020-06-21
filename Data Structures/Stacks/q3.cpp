#include <iostream>
using namespace std;

class Stack {
	public:
		int *array;
		int top,size;
		
		Stack(int size_){
			top = 0;
			size = size_;
			array = new int[size];
			for(int i = 0 ; i < size ; i++){
				array[i] = 0;
			}
		}
		
		bool isFull(){
			if (top == size){
				cout<<"Error, Stack is Full"<<endl;
				return true;
			}
			else return false;
		}
		
		bool isEmpty(){
			if ( top == 0){
				cout<<"Stack is Empty"<<endl;
				return true;
			}
			else return false;
		}
		
		void push(int data){
			if ( isFull() == false){
				array[top] = data;
				top++;
			}
		}
		
		void pop(){
			if ( isEmpty() == false){
				top--;
				array[top] = 0;
			}
		}
		
		int peak(){
			if (top-1 >= 0){
				return array[top-1];
			}
		}
		
		void display(){
			for (int i = size - 1 ; i >= 0 ; i--){
				cout<<array[i]<<endl;
			}
		}
		
		bool operator == (Stack & stack_){
			if (size != stack_.size){
				return false;
			}
			
			for (int i = 1 ; i <= size ; i++){
				if (array[i] != stack_.array[i]){
					return false;
				}
			}
			
			return true;
		}
};

int main (){
	bool temp1,temp2;
	Stack stack1(3),stack2(2),stack3(3);
	
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	
	stack2.push(1);
	stack2.push(2);
	
	stack3.push(1);
	stack3.push(2);
	stack3.push(3);
	
	temp1 = (stack1 == stack2) ;
	temp2 = (stack1 == stack3);
	
	if (temp1 == false){
		cout<<"Stack 1 and 2 are Not Equal"<<endl;
	}
	else cout<<"Stack 1 and 2 are Equal"<<endl;
	
	if (temp2 == false){
		cout<<"Stack 1 and 3 are Not Equal"<<endl;
	}
	else cout<<"Stack 1 and 3 are Equal"<<endl;
		
	return 0;
}
