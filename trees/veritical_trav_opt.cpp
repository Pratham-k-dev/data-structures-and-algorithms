#include<bits/stdc++.h>
using namespace std;

 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    void DFS(TreeNode* root,map<int,map<int,multiset<int>>> &m,int x,int y){
        if(root== nullptr) return;
        DFS(root->left,m,x-1,y+1);
        DFS(root->right,m,x+1,y+1);
        m[x][y].insert(root->val);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> m;
        DFS(root,m,0,0);
        for(auto i: m){
            vector<int> temp;
            for(auto j: i.second){
                for(auto k: j.second){
                    
                     temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;


    }
};

int main (){
    
    return 0;
}