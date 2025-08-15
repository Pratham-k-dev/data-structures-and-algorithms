#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
            int m=grid.size();
        int n=grid[0].size();
        // unordered_map<int,unordered_map<int,int>> v;
        queue<pair<int,int>> q;
        int n1=0;
        vector<pair<int,int>> rot;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j}); //pushing initially rotten
                }
                else if(grid[i][j]==1){
                    n1++;
                }
            }
        }
        if(!n1) return 0; // no fresh 
        
        int c=-1,c1=0;
        while(!q.empty()){
        
        c++; //expanding for every level
        int s=q.size();
        while(s--){
        int x=q.front().first;
        int y=q.front().second;
           
            q.pop();
            if(x+1 < m && grid[x+1][y]==1){
                q.push({x+1,y});
            grid[x+1][y]=2;
                c1++;

            }
            if(x-1 >=0 && grid[x-1][y]==1){
                q.push({x-1,y});
                grid[x-1][y]=2;
                c1++;
            }
            if(y+1 < n && grid[x][y+1]==1){
                q.push({x,y+1});
                grid[x][y+1]=2;
                c1++;
            }
            if(y-1 >=0 && grid[x][y-1]==1){
                q.push({x,y-1});
                grid[x][y-1]=2;
                c1++;
            }
        }
        }

        if(c1==n1) return c; //if all become rotten return time
        return -1;//else cannot make everything rotten
    }
};

int main (){
    
    return 0;
}