//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool DFS(int cur,vector<int> adj[],vector<int> &vis,vector<int> &pathvis){
        vis[cur]=1;
        pathvis[cur]=1;
        for(int i:adj[cur]){
            
             if(vis[i]){
                if(pathvis[i]){ 
                    
                    
                    return true;
                
                    
                    
                }
                
            }
            else if( DFS(i,adj,vis,pathvis)) return true;
            
        }
        pathvis[cur]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int n=edges.size();
        vector<int> adj[V];
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]) continue;
            
            if(DFS(i,adj,vis,pathvis)) return true;
        }
        return false;
        
        
        
    }
};

int main (){
    
    return 0;
}