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
 
    struct cmp{
        using value_type=pair<pair<int,int>,int>;
        bool operator()(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
            if(a.first.first != b.first.first) return a.first.first > b.first.first;
             

            if(a.first.second != b.first.second) return a.first.second > b.first.second;
            

            if(a.second != b.second) return a.second > b.second;
            

            return false;
        }
    };
class Solution {

    void DFS(TreeNode* root, priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>> ,cmp> &pq,int x,int y){
        if(root== nullptr) return;
        DFS(root->left,pq,x-1,y+1);
        DFS(root->right,pq,x+1,y+1);
        pq.push({{x,y},root->val});
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,cmp> pq;//syntax: priority_queue<T,container<T>,comparator>
        DFS(root,pq,0,0);
        int cnt=0;
        while(!pq.empty()){
            vector<int> temp;
            int col=pq.top().first.first;

            while(!pq.empty() && pq.top().first.first==col){
            temp.push_back(pq.top().second);
            pq.pop();
            // if(++cnt>1000) break; //debug
            }
            ans.push_back(temp);
            // if(++cnt>1000) break;

        }
        for(auto i: ans){
            for(auto j :i) cout<<j<<' ';

            cout<<endl;
        }
        return ans;
    }
};

int main (){
    TreeNode* root = new TreeNode(3);
root->left = new TreeNode(9);
root->right = new TreeNode(20);
root->right->left = new TreeNode(15);
root->right->right = new TreeNode(7);
Solution test;
test.verticalTraversal(root);
    
    return 0;
}