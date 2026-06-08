#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {//TC: O(ElogV)
        // Code here
        vector<pair<int,int>> adj[V];
        for(auto &ed: edges){
            adj[ed[0]].push_back({ed[1],ed[2]});
            adj[ed[1]].push_back({ed[0],ed[2]});
            
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq; //min heap
        pq.push({0,src});
        
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        int cnt=0;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int d=temp.first;
            int nd=temp.second;
            cnt++;
            for(auto &n: adj[nd]){
                if( d+n.second < dist[n.first]){
                    dist[n.first]=d+n.second;
                    pq.push({d+n.second,n.first});
                }
            }
            
        }
        // cout<<cnt;
        return dist;
    }
    vector<int> dijkstraSet(int V, vector<vector<int>> &edges, int src) {//using set (faster)
        // Code here
        vector<pair<int,int>> adj[V];
        for(auto &ed: edges){
            adj[ed[0]].push_back({ed[1],ed[2]});
            adj[ed[1]].push_back({ed[1],ed[2]});
            
        }
        
        set<pair<int,int>> st;
        st.insert({0,src});
        
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        int cnt=0;
        while(!st.empty()){
            auto temp=st.begin();
            st.erase(st.begin());
            int d=temp->first;
            int nd=temp->second;
            cnt++;
            for(auto &n: adj[nd]){
                if(d+n.second < dist[n.first]){
                   if(dist[n.first] != INT_MAX) st.erase({dist[n.first],n.first});
                    dist[n.first]=d+n.second;
                    
                    st.insert({d+n.second,n.first});
                }
            }
            
        }
        cout<<cnt;
        return dist;
    }
};

int main (){
vector<vector<int>> r={ {0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
Solution s;
s.dijkstraSet(3,r,2);


    return 0;
}