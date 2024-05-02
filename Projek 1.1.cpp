#include <iostream>
using namespace std;

class Node{
	public:
	Node *left;
	Node *right;
	
	int key;
	node (){
		left = right = NULL;
	}
};

class BST {
	public:
	Node *root;
	
	BST(){
		root = NULL;
	}
	
	Node *insertRecursive(int newkey, Node *currentRoot){
		if (currentRoot==NULL){
			Node *newNode = new Node();
			newNode-> key = newkey;
			return newNode;
		}
		
		if (newkey < currentRoot -> key){	
			currentRoot ->left = insertRecursive(newkey, currentRoot -> left);
		} else if (newkey > currentRoot ->key){
			currentRoot ->right = insertRecursive(newkey, currentRoot -> right);
		}
		return currentRoot;
	}
	
	void insert (int newkey){
		root = insertRecursive(newkey, root);
	}
	
	void *preOrderRecursive(Node *currentRoot){
		if (currentRoot!=NULL){
			cout <<currentRoot ->key << " ";
			preOrderRecursive(currentRoot ->left);
			preOrderRecursive(currentRoot ->right);
		}
	}
	void preOrderTraversal(){
		cout << "Pre Order Traversal : ";
		preOrderRecursive(root);
		cout << endl;
	}
};


int main(int argc, char** argv) {
	
	BST *bin1 = new BST ();
	
	bin1-> insert(6);
	bin1-> insert(7);
	bin1-> insert(4);
	bin1-> insert(8);
	bin1-> insert(5);
	bin1-> insert(3);
	
	bin1-> preOrderTraversal();
	return 0;
}