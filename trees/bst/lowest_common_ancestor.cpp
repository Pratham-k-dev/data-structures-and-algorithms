#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  
public:



    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {// optimal O(h)
        if(p->val<root->val && q->val<root->val ){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);

        }
        return root;
    }


     TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) { // my code(not optimal) O(3*h) +SC O(n)
        vector<TreeNode*> a;
        vector<TreeNode*> b;
        find(root,p,a);
        find(root,q,b);
        TreeNode* ans=root;
        int i=0,j=0;
        while(i<a.size()&& j<b.size() && a[i]->val==b[j]->val){
            ans=a[i];
            i++;
            j++;
        }
        return ans;
    }
      void find(TreeNode* root,TreeNode* p,vector<TreeNode*> & a){
        TreeNode* temp=root;
        while(temp){
            a.push_back(temp);
            if(temp==p) break;
            if(temp->val>p->val) temp=temp->left;
            else temp=temp->right;
        }
    }
};

int main (){
    
    return 0;
}