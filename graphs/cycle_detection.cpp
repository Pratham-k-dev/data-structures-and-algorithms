#include<bits/stdc++.h>
using namespace std;

class Cycle_Detect_In_undirected{

    public:
    bool usingBFS(vector<vector<int>> &edges,int V){
         vector<int> a[V];//adjacency list
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            a[u].push_back(v);
            a[v].push_back(u);
        }
        
        vector<int> visited(V,0);
        
        
        for(int i=0;i<V;i++){
            if(visited[i]) continue;
            queue<pair<int,int>> q;
            q.push({i,-1}); //current,parent
            visited[i]=1;
            while(!q.empty()){
                

                int cur=q.front().first;
                int par=q.front().second;
                q.pop();
                for(int j:a[cur]){
                    if(!visited[j]){
                        q.push({j,cur});
                        visited[j]=1;
                    }
                    else if(j != par) return true; //if visited and not parent cycle detected
                }
                
            }
            
            
        }
        
        return false;

    }

    bool DFS(int cur,int par,vector<int> a[],vector<int>&visited){
        visited[cur]=1;
        for(int i: a[cur]){
            if(!visited[i]){
               if( DFS(i,cur,a,visited)) return true;
            }
            else if(i != par) return true;
        }

        return false;
    }
    bool usingDFS(vector<vector<int>> &edges,int V){
         vector<int> a[V];//adjacency list
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            a[u].push_back(v);
            a[v].push_back(u);
        }
        
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]) continue;

            if(DFS(i,-1,a,visited))  return true;
        }
        return false;
    }

};

int main (){
    
    return 0;
}