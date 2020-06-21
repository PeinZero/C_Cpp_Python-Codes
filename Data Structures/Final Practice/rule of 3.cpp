#include <iostream>
using namespace std;

class final{
	private:
		int *arr , **arr2 ;
		int x , size;
		char y;
	public:
		// constructor
		
		final(){
			size = 0;
			
			arr = NULL;
			arr2 = NULL;
		
			x = 0;
			y = '\0';
		}
		
		final( int size_){
			size = size_;
			arr = new int[size];
			arr2 = new int* [size];
			
			for (int i = 0 ; i < size ; i++){
				arr2[i] = new int[size];
			}
			x = 0;
			y = '\0';
		}
		// copy constructor
		final(const final &obj){
			size = obj.size;
			
			arr = new int[size];
			arr2 = new int* [size];
			
			for (int i = 0 ; i < size ; i++){
				arr2[i] = new int[size];
			}
			
			for (int i = 0 ; i < size ; i++){
				arr[i] = obj.arr[i];
			}
			for (int i = 0 ; i < size ; i++){
				for (int j = 0 ; j < size ; j++){
					arr2[i][j] = obj.arr2[i][j];
				}
			}
			
			x = obj.x;
			y = obj.y;
			
		}
		// assignment operator 
		final& operator = (const final &obj){
			this->~final();
			
			this->size = obj.size;
			
			arr = new int[size];
			arr2 = new int* [size];
			
			for (int i = 0 ; i < size ; i++){
				arr2[i] = new int[size];
			}
			
			for (int i = 0 ; i < size ; i++){
				this->arr[i] = obj.arr[i];
			}
			for (int i = 0 ; i < size ; i++){
				for (int j = 0 ; j < size ; j++){
					this->arr2[i][j] = obj.arr2[i][j];
				}
			}
			this->x = obj.x;
			this->y = obj.y;
			
			return *this;
			
		}
		// destructor
		~final(){
			if (arr != NULL){
				delete [] arr;
				arr = NULL;	
			}

			if (arr2 != NULL){
				for (int i = 0 ; i < size ; i++){
					if (arr2[i] != NULL){
						delete arr2[i];
					}	
				}
				delete [] arr2;	
			}
			arr2 = NULL;
		}
		
		 //1D safe array
		int operator [] (int i){
			if (i < 0 || i >= size){
				cout<<"out of bounds."<<endl;
				return 0;
			}
			else{
				cout<<endl<<"value = ";
				return arr[i];
			} 
		}
		// 2D safe array
		int operator () (int i , int j){
			if (i < 0 || i >= size || j < 0 || j >= size){
				cout<<"out of bounds."<<endl;
				return 0;
			}
			else{
				cout<<endl<<"value = ";
				return arr2[i][j];
			}
		}
		
		void set(){
			for (int i = 0 ; i < size ; i++){
				cout<<"enter num in arr["<<i<<"]: ";
				cin>>arr[i];
			}
			for (int i = 0 ; i < size ; i++){
				for (int j = 0 ; j < size ; j++){
					cout<<"enter num in arr2["<<i<<"]["<<j<<"]: ";
					cin>>arr2[i][j];
				}
			}		
			cout<<endl<<"Enter value of int x: ";
			cin>>x;
			cout<<endl<<"Enter char value of char y: ";
			cin>>y;
			
		}
		
		void display(){
			cout<<endl<<"============OUTPUT==========="<<endl;
			for (int i = 0 ; i < size ; i++){
				cout<<"value in arr["<<i<<"]: "<<arr[i]<<endl;
			}
			for (int i = 0 ; i < size ; i++){
				for (int j = 0 ; j < size ; j++){
					cout<<"value in arr2["<<i<<"]["<<j<<"]: "<<arr2[i][j]<<endl;
				}
			}		
			cout<<endl<<"Value of int x: "<<x<<endl;
			cout<<endl<<"Value of char y: "<<y<<endl;
		}
};

int main (){
	final o1(1),o2;
	o1.set();
	o2 = o1;
	o2.display();
	final o3 = o2;
	o3.display();

	
	cout<<endl<<endl;
	cout<<o2[-1];
	cout<<endl;
	cout<<o2[0];
	cout<<endl;
	cout<<o2[2];
	cout<<endl;
	
	cout<<endl<<o2(0,-1);
	cout<<endl;
	cout<<o2(0,0);
	cout<<endl;
	cout<<o2(3,0);
	return 0;
}
