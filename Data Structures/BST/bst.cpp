#include <iostream>
#include <queue>
#include <stack>
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

class bst{
	public:
		node *root;
		
		bst(){
			root = new node;
			root = NULL;
				
		}
		
		void insert (int data_){
			root = insert(data_ , root);
		}

		node* insert(int data_ , node* temp) {
			
			if (temp == NULL){
				temp = new node(data_ , NULL , NULL);
			}
			else if (data_ <= temp->data){
				temp->left = insert(data_, temp->left);
			}
			else{
				temp->right = insert( data_, temp->right);
			}
			return temp;
		}
		
		void insertwo(int datax){
			node *t;
			t = root;
			if (t == NULL){
				root = new node (datax,NULL,NULL);
				return;
			}
			else{
				while(1){
					if (datax < t->data){
						if (t->left == NULL){
							t->left = new node(datax,NULL,NULL);
							break;
						}
						else t = t->left;
					}
					else if (datax > t->data){
						if (t->right == NULL){
							t->right = new node(datax,NULL,NULL);
							break;
						}
						else t = t->right;
					}
				}
			}
		}
		
//		void insert(int* data_ , node* temp) {         LEVEL ORDER INSERTION
//			int count = 0;
//			while (count < 2){
//			    if (temp == NULL){
//			    	temp = new node (data_[count] , NULL ,NULL);
//			    	count++;
//				}
//				else if (temp != NULL) {
//				  	qin.push(temp);
//				  	while (count <= n - 1) {
//				  		node* t = qin.front();
//				  		qin.pop();
//				  		
//				  		if (t->left == NULL){
//				  			t->left = new node (data_[count] , NULL , NULL);
//				  			qin.push(t->left);
//				  			count++;
//						}
//						if (t->right == NULL && count <= n-1){
//				  			t->right = new node (data_[count], NULL , NULL);
//				  			qin.push(t->right);
//				  			count++;
//						}
//				  	}
//			    }    
//			}
//			root = temp;
//		}
		
		node* Delete(node *t , int datax){
			if (t == NULL){
				return t;
			}
			else if (datax < t->data){
				t->left = Delete(t->left,datax);
			}
			else if (datax > t->data){
				t->right = Delete(t->right,datax);
			}
			else{
				if (t->left == NULL && t->right == NULL){
					delete t;
					t = NULL;
					return t;
				}
				else if (root->left == NULL){
					node *temp = t;
					t = t->right;
					delete temp;
					return t;
				}
				else if (root->right == NULL){
					node *temp = t;
					t = t->left;
					delete temp;
					return t;
				}
				else{
					node* temp = findMin(t->right);
					t->data = temp->data;
					root->right = Delete(root->right,temp->data);
				}
			}
			return t;
		}
		
		node* findMin(node* temp)
	    {
	        if(temp == NULL)
	            return NULL;
	        else if(temp->left == NULL)
	            return temp;
	        else
	            return findMin(temp->left);
	    }
	
	    node* findMax(node* temp) {
	        if(temp == NULL)
	            return NULL;
	        else if(temp->right == NULL)
	            return temp;
	        else
	            return findMax(temp->right);
	    }
	    
		void preorder(node *temp){
		    if(temp == NULL){
				return;
			}
			else{
				cout<<temp->data<<" ";
				inorder(temp->left);
		    	inorder(temp->right);
			}
		}
		
		void preorder(){
			if (root == NULL){
				return;
			}
			else{
				cout<<endl;
				stack <node * > s;
				s.push(root);
				while(!s.empty()){
					node *t  = s.top();
					cout<<t->data<<" ";
					s.pop();
					if (t->right != NULL){
						s.push(t->right);
					}
					if (t->left != NULL){
						s.push(t->left);
					}
				}
			}
		}
		
		void inorder(node *temp){
		    if(temp == NULL){
				return;
			}
			else{
				inorder(temp->left);
		   	 	cout<<temp->data<<" ";
		    	inorder(temp->right);
			}
		}
		
		void inorder(){
			node *t = root;
			stack<node *> s;
			cout<<endl;
			while (t != NULL || !s.empty()){
				while (t != NULL){
					s.push(t);
					t = t->left;
				}
				
				t = s.top();
				s.pop();
				cout<<t->data<<" ";
				t = t->right;
			}
		}
		
		void postorder(node *temp){
		    if(temp == NULL){
				return;
			}
			else{
				inorder(temp->left);
		   	 	inorder(temp->right);
		   	 	cout<<temp->data<<" ";
			}
		}
		
		void postorder(){
			if (root == NULL){
				return;
			}
			else{
				cout<<endl;
				stack <node * > s1,s2;
				s1.push(root);
				while(!s1.empty()){
					node *t  = s1.top();
					s1.pop();
					s2.push(t);
					
					if (t->left != NULL){
						s1.push(t->left);
					}
					if (t->right != NULL){
						s1.push(t->right);
					}
				}
				
				while (!s2.empty()){
					cout<<s2.top()->data<<" ";
					s2.pop();
				}
			}
		}
		
		void bfs(){
			if (root == NULL){
				return;
			}
			else{
				cout<<endl;
				queue <node*> q;
				q.push(root);
				while (!q.empty()){
					node *t  = q.front();
					cout<<t->data<<" ";
					q.pop();
					if (t->left != NULL){
						q.push(t->left);
					}
					if(t->right != NULL){
						q.push(t->right);
					}
				}
			}
		}
		
};

int main(){
	int n,temp;
	cin>>n;
	bst tree;
	for (int i = 0 ; i < n ; i++){
		cin>>temp;
		tree.insert(temp);
	}

	tree.inorder();
	tree.preorder();
	tree.postorder();
	tree.bfs();

	tree.Delete(tree.root , 10);
	tree.inorder();
	tree.preorder();

	return 0;
}
