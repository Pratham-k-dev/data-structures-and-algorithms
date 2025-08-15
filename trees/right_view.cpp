    // https://leetcode.com/problems/binary-tree-right-side-view/?envType=problem-list-v2&envId=tree

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
   
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
         queue<TreeNode*> q;
    q.push(root);
    
    // int x=0;
    while(!q.empty()){
        
        int n=q.size();
        int f=1;
        while(n--){
            
          TreeNode* curr = q.front();
        q.pop();
        if(f){
            ans.push_back(curr->val);
            f=0;
        }
        

        
        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
        }
        
    }

    return ans;
    }
};

int main (){
    
    return 0;
}