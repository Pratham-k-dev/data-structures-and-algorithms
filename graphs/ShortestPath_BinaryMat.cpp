//https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {//using BFS
        int d=1;
        int n=grid.size();

        queue<pair<int,int>> q;
        
        if(grid[0][0]==0){q.push({0,0});
        if(n==1) return 1;
        };

        int f=0;
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        while(!q.empty()){
            int s=q.size();
            while(s--){
            auto [x,y] = q.front();
            q.pop(); 
            for(auto &dxy:dir){
                int dx=dxy[0];
                int dy=dxy[1];
                if(x+dx >=0 && y+dy< n &&x+dx <n && y+dy>=0 && grid[x+dx][y+dy]==0){
                    if(x+dx== n-1 && y+dy==n-1){
                        f=1;
                        break;
                    }
                    grid[x+dx][y+dy]=1;
                    q.push({x+dx,y+dy});

                }
            }

            if(f==1) break;
            }

            if(f==1) break;
            d++;


        }

        return (f==1?d+1:-1);


        
    }
};

int main (){
    
    return 0;
}