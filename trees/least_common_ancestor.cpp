#include<bits/stdc++.h>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {//optimal
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root== q) return root;
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(l && r ) return root;

        return (l?l :r);
    }
};

class Brute_Force {
    bool findp(TreeNode* root,TreeNode* p,unordered_set<TreeNode*> &st){
        if(!root) return false;
        st.insert(root);
        if(root==p) return true;
        if(findp(root->left,p,st) || findp(root->right,p,st)) return true;
        st.erase(root);
        return false;

    }
    bool findq(TreeNode* root,TreeNode* q,unordered_map<int,TreeNode*> &m,int y){
        if(!root) return false;
        m[y]=(root);
        if(root==q) return true;
        if(findq(root->left,q,m,y+1) || findq(root->right,q,m,y+1)) return true;
        m.erase(y);
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> st;
        unordered_map<int,TreeNode*> m;
        findp(root,p,st);
        findq(root,q,m,0);
        TreeNode* ans=root;
        int l=0;
        for(auto &it: m){ 
            if(st.count(it.second) && it.first>l){
                l=it.first;
                ans=it.second;
            }
        }

        return ans;


    }
};

int main (){
    
    return 0;
}