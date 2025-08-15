// https://leetcode.com/problems/binary-tree-maximum-path-sum/?envType=problem-list-v2&envId=tree
#include<bits/stdc++.h>
using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
int f(TreeNode* root,int &m){
    if(root==nullptr) return 0;
    int lmax=max(0,f(root->left,m));
    int rmax=max(0,f(root->right,m));
    m=max(m,root->val +lmax+rmax);
    return root->val+max((lmax),rmax);
}

public:
    int maxPathSum(TreeNode* root) {
        int m=INT_MIN;
        f(root,m);
        return m;
    }
};
int main (){
    
    return 0;
}