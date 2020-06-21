#include <iostream>
using namespace std;

struct student {
	int id;
	string name;
	float cgpa;
};

class queue{
	private:
		student *data;
		int size;
		int x;
		char MinOrMax;
	public:
		queue (int size_ , char MinOrMax_){
			x = -1;
			size = size_;
			data = new student[size];
			MinOrMax = MinOrMax_;
			
			for (int i = 0 ; i < size ; i++){
				data[i].id = 0;
				data[i].name ="0";
				data[i].cgpa = 0.0;
			}
		}
		void enqueue(student data_){
			x++;
			if (x < size){
				data[x].id = data_.id;
				data[x].name = data_.name;
				data[x].cgpa = data_.cgpa;
				
				cout<<"ITEM ENQUEUED: ";
			  	cout<<data[x].id<<" "<<data[x].name<<" "<<data[x].cgpa<<endl;
			
				if ( x > 0){
					x++;
					if (MinOrMax == 'n'){
						for (int i = (x/2) - 1 ; i >= 0; i--){
							minHeapify(i);
						}
					}
					else{
						for (int i = (x/2) - 1 ; i >= 0; i--){
							maxHeapify(i);
						}
					}
					
					x--;
				}
			}
			else{
				cout<<"Queue is Full."<<endl;
				x--;
			}
		}
		void dequeue(){
			if (x > -1){
				student temp ;
				
				temp.id = data[0].id;
		  		temp.name = data[0].name;
		  		temp.cgpa = data[0].cgpa;
		  		data[0].id = data[x].id;
		  		data[0].name = data[x].name;
		  		data[0].cgpa = data[x].cgpa;
		  		data[x].id = temp.id;
		  		data[x].name = temp.name;
		  		data[x].cgpa = temp.cgpa;
		  		
		  		cout<<"Item Dequeued: ";
		  		cout<<data[x].id<<" "<<data[x].name<<" "<<data[x].cgpa<<endl;
				
				x--;
		  		
				if ( x > 0){
					x++;
					if (MinOrMax == 'n'){
						for (int i = (x/2) - 1 ; i >= 0; i--){
							minHeapify(i);
						}
					}
					else{
						for (int i = (x/2) - 1 ; i >= 0; i--){
							maxHeapify(i);
						}
					}
					x--;
				}
			}
			else cout<<"Queue is Empty."<<endl;
			
		}
		void maxHeapify(int i){
			int largest = i;
   			int l = 2*i + 1;
   			int r = 2*i + 2;
   			
			if (l < x && (data[l].cgpa > data[largest].cgpa) ){
				largest = l;
			}
    			
			if (r < x && data[r].cgpa > data[largest].cgpa){
    			largest = r;
    		}
    		
		  	if (largest != i){
		  		student temp;
		  		
				temp.id = data[i].id;
		  		temp.name = data[i].name;
		  		temp.cgpa = data[i].cgpa;
		  		data[i].id = data[largest].id;
		  		data[i].name = data[largest].name;
		  		data[i].cgpa = data[largest].cgpa;
		  		data[largest].id = temp.id;
		  		data[largest].name = temp.name;
		  		data[largest].cgpa = temp.cgpa;
		     	
				minHeapify(largest);
		   	}
		}
		
		void minHeapify(int i){
			int smallest = i;
   			int l = 2*i + 1;
   			int r = 2*i + 2;
   			
			if (l < x && (data[l].cgpa < data[smallest].cgpa) ){
				smallest = l;
			}
    			
			if (r < x && data[r].cgpa < data[smallest].cgpa){
    			smallest = r;
    		}
    		
		  	if (smallest != i){
		  		student temp;
		  		
				temp.id = data[i].id;
		  		temp.name = data[i].name;
		  		temp.cgpa = data[i].cgpa;
		  		data[i].id = data[smallest].id;
		  		data[i].name = data[smallest].name;
		  		data[i].cgpa = data[smallest].cgpa;
		  		data[smallest].id = temp.id;
		  		data[smallest].name = temp.name;
		  		data[smallest].cgpa = temp.cgpa;
		     	
				minHeapify(smallest);
		   	}
		
		}
		student peek(){
			return data[0];
		}
	
		
		void print(){
			for (int i = 0 ; i <= x ; i++){
				cout<<data[i].id<<" "<<data[i].name<<" "<<data[i].cgpa<<endl;
			}
			cout<<endl;	
		}
};

int main(){
	int choice;	
	char MinOrMax;	
	
	cout<<"Size of Q = 4 "<<endl;
	cout<<"1) Q using Min Heapify\n2) Q using Max Heapify"<<endl;
	cin>>choice;
	
	if (choice == 1){
		MinOrMax = 'n';
	}
	else if ( choice == 2){
		MinOrMax = 'x';
	}
	else{
		cout<<"Wrong Choice."<<endl;
		return 0;
	}			 
	
	queue q(4 , MinOrMax );
	student arr[4];
	
	cout<<endl;
	for (int i = 0 ; i < 4 ; i++){
		cout<<"Enter Id "<<i+1<<": ";
		cin>>arr[i].id;
		cout<<"Enter Name: ";
		cin>>arr[i].name;
		cout<<"Enter CGPA: ";
		cin>>arr[i].cgpa;
	}
	
	cout<<"*******************************Enqueuing Array*******************************"<<endl<<endl;
	for ( int i = 0 ; i < 4 ; i++){	
		q.enqueue(arr[i]);
	}
	cout<<endl;
	
	cout<<"\n*******************************After Heapify*********************************"<<endl<<endl;
	q.print();
	
	cout<<"\n*************************Checking Peek Function****************************"<<endl<<endl;
	student datax = q.peek();
	cout<<datax.id<<" "<<datax.name<<" "<<datax.cgpa<<endl;
	
	cout<<"\n***********************Checking Enqueue/Dequeue Function*********************"<<endl<<endl;
	q.enqueue(arr[3]);
	q.dequeue();
	q.print();
	q.dequeue();
	q.print();
	q.dequeue();
	q.print();
	q.enqueue(arr[1]);
	q.print();
	q.dequeue();
	q.print();
	q.dequeue();
	q.print();
	q.dequeue();
	
	return 0;
}
