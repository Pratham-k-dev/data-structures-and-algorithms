//https://leetcode.com/problems/unique-paths/description/
#include<bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n) { //O(n*m)
        vector<vector<int>> dp (m,vector<int> (n,0));
        int ans=1;
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            dp[i][0]=1;
            for(int j=1;j<n;j++){
                int up=0,left=0;
                if(i-1>=0) up=dp[i-1][j];
                if(j-1>=0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];

    }


    int uniquePathsOpt(int m, int n) { //using c(m+n-2,m-1)
        int N = m + n - 2;  
        int r = min(m - 1, n - 1); 
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (N - r + i) / i;
        }
        return (int)ans;
    }

    // imagine boxes as points similar to eqn x1+x2+...+xn=m-1 




    class Solution {// with obstacle
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m=Grid.size();
        int n=Grid[0].size();
        
        vector<vector<int>> dp (m,vector<int> (n,0));
        
        dp[0][0]=!Grid[0][0];
        for(int i=0;i<m;i++){
            
            
            for(int j=0;j<n;j++){
                if(i==0&& j==0) continue;
                if(Grid[i][j]==1) continue;
                int up=0,left=0;
                if(i-1>=0 && Grid[i-1][j]!=1) up=dp[i-1][j];
                if(j-1>=0 && Grid[i][j-1]!=1) left=dp[i][j-1];
                dp[i][j]=up+left;
            
            }
        }
        return dp[m-1][n-1];
    }
};

int main (){
    
    return 0;
}