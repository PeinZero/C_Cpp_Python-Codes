#include <iostream>
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
		
		
		void addAtHead(int data_){
			if (head == NULL){
				head  = new Node (data_ , NULL);
			}
			else{
				head  = new Node (data_ , head);
			}
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
		
		merge(){
			int startPos = 0 , totalCount = 0 ;
			int *mergedArray;
			Node *current = new Node;
			current = head ; 
			
			while ( current != NULL){
				totalCount = totalCount + current->count;
				current = current->next;
			}
			
			mergedArray = new int [totalCount];
			
			current = head ;
			int count = 0; 
			while ( current != NULL){
				for (int i = 0 ; i < current->count ; i++){
					mergedArray[count] = current->data[i];
					count++;
				}
				current = current->next;
			}
			
//			for (int i = 0 ; i < totalCount ; i++){
//				cout<<mergedArray[i]<<" ";
//			}
//			cout<<endl<<endl;
			
			while (startPos < totalCount){
//				cout<<"startPos = "<<startPos<<endl;
//				cout<<"totalCount = "<<totalCount<<endl;
				
				LargestPalindromeLeft(mergedArray , startPos , totalCount);
				LargestPalindromeRight(mergedArray , startPos , totalCount);
				
				
				startPos++;
				totalCount--;
			}
			
			cout<<endl;
//			cout<<"max1 = "<<max1<<endl;
//			cout<<"max2 = "<<max2<<endl;	
//			system("pause");
			if (max1 > max2)
			{
				for (int i = indexLeftStart ; i <= indexLeftEnd ;i++){
					cout<<mergedArray[i];
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
		}
		
		int LargestPalindromeLeft(int *mergedArray_ , int startPos_ , int totalCount_){
			
			int max = 0 , multiplier = 1 , start = startPos_ , end = totalCount_ - 1 ;
			int t1 = 0 , t2 = -1;
			bool palindrome = true;
			bool firstMatch = true;
			
			while ( end > startPos_){	
//				cout<<"\ncomparingL: "<<mergedArray_[startPos_]<<" "<<mergedArray_[end]<<endl;
				if(mergedArray_[startPos_] != mergedArray_[end])
				{	
					max = 0;
					firstMatch = true;
					t1 = 0  ;
					t2 = -1 ;
					startPos_ =  start;
					palindrome = false;
	                break;
	            }
	            
	            if (firstMatch == true){
	            	t1 = startPos_ ;
	            	t2 = end;
	            	firstMatch = false;
				}
	            
//	            cout<<"Lmax = "<<max<<endl;
//	            system("pause");
	            
	            startPos_ ++;
	            end--;
			}
			
			if (palindrome == true){
				max = t2 - t1 + 1;
//				cout<<"t1 = "<<t1<<" , t2 = "<<t2<<" , max = "<<max<<" , max1 = "<<max1<<endl;
				
				if (max > max1){
					max1 = max;
//					cout<<"max1 = "<<max1<<endl;
					indexLeftStart = t1;
					indexLeftEnd = t2;
				}
//				system("pause");
				return 0;
			}
			
			if (totalCount_ - 1 != startPos_){
				max = 0;
				LargestPalindromeLeft(mergedArray_ , startPos_ , totalCount_-1);
			}
			return 0;		
		}
		
		int LargestPalindromeRight(int *mergedArray_ , int startPos_ , int totalCount_){
			
			int max = 0 , multiplier = 1 , start = startPos_  , end = totalCount_;
			int t1 = 0 , t2 = -1;
			bool palindrome = true;
			bool firstMatch = true;
			
			while ( start < totalCount_ - 1){	
//				cout<<"\ncomparingR: "<<mergedArray_[start]<<" "<<mergedArray_[totalCount_ - 1]<<endl;
				if(mergedArray_[start] != mergedArray_[totalCount_ - 1])
				{	
					max = 0;
					firstMatch = true;
					t1 = 0  ;
					t2 = -1 ;
					totalCount_ = end;
					palindrome = false;
	                break;
	            }
	            
	            if (firstMatch == true){
	            	t1 = start ;
	            	t2 = totalCount_ - 1;
	            	firstMatch = false;
				}
	            
//	            cout<<"Rmax = "<<max<<endl;
//	            system("pause");
	            start++;
	            totalCount_--;
			}
			
			if (palindrome == true){
				max = t2 - t1 + 1;
//				cout<<"t1 = "<<t1<<" , t2 = "<<t2<<" , max = "<<max<<" , max2 = "<<max2<<endl;
				
				if (max > max2){
					max2 = max;
//					cout<<"max2 = "<<max2<<endl;
					indexRightStart = t1;
					indexRightEnd = t2;
				}
//				system("pause");
				return 0;
			}

			if (startPos_ != totalCount_ - 1){
				max = 0;
				LargestPalindromeRight(mergedArray_ , startPos_ + 1 , totalCount_);
			}
			return 0;
		}
			
		void display()
		{
			Node *temp = new Node();
			temp=head;
			while(temp!=NULL)
			{
				for (int i = 0 ; i < temp->count ; i++){
					cout<<temp->data[i];
				}
				cout<<"\t";
				temp=temp->next;
			}
			cout<<endl<<endl;
		}
	
};

int main(){
	SinglyLinkedList list;
	int n,num;
//	cout<<"Nodes: ";
	cin>>n;
	
	for (int  i = 0 ; i < n ; i++){
		cin>>num;
		list.addAtTail(num);
	}
	
//	list.display();
	list.merge();
	return 0;
}
