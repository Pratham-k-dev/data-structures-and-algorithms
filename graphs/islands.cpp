//https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        unordered_map<int,unordered_map<int,bool>> v;
        queue<pair<int,int>> q;
        int cnt=0;
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1},{1,-1},{1,1},{-1,1},{-1,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                
                if(!v[i][j] && grid[i][j]=='L'){
                    
                q.push({i,j});
                    cnt++;
                    v[i][j]=true;
                    while(!q.empty()){
                        pair<int,int> temp=q.front();
                        int i1=temp.first;
                        int j1=temp.second;
                        q.pop();
                        for(auto &p:dir){
                            int x=i1+p.first;
                            int y=j1+p.second;
                            if(x>=0 && y>=0 && x<n && y<m && !v[x][y] && grid[x][y]=='L'){
                                q.push({x,y});
                                v[x][y]=true;
                            }
                        }
                    }
                    
                }
            }
        }
        
        return cnt;
    }




    int count_unique_Islands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>> ans;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] || grid[i][j]==0) continue;
                queue<pair<int,int>> q;
                vector<pair<int,int>> temp;
                q.push({i,j});
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    temp.push_back({x-i,y-j});
                    
                    for(auto it: dir){
                        int nx=x+it.first;
                        int ny=y+it.second;
                        if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && grid[nx][ny]==1){
                            q.push({nx,ny});
                            visited[nx][ny]=1;
                            temp.push_back({nx-i,ny-j});
                        }
                        
                    }
                    
                }
                
                ans.insert(temp);
                
                
            }
        }
        return ans.size();
    }



};

int main (){
    
    return 0;
}