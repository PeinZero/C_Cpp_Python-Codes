#include <iostream>
using namespace std;

class queue{
	public:
		int front,rear,size;
		int *arr;
		
		queue(){
			front =  -1 ;
			rear = -1 ; 
			size = 5 ;
			arr = new int [5];
			
			for (int i = 0 ; i < size ; i++){
				arr[i] = 0 ;
			}
		}
		
		void enqueue(int data){
			if ( rear == size - 1 && front == 0){
				cout<<"queue is Full."<<endl;
			}
			else if (rear == front - 1){
				cout<<"queue is Full."<<endl;
			}
			else if ( rear == -1){
				rear++;
				front++;
				arr[rear] = data;
			}
			else if (rear == size - 1 && front > 0){
				rear = 0;
				arr[rear] = data;
			}
			else{
				rear++;
				arr[rear] = data;
			}
			return;
		}
		
		void dequeue(){
			if (front == -1) 
		    { 
		        cout<<"Queue is Empty"<<endl; 
		        return ; 
		    }
			else if(front == rear){
				arr[front] = 0;
				front = -1;
				rear = -1;
			} 
			else if (front == size - 1){
				arr[front] = 0;
				front = 0;
			}
			else{
				arr[front] = 0;
				front++;
			}
		    return;     
		}
		
		void display(){
			for (int i = 0 ; i < size ; i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	
};


int main(){
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
	q.enqueue(5);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.display();
	q.enqueue(10);
	q.dequeue();
	q.display();
	q.enqueue(12);
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();
	q.display();
	q.dequeue();	
	return 0;
}	
