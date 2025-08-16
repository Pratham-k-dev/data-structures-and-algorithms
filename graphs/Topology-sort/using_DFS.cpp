#include<bits/stdc++.h>
using namespace std;
class Solution {
    void DFS(int cur,vector<int> adj[],vector<int> &visited,stack<int> &s){
        visited[cur]=1;
        
        for(int i:adj[cur]){
            if(!visited[i]) DFS(i,adj,visited,s);
        }
        s.push(cur);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back( edges[i][1]) ;
        }
        vector<int> visited(V,0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(visited[i]) continue;
            
            DFS(i,adj,visited,s);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main (){
    
    return 0;
}