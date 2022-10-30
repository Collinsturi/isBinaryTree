#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* getNewNode(int data){
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

bool isSubTreeLesser(node* root, int data){
	if(root == NULL) return true;
	
	if(root->data <= data && isSubTreeLesser(root->left, data) && isSubTreeLesser(root->right, data))
		return true;
	else
		return false;
}
bool isSubTreeGreater(node* root, int data){
	if(root == NULL) return true;
	
	if(root->data > data && isSubTreeGreater(root->left, data) && isSubTreeGreater(root->right, data))
		return true;
	else
		return false;
}
bool isBinarySearchTree(node* root){
	if(root == NULL) return true;
	
	if(isSubTreeLesser(root->left, root->data) && isSubTreeGreater(root->right, root->data) && 
		isBinarySearchTree(root->left) && isBinarySearchTree(root->right)){
			return true;
	}else{
		return false;
	}
}

int main(){
	/*
						7	
			
				4				9
		
			1		6
	
	This is the Binary tree used below.
	*/		
	
	
	
	node* root = NULL;
	
	root = getNewNode(7);
	root->right = getNewNode(9);
	root->left = getNewNode(4);
	root->left->left = getNewNode(1);
	root->left->right = getNewNode(6);
	
	
	cout<<isBinarySearchTree(root);
}
