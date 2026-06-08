//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &v: flights){
            adj[v[0]].push_back({v[1],v[2]});
            
        }
        
        set<vector<int>> st;
        vector<pair<int,int>> d(n,{INT_MAX, -1});
        
        d[src]={0,-1};
        st.insert({-1,0,src});
        while(!st.empty()){//using dijkstra
            auto cur= *st.begin();
            st.erase(st.begin());
            if(cur[0] >= k) continue;
            for(auto &nb : adj[cur[2]]){
                
                if( cur[1]+ nb.second < d[nb.first].first ){
                   
                    st.insert({cur[0]+1,cur[1]+ nb.second,nb.first});
                    d[nb.first].first=cur[1]+ nb.second;
                    d[nb.first].second=cur[0]+1;
                   
                }

            }
            

        }
        return (d[dst].first==INT_MAX? -1 : d[dst].first);

    }
};
int main (){
    
    return 0;
}