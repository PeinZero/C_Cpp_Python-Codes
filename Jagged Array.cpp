#include <iostream>
using namespace std;

class JaggedArray {
	public:
		int **array;
		int rows,*cols,size;
		
		JaggedArray();
		JaggedArray(const JaggedArray & object_jaggedArray);
		JaggedArray& operator = (const JaggedArray & object_jaggedArray);
		int& operator () (int i , int j);
		
		void Retrieve();
		void Display();
		
		~JaggedArray();
		

};


JaggedArray :: JaggedArray(){
	size = 0;
	
	cout<<"Enter Rows of Jagged Array: ";
	cin>>rows;
	
	array =  new int* [rows];
	cols = new int [rows];
	
	for (int i = 0 ; i < rows ; i++){
		cout<<"For Row "<<i+1<<". Enter No of Columns: ";
		cin>>cols[i];
		array[i] = new int [cols[i]];
	}
	
	for (int i = 0 ; i < rows ; i++){
		for ( int j = 0 ; j < cols[i] ; j++){
			array[i][j] = 0;
		}
	}
	
}

JaggedArray :: JaggedArray(const JaggedArray &object_jaggedArray){
	
	this->rows = object_jaggedArray.rows;
	this->array = new int* [this->rows];
	this->cols = new int [this->rows];
	
	for (int i = 0 ; i < rows ; i++){
		this->cols[i] =  object_jaggedArray.cols[i];
	}
	
	for (int i = 0 ; i < rows ; i++){
		array[i] = new int [this->cols[i]];
		for ( int j = 0 ; j < cols[i] ; j++){
			this->array[i][j] = object_jaggedArray.array[i][j];
		}
	}	
	
}

JaggedArray& JaggedArray :: operator = (const JaggedArray &object_jaggedArray){
	
	if (this == &object_jaggedArray){
         	return *this;
	}
	delete [] cols;
	cols = NULL;
	
	for (int i = 0 ; i < rows ; i++){
		delete [] array[i];
	}
	delete [] array;
	array = NULL;
	
	this->rows = object_jaggedArray.rows;
	this->array = new int* [this->rows];
	this->cols = new int [this->rows];
	
	for (int i = 0 ; i < rows ; i++){
		this->cols[i] =  object_jaggedArray.cols[i];
	}
	
	for (int i = 0 ; i < rows ; i++){
		array[i] = new int [this->cols[i]];
		for ( int j = 0 ; j < cols[i] ; j++){
			this->array[i][j] = object_jaggedArray.array[i][j];
		}
	}	
		
}


int& JaggedArray :: operator () (int i ,int j){
	
	if ( i < 0 || i > rows-1 || j < 0 || j > cols[i] -1 ){
		cout<<"Error! Index Out of Bound.";
		exit(1);
		
	}	
	else return array[i][j];
}

void JaggedArray :: Retrieve(){
	int total;
	for ( int i = 0 ; i < rows ; i++){
		size = size + cols[i];
	}
	
	cout<<endl<<"You can't ENTER more than "<<size<<" INTEGERS for the rows and columns that you set."<<endl<<endl;
	cout<<"Total Numbers Integers to enter? ";
	cin>>total;
	
	while ( total < 0 || total > size){
		system("cls");
		cout<<"Error !\nTotal Numbers Integers to enter? (no more than "<<size<<"):";
		cin>>total;
	}
	
	int indexi = 0 , indexj = 0;
	for (int count = 0 ; count < total ; count++){
		
		cout<<"Enter Integer: ";
		
		if( indexj > ( cols[indexi] - 1) ){
			indexi++;
			indexj=0;
		}
		cin>>array[indexi][indexj];
		indexj++;
	}
}

void JaggedArray :: Display(){
	cout<<endl<<endl<<"Content of Jagged Array: "<<endl<<endl;
	for ( int i = 0 ; i < rows ; i++){
		for ( int j = 0 ; j < cols[i] ; j++){
			cout<<"Jagged Array ["<<i<<"]"<<"["<<j<<"] = "<<array[i][j]<<endl;
		}
	}
}

JaggedArray :: ~JaggedArray(){
	delete [] cols;
	cols = NULL;
	
	for (int i = 0 ; i < rows ; i++){
		delete [] array[i];
	}
	delete [] array;
	array = NULL;
}


int main(int argc, char** argv) {
	
	JaggedArray jArray;
	
	jArray.Retrieve();
	
	JaggedArray jArray2 = jArray;
	jArray2.Display();
	
	
	return 0 ;
}
