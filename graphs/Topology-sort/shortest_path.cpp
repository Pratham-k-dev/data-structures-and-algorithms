#include<bits/stdc++.h>
using namespace std;
// User function Template for C++
class Solution {// here source =0
    void DFS(int cur,vector<vector<pair<int,int>>> &adj,vector<int> &vis,vector<int>&topo){
        vis[cur]=1;
        for(auto it:adj[cur]){
                int n=it.first;
                int w=it.second;
            if(vis[n]) continue;
            DFS(n,adj,vis,topo);
        }
        topo.push_back(cur);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> vis(V,0);
        vector<int> topo;
        for(int i=0;i<V;i++){
            if(vis[i]) continue;
            DFS(i,adj,vis,topo);
            
        }
        reverse(topo.begin(),topo.end());
        vector<int> dis(V,INT_MAX); //distances from 0
        dis[0]=0;
        int i=0;
        for( i=0;i<V;i++){
            if(topo[i]==0) break;
            
        }
        while(i<V){
            for(auto it:adj[topo[i]]){
                int n=it.first;
                int w=it.second;
                dis[n]=min(dis[n],dis[topo[i]]+w);
            }
            i++;
        }
        for(i=0;i<V;i++) if(dis[i]==INT_MAX) dis[i]=-1;
        return dis;
    }
};


int main (){
    
    return 0;
}