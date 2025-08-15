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
bool f(TreeNode* root,int t,vector<int> &ans){// my code
    if(root== nullptr) return false;
    if(root->val==t){
        ans.push_back(root->val);
         return true;

    }
    if(f(root->left,t,ans)||f(root->right,t,ans)){

        ans.push_back(root->val);
        return true;
    }

    return false;
}
bool opt(TreeNode* root,int t,vector<int> &ans){

    if(!root) return false;
    ans.push_back(root->val);
    if(root->val== t) return true;
    if(opt(root->left,t,ans)||opt(root->right,t,ans)) return true;
    ans.pop_back();
    return false;
}


int main (){
//     TreeNode* n6 = new TreeNode(6);
// TreeNode* n7 = new TreeNode(7);
// TreeNode* n4 = new TreeNode(4);
// TreeNode* n5 = new TreeNode(5, n6, n7);
// TreeNode* n2 = new TreeNode(2, n4, n5);
// TreeNode* n3 = new TreeNode(3);
// TreeNode* root = new TreeNode(1, n2, n3);

TreeNode* n3a = new TreeNode(3);
TreeNode* n2a = new TreeNode(2, n3a, nullptr);
TreeNode* n3b = new TreeNode(3);
TreeNode* n2b = new TreeNode(2, nullptr, n3b);
TreeNode* root = new TreeNode(1, n2a, n2b);


vector<int> ans;
f(root,3,ans);
reverse(ans.begin(),ans.end());

for(int i:ans) cout<<i<<' ';
cout<<endl;
ans.clear();
opt(root,3,ans);
for(int i:ans) cout<<i<<' ';

return 0;
}