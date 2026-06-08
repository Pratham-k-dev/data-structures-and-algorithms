//https://leetcode.com/problems/path-with-minimum-effort/description/
#include<bits/stdc++.h>
using namespace std;

/*
Note using pair<int,pair<int,int>> insted of vector<int> in priority queue optimises run time by significant amount
*/
#define ff first
#define ss second
class Solution {// dijkstra with priority queue and pair of int ,pair as container
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();


        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        // vector<vector<int>> vis(n,vector<int>(m,0));
    
        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

        pq.push({0,{0,0}});
        dist[0][0]=0;
        // vis[0][0]=0;
        while(!pq.empty()){
            auto temp= pq.top();

            pq.pop();
            int x=temp.ss.ff;
            int y=temp.ss.ss;
            int d=temp.ff;
            if(d> dist[x][y]) continue;
            for(auto &dxy:dir ){
               int dx=dxy.ff;
                int dy=dxy.ss;
                
                if(x+dx>= 0 && x+dx<n &&y+dy>= 0 &&y+dy<m && max(d, abs(h[x][y]-h[x+dx][y+dy])) < dist[x+dx][y+dy] ){
                    // st.erase({dist[x+dx][y+dy], x+dx,y+dy});
                    dist[x+dx][y+dy]= max(d, abs(h[x][y]-h[x+dx][y+dy]));
                    pq.push({dist[x+dx][y+dy], {x+dx,y+dy}});
                    
                }
            }
                // vis[x][y]=1;

            
        } 
        return (dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1]);

        
    }
};

class Solution {//using dijkstra
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();


        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        // vector<vector<int>> vis(n,vector<int>(m,0));

        set<vector<int>> st;
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

        st.insert({0,0,0});
        dist[0][0]=0;
        // vis[0][0]=0;
        while(!st.empty()){
            auto temp= *st.begin();

            st.erase(st.begin());
            int x=temp[1];
            int y=temp[2];
            int d=temp[0];
            for(auto &dxy:dir ){
               int dx=dxy[0];
                int dy=dxy[1];
                
                if(x+dx>= 0 && x+dx<n &&y+dy>= 0 &&y+dy<m && max(d, abs(h[x][y]-h[x+dx][y+dy])) < dist[x+dx][y+dy] ){
                    st.erase({dist[x+dx][y+dy], x+dx,y+dy});
                    dist[x+dx][y+dy]= max(d, abs(h[x][y]-h[x+dx][y+dy]));
                    st.insert({dist[x+dx][y+dy], x+dx,y+dy});
                    
                }
            }
                // vis[x][y]=1;

            
        } 
        return (dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1]);

        
    }



};
class Solution {//using BFS,Binary Search
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    bool pred(int ans, vector<vector<int>> &h,vector<vector<int>> &vis,int timer){
        int n=h.size();
        int m = h[0].size();
        if(n==1 && m==1) return true;
        queue<vector<int>> q;
        q.push({0,0});
        vis[0][0]= timer;
        while(!q.empty()){
            vector<int> cur= q.front();
            q.pop();
            int x=cur[0];
            int y=cur[1];

            for(auto &dxy: dir){
                int dx= dxy[0];
                int dy= dxy[1];
                if(x+dx>=0 && y+dy>=0 && x+dx<n && y+dy<m && abs(h[x+dx][y+dy]- h[x][y]) <= ans && vis[x+dx][y+dy] !=timer){
                    if(x+dx== n-1&& y+dy== m-1) return true;
                    q.push({x+dx,y+dy});
                    vis[x+dx][y+dy]=timer;

                }
            }

        }
        return 0;

    }
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();


        vector<vector<int>> vis(n,vector<int>(m,0));
        int timer=1;//timer is used to avoid reinitialization of visited matrix  every time
        int l=0,r=1e6;
        while(l<=r){//BS on answers pattern: F F F T T T...
            int mid=l+(r-l)/2;
            if(pred(mid,h,vis,timer)) r=mid-1;
            else l=mid+1;
            timer++;

        }
        return l;
        
    }
};
int main (){
    
    return 0;
}