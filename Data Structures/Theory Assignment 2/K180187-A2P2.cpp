#include <iostream>
#include <fstream>
using namespace std;

class Node{
	public:
		int *data ,count;
		Node* next;
		
		Node(){
			
			data = 0;
			next = 0;
		}
		
		Node(int data_ , Node* next_){
			int temp;
			count = 0;
			temp = data_;
			
			while(temp != 0){
				count++;
				temp = temp/10;
			}
			
			data = new int[count];
			
			for (int i = count-1 ; i >= 0 ; i--){
				data[i] = data_ % 10;
				data_ = data_ / 10;
			}
			next = next_;
		}
};

class SinglyLinkedList{
	private:
			Node* head;
			Node* tail;
			
	public:
		int max1  , max2 , indexRightStart  , indexRightEnd , indexLeftStart  , indexLeftEnd ;
		SinglyLinkedList(){
		
			head = new Node();
			tail = new Node();
			
			head = NULL;
			tail = NULL;
			max1 = 0;
			max2 = 0;
			indexRightStart =0 ;
			indexRightEnd = 0;
			indexLeftStart = 0;
			indexLeftEnd = 0;
		}
		
		void addAtTail(int data_){
			
			if (head == NULL){	
				head = tail  = new Node (data_ , NULL);		
			}
			else{
				tail->next = new Node (data_ , NULL);
				tail = tail->next;
			}
		}
		
		MergeNodes(){
			
			int startPos = 0 , totalCount = 0 , count = 0 , size = 0 ;
			int *mergedArray;
			Node *current = new Node;
			
			current = head ; 
			while ( current != NULL){
				
				totalCount = totalCount + current->count;
				current = current->next;
			}
			
			mergedArray = new int [totalCount];
			
			current = head ;
			while ( current != NULL){
				
				for (int i = 0 ; i < current->count ; i++){
					mergedArray[count] = current->data[i];
					count++;
				}
				current = current->next;
			}
			
			size = totalCount;	
			totalCount--;
			
			while (startPos < totalCount){
				
				LargestPalindromeLeft(mergedArray , startPos , totalCount);
				LargestPalindromeRight(mergedArray , startPos , totalCount);
				startPos++;
				totalCount--;
			}
			
			Display(mergedArray, size);			
		}
		
		void LargestPalindromeLeft(int *mergedArray_ , int startPos_ , int totalCount_){
			
			int max = 0 , start = startPos_ , end = totalCount_ ;
			int palindromStartIndex = 0 , palindromEndIndex = -1;
			bool palindrome = true;
			bool firstMatch = true;
			
			while ( end > start){
				
				palindrome = true;	
				if(mergedArray_[start] != mergedArray_[end])
				{	
					max = 0;
					firstMatch = true;
					palindromStartIndex = 0  ;
					palindromEndIndex = -1 ;
					start =  startPos_;
					end = totalCount_;
					totalCount_--;
					end--;
					palindrome = false;
	                continue;
	            }
	            
	            if (firstMatch == true){
	            	palindromStartIndex = startPos_ ;
	            	palindromEndIndex = end;
	            	firstMatch = false;
				}	            
	            start++;
	            end--;
			}

			if (palindrome == true){
				
				max = palindromEndIndex - palindromStartIndex + 1;
				if (max > max1){
					max1 = max;
					indexLeftStart = palindromStartIndex;
					indexLeftEnd = palindromEndIndex;
				}
				return;
			}	
		}
		
		void LargestPalindromeRight(int *mergedArray_ , int startPos_ , int totalCount_){
			
			int max = 0 , start = startPos_  , end = totalCount_;
			int palindromeStartIndex = 0 , palindromeEndIndex = -1;
			bool palindrome = true;
			bool firstMatch = true;
			
			while ( start < end){
			
				palindrome == true;
				if(mergedArray_[start] != mergedArray_[end])
				{	
					max = 0;
					palindromeStartIndex = 0  ;
					palindromeEndIndex = -1 ;
					end = totalCount_;
					start = startPos_;
					start++;
					startPos_++;
					firstMatch = true;
					palindrome = false;
	                continue;
	            }
	            else if (firstMatch == true){
	            	palindromeStartIndex = start ;
	            	palindromeEndIndex = end;
	            	firstMatch = false;
				}
				start++;
	            end--;	            
			}
			
			if (palindrome == true){
				
				max = palindromeEndIndex - palindromeStartIndex + 1;
				if (max > max2){
					max2 = max;
					indexRightStart = palindromeStartIndex;
					indexRightEnd = palindromeEndIndex;
				}
				return;
			}
		}
			
		void Display(int *mergedArray , int size){
			fstream file;
			file.open("OutputP2.txt" , ios::out);
			
			if (max1 == 0 && max2 == 0){
				for (int i = 0 ; i < size ; i++){
					if (mergedArray[i] > max1){
						max1 = mergedArray[i];
					}
				}
				cout<<max1<<endl;
				file<<max1;
				return;
			}
			
			if (max1 == max2){
				max1 = 0;
				max2 = 0;
				for (int i = indexLeftStart ; i <= indexLeftEnd ;i++){
					for (int j = indexRightStart ; j <= indexRightEnd ;j++){
						if (mergedArray[i] > mergedArray[j]){
							max1 = 1;
							break;
						}
						else if (mergedArray[i] < mergedArray[j]){
							max2 = 1;
							break;
						}
						else break;
					}
					if (max1 == 1 || max2 == 1){
						break;
					}
				}
			}
			
			if (max1 > max2)
			{
				for (int i = indexLeftStart ; i <= indexLeftEnd ;i++){
					cout<<mergedArray[i];
					file<<mergedArray[i];
				}
				cout<<endl;
			}
			else
			{
				for (int i = indexRightStart ; i <= indexRightEnd ;i++){
					cout<<mergedArray[i];
				}
				cout<<endl;
			}
			file.close();
		}
		
};

int main(){
	SinglyLinkedList List;
	fstream file;
	int noOfNodes,num;
	
	file.open("InputP2.txt" , ios::in);
	file>>noOfNodes;
	
	for (int  i = 0 ; i < noOfNodes ; i++){
		file>>num;
		List.addAtTail(num);
	}
	file.close();
	
	List.MergeNodes();
	
	return 0;
}
