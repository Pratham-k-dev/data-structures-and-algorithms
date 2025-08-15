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
void preorder(TreeNode* root){
    if(!root) return;
    cout<<root->val<<' ';
    preorder(root->left);
    preorder(root->right);
}
class Solution {
    int it=0;
    void build(TreeNode* &root,vector<pair<int,int>> &a,int h){
      if(it>=a.size() ) return;

      if(a[it].second==h+1 && root->left == nullptr){
        root->left=new TreeNode(a[it].first);
        it++;
        build(root->left,a,h+1);
      }
       if(a[it].second==h+1 && root->right == nullptr){
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
                x+=10*x+s[i]-'0';
                i++;
            }
            root=new TreeNode(x);
        while(i<n){
            int d=0;
            while(i<n && s[i]=='-') i++,d++;
             x=0;
            while(i<n && s[i]!='-') {
                x+=10*x+s[i]-'0';
                i++;
            }
            a.push_back({x,d});

        }
        for(auto i:a){
            cout<<i.first<<' '<<i.second<<endl;
        }
        build(root,a,0);
        return root;
       
        

    }
};

int main (){
    Solution o;
    TreeNode* root;
    string s="1-401--349---90--88";
    
    root=o.recoverFromPreorder(s);
    cout<<endl;
    preorder(root);

    
    return 0;
}