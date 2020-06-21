#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

class node{
	public:
		
	int data;
	node *left;
	node *right;
	
	node(){
		data =  0;
		left = NULL;
		right = NULL;
	}
	
	node (int data_, node *left_ , node *right_){
		data = data_;
		left = left_;
		right = right_;
	}
};

class bt{
	public:	
		fstream file;
		queue<node*> qin;
		queue<node*> qout;
		node *root;
		int n;
		
		bt(int n_){
			
			
			file.open("OutputP2.txt", ios::out);
		
			root = new node;
			root = NULL;
			
			n = n_;			
		}
		

		void insert(int* data_ , node* temp) {
			int count = 0;
			while (count < 2){
			    if (temp == NULL){
			    	temp = new node (data_[count] , NULL ,NULL);
			    	count++;
				}
				else if (temp != NULL) {
				  	qin.push(temp);
				  	while (count <= n - 1) {
				  		node* t = qin.front();
				  		qin.pop();
				  		
				  		if (t->left == NULL){
				  			t->left = new node (data_[count] , NULL , NULL);
				  			qin.push(t->left);
				  			count++;
						}
						if (t->right == NULL && count <= n-1){
				  			t->right = new node (data_[count], NULL , NULL);
				  			qin.push(t->right);
				  			count++;
						}
				  	}
			    }    
			}
			root = temp;
		}
	    	
		void inorder(node *temp){
		    if(temp == NULL){
				return ;
			}
			else{
				inorder(temp->left);
		   	 	cout<<temp->data<<endl;
				inorder(temp->right);
		    }
		}
			
		int treeSum(node* temp , int X){

			if ( (temp->left != NULL && temp->left->data <= temp->data) && (temp->right != NULL && temp->right->data >= temp->data) ){
				if (temp->data + temp->left->data + temp->right->data == X){
					cout<<temp->data<<endl;
					cout<<temp->left->data<<endl;
					cout<<temp->right->data<<endl;
					file<<temp->data<<endl;
					file<<temp->left->data<<endl;
					file<<temp->right->data<<endl;
					exit(1);
				}
			}

			if (temp == NULL){
				return 0;
			}
			else{
				int sum = 0;
				int sumr = 0;
				
				sum = sum + temp->data;
//				cout<<"temp data = "<<temp->data<<endl;
//				system("pause");
//				sumr = temp->data;
				
				if ( (temp->left != NULL && temp->left->data <= temp->data) && (temp->right != NULL && temp->right->data >= temp->data) ){
//					cout<<"here1"<<endl;
//					system("pause");
					sum = sum + treeSum(temp->left,X);
//					cout<<sum<<endl;
//					system("pause");
//					if (sum == X){
//						file<<temp->data<<endl;
//						cout<<temp->data<<endl;
//						bfs(X,temp->left);
//						file.close();
//						exit(1);
//					}
					sum = sum + treeSum(temp->right,X);
//					cout<<sum<<endl;
//					system("pause");
//					sumr = sumr + treeSum(temp->right,X);
				}
				else if (( (temp->left != 0) && (temp->left->data > temp->data) ) || ( (temp->right != 0) && (temp->right->data < temp->data))){
//					cout<<"here3"<<endl;
//					system("pause");
					int s = sum;
					sum = 0;
					sum = sum + treeSum(temp->left,X);
					if (sum == X){
						file<<temp->data<<endl;
						cout<<temp->data<<endl;
						bfs(X,temp->left);
						file.close();
						exit(1);
					}
					else sum = 0;
					
					sum = sum + treeSum(temp->right,X);
					if (sum == X){
						file<<temp->data<<endl;
						cout<<temp->data<<endl;
						bfs(X,temp->right);
						file.close();
						exit(1);
					}
					else sum = s;
					
				} 
				else if (temp->left != NULL){
//					cout<<"here2"<<endl;
//					system("pause");
					sum = sum + treeSum(temp->left,X);	
//					cout<<sum<<endl;
//					system("pause");

					if (sum == X){
						file<<temp->data<<endl;
						cout<<temp->data<<endl;
						bfs(X,temp->left);
						file.close();
						exit(1);
					}
				}

				if (sum == X){;
					bfs(X,temp);
					file.close();
					exit(1);
				}
//				if (sumr == X){
//					file<<temp->data<<endl;
//					cout<<temp->data<<endl;
//					bfs(X,temp->right);
//					file.close();
//					exit(1);
//				}
				else{
					return sum;
				}
			}
		}

		void bfs(int X, node* temp) {
			int sum = 0;
			if (temp == NULL) {
				return;
			}
			else{
			  	qout.push(temp);
			  	while (!qout.empty() ) {
			  		node* t = qout.front();
			  		qout.pop();
			  		
			  		cout<<t->data<<endl;
			  		file<<t->data<<endl;
			  		sum = sum + t->data;
			  		
			  		if ((t->left != NULL && t->left->data <= t->data) && (t->right != NULL && t->right->data >= t->data) ){
			  			qout.push(t->left);
			  			qout.push(t->right);
					}
					else if (t->right == NULL && (t->left != NULL && t->left->data <= t->data) ){
						qout.push(t->left);
					}
						
			  	}
			}    

		}
		
};

int main(){
	fstream file;
	int n,X,*temp;
	
	file.open("InputP2.txt", ios :: in);
	
	file>>n;
	temp = new int [n];
	bt tree(n);
	
	file>>X;

	for (int i = 0 ; i < n ; i++){
		file>>temp[i];
	}
	tree.insert(temp,tree.root);
//	tree.inorder(tree.root);
//	system("pause");
	tree.treeSum(tree.root,X);
	

	return 0;
}
