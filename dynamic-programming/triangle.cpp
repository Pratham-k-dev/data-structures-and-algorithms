//  https://leetcode.com/problems/triangle/description/


#include<bits/stdc++.h>
using namespace std;
int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        int ans=INT_MAX;
        if(n==1) return t[0][0];
         vector<vector<int>> dp(n);
         dp[0].push_back(t[0][0]);
         for(int i=1;i<n;i++){
            for(int j=0;j<t[i].size();j++){
                int x=INT_MAX,y=INT_MAX;
                if(j >=0 && j<t[i-1].size()) x=dp[i-1][j];
                if(j-1 >=0 && j-1<t[i-1].size()) y=dp[i-1][j-1];
                dp[i].push_back(t[i][j]+min(x,y));
                if(i==n-1) ans=min(ans,dp[i][j]);
            }
         }
         return ans;
    }

    int minimumTotalOpt(vector<vector<int>>& t) { //space optimized
        int n=t.size();
        int ans=INT_MAX;
        if(n==1) return t[0][0];
         vector<int> prev(n,0);
         vector<int> cur(n,0);
         prev[0]=(t[0][0]);
         for(int i=1;i<n;i++){
            for(int j=0;j<t[i].size();j++){
                int x=INT_MAX,y=INT_MAX;
                if(j >=0 && j<t[i-1].size()) x=prev[j];
                if(j-1 >=0 && j-1<t[i-1].size()) y=prev[j-1];
                cur[j]=(t[i][j]+min(x,y));
                if(i==n-1) ans=min(ans,cur[j]);
            }
            prev=cur;
            
         }
         return ans;
    }

int main (){
    
    return 0;
}