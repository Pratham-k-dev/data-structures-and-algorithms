//https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1
#include<bits/stdc++.h>
using namespace std;
// User function Template for C++
class Solution {
    
    void f(string &s,int i,int j,vector<vector<int>> &dp,vector<vector<int>> &dpf){
        if(i>j) return ;
        if(i==j) {
            if(s[i]=='T') dp[i][j]=1,dpf[i][j]=0;
            else dp[i][j]=0,dpf[i][j]=1;
            return ;
            
        }
        if(dp[i][j]!=-1 && dpf[i][j]!=-1) return;
        
        int n=s.size();
        int ans=0,ansf=0;
        
        for(int k=i+1;k<j;k+=2){
            f(s,i,k-1,dp,dpf);
            f(s,k+1,j,dp,dpf);
            int res1=dp[i][k-1],res2=dp[k+1][j];
            int resf1=dpf[i][k-1],resf2=dpf[k+1][j];
            
            
            if(s[k]=='&'){ 
                ans+=(res1*res2);
                ansf+=(res1*resf2)+(resf1*res2)+(resf1*resf2);
            
            }
            else if(s[k]=='|'){ 
            ans+=(res1*resf2)+(resf1*res2)+(res1*res2);
            ansf+=resf1*resf2;
            }
            else{ 
                ans+=res1*resf2+resf1*res2;
                ansf+=(res1*res2)+(resf1*resf2);
            }
            
            
            
        }
        
        dp[i][j]=ans;
        dpf[i][j]=ansf;
        
    }
  public:
    int countWays(string &s) {
        // code here
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<int>> dpf(n,vector<int>(n,-1));
         f(s,0,n-1,dp,dpf);
         return dp[0][n-1];
        
    }
};

int main (){
    
    return 0;
}