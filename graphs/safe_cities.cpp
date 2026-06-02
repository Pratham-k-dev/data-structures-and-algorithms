//https://leetcode.com/problems/find-eventual-safe-states/description/

#include<bits/stdc++.h>
using namespace std;

class Solution2 {// better version 
    bool Dfs(int i,vector<vector<int>> &adj, vector<int> &vis,vector<int> &pathvis, vector<int> &safe){

        int f=1;
        vis[i]=1;
        pathvis[i]=1;
        for(int x:adj[i]){
            if(pathvis[x] ) {

            f=0;
            break;
            } 
            if(vis[x] && !safe[x]) {f=0;
            break;}
            if(vis[x]) continue;
           
            if(!Dfs(x,adj,vis,pathvis,safe)) {f=0;break;}
            
        }
        pathvis[i]=0;
        if(f) safe[i]=1;
        return f;



    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> safe(n,0);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(vis[i])continue;

            Dfs(i,graph,vis,pathvis,safe);
        }

        for(int i=0;i<n;i++){
            if(safe[i]) ans.push_back(i);
        }

        return ans;

        
    }
};
class Solution {
    
  

    bool  DFS(int cur,vector<vector<int>> &graph,vector<int> &vis,vector<int> &pathvis,vector<int> &check){
        vis[cur]=1;
        pathvis[cur]=1;
        // a[cur]=0;
        for(int &i:graph[cur]){

            if(!vis[i]){
                 
                  
                  if(DFS(i,graph,vis,pathvis,check)){
                // a[cur]=0;
                return true;
                }
                  
            }
            else if(pathvis[i])  {
                // a[cur]=0;
                
                return true;
            }
            
            
           
        }
         // If we reach here, no cycle was found for this path → safe node
        check[cur]=1;
            pathvis[cur]=0;
        return false;
        

    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n=graph.size();
        
        vector<int> vis(n,0),check(n,0),ans;
            vector<int> pathvis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            DFS(i,graph,vis,pathvis,check);
        }
        for(int i=0;i<n;i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
        
    }
};

class Using_TopoSort {
    
  

   
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V=graph.size();
        vector<vector<int>> rgraph(V);
        vector<int> indeg(V,0), a(V,0);

        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                rgraph[graph[i][j]].push_back(i);
                indeg[i]++;
            }

        }
        
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){ q.push(i);
            
            a[i]=1;
            
            }
        }
        vector<int> ans;

        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i: rgraph[cur]){
                
                
                indeg[i]--;
                if(indeg[i]==0){ q.push(i);
                  a[i]  =1;
                }
            }
        }
        for(int i=0;i<V;i++){


         if(a[i]) ans.push_back(i);
        }
        return ans;
    }
};

int main (){
    
    return 0;
}

