//https://leetcode.com/problems/find-eventual-safe-states/description/

#include<bits/stdc++.h>
using namespace std;
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

int main (){
    
    return 0;
}

