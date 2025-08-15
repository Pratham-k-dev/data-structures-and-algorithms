//https://leetcode.com/problems/flood-fill/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {//using BFS
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        unordered_map<int,unordered_map<int,int>> v;
        queue<pair<int,int>> q;
        int val=image[sr][sc];
        q.push({sr,sc});
        v[sr][sc]=1;
        while(!q.empty()){
        //  auto &[x ,y] = q.front();
        int x=q.front().first;
        int y=q.front().second;
            image[x][y]=color;
            q.pop();
            if(x+1 < m && image[x+1][y]==val && !v[x+1][y]){
                q.push({x+1,y});
                v[x+1][y]=1;    
            }
            if(x-1 >=0 && image[x-1][y]==val && !v[x-1][y]){
                q.push({x-1,y});
                v[x-1][y]=1;
            }
            if(y+1 < n && image[x][y+1]==val && !v[x][y+1]){
                q.push({x,y+1});
                v[x][y+1]=1;
            }
            if(y-1 >=0 && image[x][y-1]==val && !v[x][y-1]){
                q.push({x,y-1});
                v[x][y-1]=1;
            }
        }
        return image;

    }
};

int main (){
    
    return 0;
}