// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/?envType=problem-list-v2&envId=tree
#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        vector<int> ans;
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> p;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){ q.push(temp->left);
            p[temp->left]=temp;
            }
            if(temp->right){ q.push(temp->right);
            p[temp->right]=temp;
            }
        }

        unordered_set<TreeNode*> v;
        v.insert(t);
        q.push(t);

     while(!q.empty() && k>=0){
        int n=q.size();
        while(n-- ){
            TreeNode* temp=q.front();
            if(k==0  ){
                ans.push_back(temp->val);
            }
            //    if(!v.count(temp)) v.insert(temp);
            q.pop();
            if(temp->left&& !v.count(temp->left)){ q.push(temp->left);
            v.insert(temp->left);
            
            }
            if(temp->right && !v.count(temp->right)){ q.push(temp->right);
            v.insert(temp->right);
            
            }
            if(p.find(temp)!=p.end() && !v.count(p[temp])){ q.push(p[temp]);
                v.insert(p[temp]);
            }
            
        } 
        k--;          
        }

        return ans;

    }
};

int main (){
    
    return 0;
}