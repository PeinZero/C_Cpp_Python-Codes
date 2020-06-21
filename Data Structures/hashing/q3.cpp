#include "SinglyLinkedList.h"

class Hashing{
	public:
		
		int tableSize;
		int currentSize;
		SinglyLinkedList *table;
		
		Hashing(int size){
			currentSize = 0;
			tableSize = size;
			table = new SinglyLinkedList [tableSize];
		}
		
		void insertInTable(int key){
			int position = key%tableSize;
			table[position].addAtTail(key);
			currentSize++;
		}
		
		bool checkLoadFactor(){
			float loadFactor = (float) currentSize/tableSize;
			if (loadFactor > 3){
				
				delete table;
				
				currentSize = 0;
				tableSize = tableSize*2;
				table = new SinglyLinkedList [tableSize];
				
				return true;
			}
			return false;
		}
		
		void displayHashTable(){
			cout<<"\t\t\tHASH TABLE\n\n";
			for (int i = 0 ; i < tableSize ; i++){
				cout<<"table["<<i<<"]: ";
				table[i].display();
			}
		}
	 
};


int main(){
	int array[18] = {10, 15, 20, 25, 30, 35, 43, 45, 90, 87, 65, 98, 76, 70, 32, 43, 56, 97};
	Hashing obj(5);
	bool LF = false;
	
	for (int i = 0 ; i < 18 ; i++){
		obj.insertInTable(array[i]);
		LF = obj.checkLoadFactor();
		if (LF == true){
			i = -1;
		}
	}
	
	obj.displayHashTable();
	
	return 0;
}
