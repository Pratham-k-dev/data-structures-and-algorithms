#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTiterator{
    stack<TreeNode*> sn; 
    stack<TreeNode*> sb; 
public:
BSTiterator(TreeNode* root){
    TreeNode* temp=root;
    while(temp){
        sn.push(temp);
        temp=temp->left;
    }
    temp=root;
    while(temp){
        sb.push(temp);
        temp=temp->right;
    }
}

int before(){
    TreeNode* node=sb.top();
    sb.pop();
    TreeNode* temp=node->left;
    while(temp){
        sb.push(temp);
        temp=temp->right;
    }
    return node->val;
}
int next(){
      TreeNode* node=sn.top();
    sn.pop();
    TreeNode* temp=node->right;
    while(temp){
        sn.push(temp);
        temp=temp->left;
    }
    return node->val;
}
};

bool two_sum(TreeNode* root,int k){// use TC=O(n) ,SC=O(h)
    BSTiterator it(root);
    int i=it.next();
    int j=it.before();
    while(i<j){
        if(i+j==k) return true;
        if(i+j < k) i=it.next();
        else j=it.before();
    }
    return false;
}

// two sum with inorder vector=> TC= O(n),SC=O(n)
int main (){
    
    return 0;
}