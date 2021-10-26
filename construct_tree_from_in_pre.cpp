#include<bits/stdc++.h>
using namespace std;

struct Node{
	char val;
	Node *left;
	Node *right;
};

Node* newNode(char x){
	Node *node = new Node();
	node->val = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int search(char arr[],int l,int r,char key){
	for(int i=l;i<=r;i++){
		if(arr[i] == key)
			return i;
	}
}

Node* buildTree(char inorder[],char preorder[],int l, int r){
	static int preIndex = 0;

	if(l>r)
		return NULL;

	Node *tempNode = newNode(preorder[preIndex++]);

	if(l==r)
		return tempNode;

	int inIndex = search(inorder,l,r,tempNode->val);

	tempNode->left = buildTree(inorder,preorder,l,inIndex-1);
	tempNode->right = buildTree(inorder,preorder,inIndex+1,r);

	return tempNode;
}

void LevelOrderTraversal(Node* node){
	queue<Node*> q;
	q.push(node);
	while(!q.empty()){
		Node *temp = q.front();
		q.pop();

		cout<< temp->val << " ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	return;
}

int main(){
	char inorder[] = {'D','B','E','A','F','C'};
	char preorder[] = {'A','B','D','E','C','F'};
	int n = sizeof(inorder)/sizeof(inorder[0]);

	Node *root = NULL;
	root = buildTree(inorder,preorder,0,n-1);
	LevelOrderTraversal(root);
	cout << endl;

	return 0;	
}