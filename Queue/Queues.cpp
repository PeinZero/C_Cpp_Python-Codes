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
			if(rear >= size -1 ){
				cout<<"queue is full"<<endl;
				return;
			}
			else{
				if (rear == -1){
					rear++;
					front++;
					arr[rear] = data;
					return;
				}
				rear++;
				arr[rear] = data;
			}
		}
		
		void dequeue(){
			if (front == -1){
				cout<<"queue is empty"<<endl;
				return;
			}
			else{
				arr[front] = 0;
				if (front == rear){
					front = -1 ;
					rear = -1;
					return;
				}
				front++;
			}
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
	q.dequeue();
	q.display();
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(6);
	q.enqueue(1);
	q.enqueue(3);
	q.display();
	q.enqueue(2);
	q.display();
	
	return 0;
}
