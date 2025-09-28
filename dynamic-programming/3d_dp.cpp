#include<bits/stdc++.h>
using namespace std;
class Solution {
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> prev (m,vector<int>(m,-1));
        vector<vector<int>> cur (m,vector<int>(m,-1));
        prev[0][m-1]=grid[0][0]+grid[0][m-1];
        for(int i=1;i<n;i++){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi=-1;
                    for(int d1=-1;d1<=1;d1++){
                        for(int d2=-1;d2<=1;d2++){
                                if(j1+d1>=0 && j2+d2>=0 && j1+d1<m&& j2+d2<m &&prev[j1+d1][j2+d2]!=-1){
                                    maxi=max(maxi,prev[j1+d1][j2+d2]);
                                }
                        }

                    }

                   if(maxi!=-1) cur[j1][j2]=grid[i][j1]+(j1!=j2 ? grid[i][j2]:0)+maxi;
                    if(i==n-1 ) ans=max(ans,cur[j1][j2]);
                }
            }
            prev=cur;
        }
        return ans;
    }
};

int main (){
    
    return 0;
}