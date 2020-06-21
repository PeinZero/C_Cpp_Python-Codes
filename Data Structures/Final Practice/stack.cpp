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
			int popped;
			if ( isEmpty() == false){
				top--;
				popped = array[top];
				array[top] = 0;
			}
			cout<<popped<<" ";
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
		
		void reverseDisplay(){
			for (int i = 0 ; i <= top ; i++){
				pop();
			}
		}
		
		
};

int main (){

	return 0;
}
