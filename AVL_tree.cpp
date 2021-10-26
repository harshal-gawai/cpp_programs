#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node *left;
	Node *right;
	int height;
};
Node* newNode(int val){
	Node *temp = new Node();
	temp->val = val;
	temp->height = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int max(int a, int b){
	return (a>b)? a : b;
}

int height(Node *n){
	if(!n)
		return 0;
	return n->height;
}

int SpiritLevel(Node* n){
	if(!n)
		return 0;
	return height(n->left)-height(n->right);
}

Node* rightRotate(Node *node){
	Node *y = node->left;
	Node *T3 = y->right;

	//perform right rotation
	y->right = node;
	node->left = T3;

	//update heights
	node->height = max(height(node->left),height(node->right)) + 1;
	node->height = max(height(y->left),height(y->right)) + 1;
	return y;
}



Node* leftRotate(Node *node){
	Node *x = node->right;
	Node *T2 = x->left;

	//perform left rotation
	x->left = node;
	node->right = T2;

	//update heights
	node->height = max(height(node->left),height(node->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;
	return x;
}

Node* Insert(Node *node, int x){
	if(!node)
		return newNode(x);
	if(x > node->val)
		node->right = Insert(node->right,x);
	else if(x < node->val)
		node->left = Insert(node->left,x);
	else
		return node;

	node->height = 1 + max(height(node->left),height(node->right));

	int balance = SpiritLevel(node);

	//case1: left left case
	if(balance > 1 && x < node->left->val){
		return rightRotate(node);
	}

	//case3: right right case
	if(balance < -1 && x > node->right->val){
		return leftRotate(node);
	}

	//case2: left right case
	if(balance > 1 && x > node->left->val){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	//case4: right left case
	if(balance < -1 && x < node->right->left->val){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	else
		return node;
}

void preorder(Node* node){
	if(!node)
		return;
	cout << node->val <<" ";
	preorder(node->left);
	preorder(node->right);
}

int main(){
	Node* root = NULL;
	root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25);
    preorder(root);
    cout << endl;
	return 0;
}