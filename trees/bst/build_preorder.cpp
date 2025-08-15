//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/?envType=problem-list-v2&envId=tree
#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    int ind=0;
    TreeNode* build(vector<int>& preorder,int low,int high){
        if(ind >=preorder.size() || (preorder[ind]>high || preorder[ind]<low)) return nullptr;
        TreeNode* root=new TreeNode(preorder[ind++]);
        root->left=build(preorder,low,root->val);
        root->right=build(preorder,root->val,high);
        return root;
        
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,INT_MIN,INT_MAX);
    }
};

int main (){
    
    return 0;
}
