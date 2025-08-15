#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> dir={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool knight(int n,vector<vector<int>> &grid,vector<vector<bool>> &v,int x,int y,int c){
    v[x][y]=1;
    grid[x][y]=(c);
    if(c==(n*n-1)) return true;

    for(auto &i:dir){
        int dx=i.first;
        int dy=i.second;
        if(x+dx>=0 && y+dy>=0 && x+dx<n && y+dy<n && !v[x+dx][y+dy]){
            if(knight(n,grid,v,x+dx,y+dy,c+1)) return true;
            
        }
    }
    
    v[x][y]=0;
    // grid[x][y]=-1;

    return  false;




}

int main (){
    vector<vector<int>> grid(5,vector<int>(5));
    vector<vector<bool>> v(5,vector<bool>(5,false));
int c=0;
    if(knight(5,grid,v,0,0,c)){
        for(auto &i:grid){
            for(auto &j:i) cout<<j<<' ';

            cout<<endl;
        }
    }
    else cout<<-1<<endl;
    
    return 0;
}