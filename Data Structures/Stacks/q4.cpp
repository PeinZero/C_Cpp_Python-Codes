#include <iostream>
using namespace std;

class Stack {
	public:
		int *array;
		int top,size;
		
		Stack(){
			array = new int[5];
			top = 0;
			size = 5;
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
		
		void ReverseStack(Stack &stack2){
			int temp = top;
			for (int i = 1 ; i <= size ; i++){
				stack2.push(peak());
				top--;
			}
			top = temp;
		}
		
		void display(){
			for (int i = size - 1 ; i >= 0 ; i--){
				cout<<array[i]<<endl;
			}
		}
		
};

int main(){
	Stack stack1 , stack2;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	stack1.push(5);
	stack1.display();
	stack1.ReverseStack(stack2);
	cout<<endl;
	stack2.display();
}
