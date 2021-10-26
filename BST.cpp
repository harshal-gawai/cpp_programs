#include<bits/stdc++.h>
using namespace std;

class BST{
	int val;
	BST *left, *right;

public:
	BST();					//default constructor

	BST(int);				//parametrized constructor

	BST* Insert(BST*,int);	//values inserter

	void inorder(BST*);		//printer traversal

	BST* DeleteNode(BST*, int);

	void depthfinder(BST*,int,int,int);

	void levelordertraversal(BST*);
};

BST::BST() : val(0), left(NULL),right(NULL) {}

BST::BST(int x){
	val = x;
	left = right = NULL;
}

BST* BST::Insert(BST *root, int x){
	if(!root)
		return new BST(x);

	if(x > root->val)
		root->right = Insert(root->right,x);
	else
		root->left = Insert(root->left,x);
	return root;
}

vector<int> printer;
void BST::inorder(BST* node){
	if(!node)
		return;
	inorder(node->left);
	printer.push_back(node->val);
	inorder(node->right);
}

BST* BST::DeleteNode(BST *root, int k){
	if(!root)
		return root;

	if(k > root->val){
		root->right = DeleteNode(root->right,k);
		return root;
	}
	else if(k < root->val){
		root->left = DeleteNode(root->left,k);
		return root;
	}

	//from here onwards node with k has to be deleted;
	if(root->val == k){
		//one of child is empty
		if(root->left == NULL && root->right){
			BST *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->left && root->right==NULL){
			BST *temp = root->left;
			delete root;
			return temp;
		}

		//both childs exist. ie are non empty
		else{
			BST *succParent = root;

			BST *succ = root->right;
			while(succ->left != NULL){
				succParent = succ;
				succ = succ->left;
			}

			if(succParent != root)
				succParent->left = succ->right;
			else
				succParent->right = succ->right;

			root->val = succ->val;
			delete succ;
			return root;
		}

	}
	return NULL;

}
vector<int> depth;

void BST::depthfinder(BST *root,int i,int x,int count){
	if(root->val == x){
		depth[i] = count;
		return;
	}
	if(x > root->val){
		depthfinder(root->right,i,x,count+1);
	}
	else{
		depthfinder(root->left,i,x,count+1);
	}
}

void BST::levelordertraversal(BST *root){
	queue<BST*> q;
	q.push(root);
	while(!q.empty()){
		BST *temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
	return;
}

int main(){
	BST b, *root = NULL;		//b is object and *root is BST object pointer currently NULL
	root = b.Insert(root,5);	//master node/root node of BST
	b.Insert(root, 10);
	b.Insert(root, 11);
	b.Insert(root, 23);
	root = b.DeleteNode(root, 10);
	b.Insert(root, 10);
	b.Insert(root, 13);
	b.Insert(root, 4);
	root = b.DeleteNode(root, 5);
	root = b.DeleteNode(root, 10);
	b.Insert(root, 2);
	b.Insert(root, 5);
	root = b.DeleteNode(root, 4);
	b.Insert(root, 25);
	b.Insert(root, 24);


	printer.clear();depth.clear();
    b.inorder(root);
    for(int i=0;i<printer.size();i++) 
    	cout << printer[i] << " ";
    cout << endl;

    depth.resize(printer.size());

    for(int i=0;i<printer.size();i++)
    	b.depthfinder(root,i,printer[i],0);

   	for(int i=0;i<depth.size();i++)
   		cout << depth[i] << " ";
   	cout << endl;

   	b.levelordertraversal(root);
   	cout << endl;
    return 1;
}

// b.Insert(root, );
// root = b.DeleteNode(root, );