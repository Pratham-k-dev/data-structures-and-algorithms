#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void BFS(Node* root,map<int,int> &m){//level order
    queue<pair<Node*,int> > q;
    q.push({root,0});
    
    // int x=0;
    while(!q.empty()){
        
        int n=q.size();
        while(n--){
            int x=q.front().second;
          Node* curr = q.front().first;
        q.pop();

        // Print current node's data
        if(m.find(x)==m.end()) m[x]=curr->data;

        // Push left and right children if they exist
        if (curr->left) q.push({curr->left,x-1});
        if (curr->right) q.push({curr->right,x+1});
        }
        
    }
    
}
    vector<int> topView(Node *root) {
        // code here
        map<int,int> m;
        vector<int> ans;
        BFS(root,m);
        // DFS_right(root,m,0);
        for(auto i: m) ans.push_back(i.second);
        return ans;
        
    }
};

int main (){
    
    return 0;
}