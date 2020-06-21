#include <iostream>
using namespace std;

class Stack {
	public:
		char *array;
		int top,size;
		
		Stack(int size_){
			
			top = 0;
			size = size_;
			array = new char[size];
			for(int i = 0 ; i < size ; i++){
				array[i] = '0';
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
		
		void push(char data){
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
		
		char peak(){
			if (top-1 >= 0){
				return array[top-1];
			}
		}

		void display(){
			for (int i = size - 1 ; i >= 0 ; i--){
				cout<<array[i];
			}
			cout<<endl;
		}
		
};

void CheckMatchingGroupSymbol(Stack &stack , string str){
	
	for ( int i = 0 ; str[i] != '\0' ; i++){
		if (str[i] == '{' || str[i] == '[' || str[i] == '('){
			stack.push(str[i]);
		}
		
		if ( (str[i] == '}' && stack.peak() == '{') || (str[i] == ']' && stack.peak() == '[') || (str[i] == ')' && stack.peak() == '(') ){
			stack.pop();
		}
	}
	
	if (stack.isEmpty() == true){
		cout<<"Contain matching group symbol."<<endl;
	}
	else cout<<"Does not contain matching group symbol."<<endl;
}

int main(){
	string str;
	cout<<"Enter a Expression:\n";
	getline(cin , str);
	
	Stack stack(str.length());
	CheckMatchingGroupSymbol(stack,str);	
	return 0;
	
}



















