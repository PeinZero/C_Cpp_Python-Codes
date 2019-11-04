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
		
		bool isPrime(int n)  
		{  
		  bool flag = true;  
		  for(int i = 2; i < n/2; i++)  
		  {  
		      if(n % i == 0)  
		      {  
		          flag=false; 
				  break;
		          
		      }  
		  }  
		  return flag; 
		       
		} 
		
		void Primefactors(int data){
			for (int i = 2 ; i <= data ; i++){
				
				if (isPrime(i) == true){
					if (data % i == 0){
						push(i);
					}
				}
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
	int num;
	cout<<"enter num: ";
	cin>>num;
	Stack stack(num/4);
	stack.Primefactors(num);
	cout<<"In Stack:"<<endl;
	stack.display();
	cout<<"After Popping:"<<endl;
	stack.reverseDisplay();
	return 0;
}
