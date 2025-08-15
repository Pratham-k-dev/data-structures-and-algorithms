#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   
    bool f(TreeNode* root, ll &maxi,ll &mini){
        if(!root){
            maxi=INT64_MIN;
    mini=INT64_MAX;
         return true;
        }
        
      
        bool x,y;
        ll lmax,lmin,rmax,rmin;
        x=f(root->left,lmax,lmin);
        
        y=f(root->right,rmax,rmin);
        
        if(!x || !y) return false;
        if(root->val>=rmin || root->val<=lmax) return false;
        mini=min((ll)root->val,lmin);
        maxi=max((ll)root->val,rmax);
        return true;
        
    }
public:
    bool isValidBST(TreeNode* root) {
        ll l=INT64_MIN,r=INT64_MAX;
        return f(root,l,r);
    }
};
int main (){
    
    return 0;
}
