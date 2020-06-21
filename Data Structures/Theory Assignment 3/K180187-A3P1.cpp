#include <iostream>
#include <fstream>
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
		node *root,*nl,*nr;
		int maxl, maxr;
		fstream file;
		
		bst(){
			root = new node;
			root = NULL;
			nl = new node;
			nl = NULL;
			nr = new node;
			nr = NULL;
			maxl = -1;
			maxr = -1;
			file.open("OutputP1.txt", ios::out);
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
		
		void largestsequence(node *t){
			if (t == NULL){
				return;
			}
			else{
				int lc = lefttraverse(t);
//				cout<<"lc = "<<lc<<endl;
				if (lc >= maxl){
					maxl = lc;
					nl = t;
				}
				int rc = righttraverse(t);
//				cout<<"rc = "<<rc<<endl;
				if (rc >= maxr){
					maxr = rc;
					nr = t;
				}
//				system("pause");
				largestsequence(t->left);
				largestsequence(t->right);
				}		
		}
		
		int lefttraverse(node *t){
			if (t == NULL){
				return 0;
			}
			else{
				int lc = 1;
				lc = lc + lefttraverse(t->left);
				return lc;
			}
		}
		
		int righttraverse(node *t){
			if (t == NULL){
				return 0;
			}
			else{
				int rc = 1;
				rc = rc + righttraverse(t->right);
				return rc;
			}
		}
		
		void display(){
			if ( maxl >= maxr){
				cout<<maxl<<endl;
				file<<maxl<<endl;
				displayleft(nl);
			}
			else{
				cout<<maxr<<endl;
				file<<maxr<<endl;
				displayright(nr);
			}
			file.close();
		}
		
		void displayleft(node* n){
			if (n == NULL){
				return;
			}
			else{
				cout<<n->data<<",";
				file<<n->data;
				if (n->left != NULL){
					file<<",";
				}
				displayleft(n->left);
			}
		}
		
		void displayright(node* n){
			if (n == NULL){
				return;
			}
			else{
				cout<<n->data<<",";
				file<<n->data;
				if (n->right != NULL){
					file<<",";
				}
				displayright(n->right);
			}
		}
		
	
};

int main(){
	fstream file;
	int num;
	bst tree;
	
	file.open("InputP1.txt" , ios:: in);
	file>>num;
	tree.root = tree.insert(num , tree.root);
	while (!file.eof()){
		file>>num;
		tree.insert(num , tree.root);
	}
	tree.largestsequence(tree.root);
	tree.display();

	return 0;
}
