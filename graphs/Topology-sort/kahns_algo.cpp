#include<bits/stdc++.h>
using namespace std;
class Solution {//using BFS and indegree
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        vector<int> indeg(V,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int cur=q.front();
            ans.push_back(cur);
            q.pop();
            for(int i: adj[cur]){
                
                
                indeg[i]--;
                if(indeg[i]==0) q.push(i);
                    
                
            }
        }
        
        return ans;
    }
};

int main (){
    
    return 0;
}