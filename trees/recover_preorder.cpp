// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/?envType=problem-list-v2&envId=tree
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

class Solution {
    int it=0;
    void build(TreeNode* &root,vector<pair<int,int>> &a,int h){
      if(it>=a.size() ) return;

      if(it<a.size() && a[it].second==h+1 && root->left == nullptr){
        root->left=new TreeNode(a[it].first);
        it++;
        build(root->left,a,h+1);
      }
      if(it<a.size() && a[it].second==h+1 && root->right == nullptr){
         root->right=new TreeNode(a[it].first);
         it++;
        build(root->right,a,h+1);
      }
    }
public:
    TreeNode* recoverFromPreorder(string s) {
        int n=s.size();
        TreeNode* root=nullptr;
        vector<pair<int,int>> a;


        int i=0;
        int x=0;
        while(i<n && s[i]!='-') {
                x=10*x+s[i]-'0';
                i++;
            }
            root=new TreeNode(x);
        while(i<n){
            int d=0;
            while(i<n && s[i]=='-') i++,d++;
             x=0;
            while(i<n && s[i]!='-') {
                x=10*x+s[i]-'0';
                i++;
            }
            a.push_back({x,d});

        }
        build(root,a,0);
        return root;
       
        

    }
};
int main (){
    
    return 0;
}