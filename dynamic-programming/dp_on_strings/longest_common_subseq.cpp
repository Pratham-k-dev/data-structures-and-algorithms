//https://leetcode.com/problems/longest-common-subsequence/cf


// to print LCS refer : https://www.geeksforgeeks.org/dsa/printing-longest-common-subsequence/
#include<bits/stdc++.h>
using namespace std;
 int f(int i1,int i2,string &s1,string &s2,vector<vector<int>> &dp){ // longest fron s1[0 to i1],s2[0 to i2]
        if(i1<0 || i2<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(s1[i1]==s2[i2]){
            return dp[i1][i2]= 1+f(i1-1,i2-1,s1,s2,dp);// if index matches move both indexes back
        }
         return dp[i1][i2]= max(f(i1,i2-1,s1,s2,dp),f(i1-1,i2,s1,s2,dp)); // if doesnt match move one index back
    }
     int longestCommonSubsequence(string text1, string text2) {//memoization
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        f(n-1,m-1,text1,text2,dp);
        return dp[n-1][m-1];

    }

     int longestCommonSubsequence1(string text1, string text2) { //tabulation
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
       
        

        for(int i1=0;i1<n;i1++){
            for(int i2=0;i2<m;i2++){
                if(text1[i1]==text2[i2]){
                     dp[i1][i2]=1+(i1>0 && i2>0?dp[i1-1][i2-1] :0);
                }
                else{
                    int x=0,y=0;
                    if(i1>0) x=dp[i1-1][i2];
                    if(i2>0) y=dp[i1][i2-1];
                    dp[i1][i2]=max(x,y);
                }
            }
        }
        return dp[n-1][m-1];

    }
     int longestCommonSubsequence_1(string text1, string text2) { //tabulation , 1 based  indexed
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       
        

        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=m;i2++){
                if(text1[i1-1]==text2[i2-1]){
                     dp[i1][i2]=1+dp[i1-1][i2-1];
                }
                else{
                    
                     int x=dp[i1-1][i2];
                     int y=dp[i1][i2-1];
                    dp[i1][i2]=max(x,y);
                }
            }
        }
        return dp[n][m];

    }



     int longestCommonSubsequence3(string text1, string text2) { //space optimized
        int n=text1.size(),m=text2.size();
        

        vector<int> prev(m,0);
        vector<int> cur(m,0);
        

        for(int i1=0;i1<n;i1++){
            for(int i2=0;i2<m;i2++){
                if(text1[i1]==text2[i2]){
                     cur[i2]=1+(i1>0 && i2>0?prev[i2-1] :0);
                }
                else{
                    int x=0,y=0;
                    if(i1>0) x=prev[i2];
                    if(i2>0) y=cur[i2-1];
                    cur[i2]=max(x,y);
                }
            }
            prev=cur;
        }
        return cur[m-1];

    }

int main (){
    
    return 0;
}