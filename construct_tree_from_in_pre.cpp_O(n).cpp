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



Node* buildTree(char inorder[],char preorder[],int l, int r,unordered_map<int,int> &um){
	static int preIndex = 0;

	if(l>r)
		return NULL;

	Node *tempNode = newNode(preorder[preIndex++]);

	if(l==r)
		return tempNode;

	int inIndex = um[tempNode->val];

	tempNode->left = buildTree(inorder,preorder,l,inIndex-1),um;
	tempNode->right = buildTree(inorder,preorder,inIndex+1,r,um);

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

	unordered_map<char,int> um;
	for(int i=0;i<n;i++){
		um[inorder[i]] = i;
	}

	root = buildTree(inorder,preorder,0,n-1,um);
	LevelOrderTraversal(root);
	cout << endl;

	return 0;	
}