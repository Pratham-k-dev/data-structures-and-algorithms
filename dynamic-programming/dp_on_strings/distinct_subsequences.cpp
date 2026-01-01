//https://leetcode.com/problems/distinct-subsequences/
#include<bits/stdc++.h>
using namespace std;

    int f(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){ //memoization method
        if(j>=s2.size()) return 1;
        if(i>=s1.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int takes=0;
        if(s1[i]==s2[j]) takes=f(s1,s2,i+1,j+1,dp);
        int nottakes=f(s1,s2,i+1,j,dp);
        return dp[i][j]=takes+nottakes;

    }
    int f2(string s1,string s2){//tabulation
          int n=s1.size();
            int m=s2.size();
            vector<vector<double>> dp(n+1,vector<double> (m+1,0));
            for(int i=0;i<m;i++) dp[n][i]=0;
            dp[n][m]=1;
            for(int i=n-1;i>=0;i--){
                for(int j=m;j>=0;j--){
                    if(j==m) dp[i][j]=1;
                    else{
                        double takes=0;
                        if(s1[i]==s2[j]) takes=dp[i+1][j+1];
                        double nottakes=dp[i+1][j];
                        dp[i][j]=takes+nottakes;
                    }
                }
            }

            return (int)dp[0][0];
    }

    // in Leetcode the above gives integer overflow even in Long long, so we used double here

int main (){
    string s1="babgbag";
    string s2="bag";
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    cout<<f2(s1,s2)<<endl;
    return 0;
}