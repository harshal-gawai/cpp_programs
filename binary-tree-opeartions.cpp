// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
#include<bits/stdc++.h>
using namespace std;

// struct node *root = newNode('0',0);
//struct node *root=NULL;
// newNode* temp = new newNode('0',0);    this doesn't work here
struct TreeNode{
    char name;
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x,int y) : name(x), val(y),left(NULL), right(NULL) {}
};

TreeNode* build_tree(TreeNode* node, vector<int> &vals, vector<char> &names, int n){
    // cout << "lalala "<<root->name << " " << root->val << endl;
    queue<TreeNode*> q;
    q.push(node);
    int count = 0;
    
    TreeNode *cur = NULL;
    for(int i = 1; i < n; i++){
        TreeNode *node = new TreeNode(names[i],vals[i]);
        if(count == 0){
           cur = q.front();   
            q.pop();
        }
        if(count==0){
          count++;
          cur->left = node;
        }else {
          count = 0;
          cur->right = node;
        }
        if(names[i] != 'N'){
          q.push(node);
        }
     }
    return node;
}

TreeNode* find_first_N(TreeNode* node){
    TreeNode *temp = new TreeNode('0',0);
    queue<TreeNode*> q;
    q.push(node);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->name == 'N' && temp->val == -1)
            break;
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
    return temp;
}

int main(){
    int T;
    cin>>T;
    // struct node *root=NULL;
    TreeNode *root = NULL;
    while(T--)
    {
        int operation;
        cin>>operation;
        if (operation == 1)
        {
            int n;
            cin>>n;
            vector <int> vals(n,-1);
            vector <char> names;
            for (int i=0;i<n;i++)
            {
                char s;
                int v;
                cin>>v;
                cin>>s;
                vals[i]=v;
                names.push_back(s); 
            }
            if (root != NULL){ //Tree already exists
                //find first N, -1
                // cout <<"not NULL" << endl;
                TreeNode *found = find_first_N(root);
                cout << found->name << " " << found->val << endl;
                // TreeNode *node = new TreeNode(names[0],vals[0]);
                // found = build_tree(found,vals,names,n);
            }
            else
            {
            //your code goes here
                //initialize new tree is done here
                TreeNode *root = new TreeNode(names[0],vals[0]);
                root = build_tree(root,vals,names,n);
                // cout << root->left->name << " " << root->val << endl;
            }
        }
        if (operation==2)
        {
            char s;
            cin>>s;
            //your code goes here
        }
        if (operation==3)
        {
            char s;
            cin>>s;
            int count=0;
           //your code goes here
            cout<<count<<endl;    
        }
        if (operation==4)
        {
            int target;
            cin>>target;
            int leaf=0,non_leaf=0;
            //your code goes here
            cout<<leaf<<" "<<non_leaf<<endl;    
        }
        //printer
        if (operation==5)
        {
            int target;
            cin>>target;
            //your code goes here
            TreeNode *temp = new TreeNode('0',0);
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                temp = q.front();
                q.pop();
                cout << temp->name << " ";
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            cout<<endl;
        }
    }
    return 0;
}