#include <iostream>
using namespace std;

template <typename T>

class DynamicSafeArray {
	public:
		
		int size;
		T *array;
		
		DynamicSafeArray (int size_){
			size = size_;
			array = new T[size]; 
			
			for (int i = 0 ; i < size ; i++){
				array[i] = 0;
			}
		}
		
		DynamicSafeArray (const DynamicSafeArray& object_dsa){
			cout<<"Copy Constructor Called"<<endl;
			this->size = object_dsa.size;
			this->array = new T [this->size];
			
			for ( int i = 0 ; i < this->size ; i++){
				this->array[i] = object_dsa.array[i];
			}
		}
		DynamicSafeArray& operator = (const DynamicSafeArray& object_dsa){
			cout<<"Assignment Operator Called"<<endl;
			delete [] array;
			this->size = object_dsa.size;
			this->array = new T [this->size];
			
			for ( int i = 0 ; i < this->size ; i++){
				this->array[i] = object_dsa.array[i];
			}
		}
		
		T& operator[](T i){
			if ( i < 0 || i > size-1 ){
				cout<<"Error! Index out of bounds."<<endl;
				exit(1);
			}
			else
			{
				return array[i];
			}
		}
		
		void insertion(){
			cout<<"Enter Data: "<<endl;
			for(int i = 0 ; i < size ; i++){
				cin>>array[i];
			}
		}
		
		bool searching(T toSearch){	
			for (int i = 0 ; i < size ; i++){
				if (array[i] == toSearch){
					cout<<"The Data is at index : "<<i+1<<" of DynamicSafeArray."<<endl;
					return true;
				}		
			}
			cout<<"Data not found in DynamicSafeArray."<<endl;
			return false;
		}
		
		friend istream& operator >> (istream& infile, DynamicSafeArray & rhs){
			for (int count=0;count<rhs.size;count++){
				infile>>rhs.Data[count];
			}
			
			return infile;
		}
		friend ostream& operator << (ostream& outfile, DynamicSafeArray &rhs){
			for (int count=0;count<rhs.size;count++){
				outfile<<rhs.Data[count];
			}
			return outfile;
		}
		~DynamicSafeArray (){
			delete [] array;
			array = NULL;
		}

};

