//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
    int x= 1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n];

        for(auto &vec: roads){
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0],vec[2]});
        }

        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        pq.push({0,0});
        vector<pair<ll,int>> dist(n,{INT64_MAX, 0}); // stors distance, ways
        dist[0]={0,1};
        int cnt=0;

        while(!pq.empty()){

            pair<ll,int>  temp=pq.top();
            pq.pop();
            for(auto &nb: adj[temp.second]){

            if(temp.first+1LL*nb.second< dist[nb.first].first  ){
                dist[nb.first].first=1LL*temp.first+nb.second;

                dist[nb.first].second=dist[temp.second].second;
                pq.push({dist[nb.first].first,nb.first});
                cnt++;
            }
            else if(temp.first+1LL*nb.second== dist[nb.first].first){
                dist[nb.first].second=(1LL*dist[nb.first].second+dist[temp.second].second)%x;
                // pq.push({dist[nb.first].first,nb.first});
                cnt++;
            }
            }
        }
        // cout<<cnt;
        return dist[n-1].second;




        
    }
};

int main (){
    
    return 0;
}