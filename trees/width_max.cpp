//https://leetcode.com/problems/maximum-width-of-binary-tree/?envType=problem-list-v2&envId=tree
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

 #define ll long long
class Solution {
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,1});
        int ans=1;
        while(!q.empty()){
            int n=q.size();
            int f=0;
            int l=q.front().second;
            int r=l;

            while(n--){
                r=q.front().second;
                TreeNode* temp=q.front().first;
                q.pop();
                if(temp->left) q.push({temp->left,2LL*r});
                if(temp->right) q.push({temp->right,2LL*r+1});

                
            }
            ans=max(ans,(int)(1LL*r-l+1));
        }
        return ans;
    }
};
int main (){
    
    return 0;
}