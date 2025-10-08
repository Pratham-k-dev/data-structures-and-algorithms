#include<bits/stdc++.h>
using namespace std;
int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0)); //one based indexing
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];// if matched also add previous match else it remains 0
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
        
    }

int main (){
    
    return 0;
}