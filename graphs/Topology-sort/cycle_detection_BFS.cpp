//using kahn's algo/toposort

#include<bits/stdc++.h>
using namespace std;
 bool cycle_Detection(int V, vector<vector<int>>& edges) {
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
        
        return (ans.size()!=V); //the only problem why it didnt reach size of total nodes is a cycle
    }

int main (){
    
    return 0;
}