//https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
#include<bits/stdc++.h>
using namespace std;
 int f(int i,int cap,vector<int> &val,vector<int> &wt,vector<vector<int>> &dp){
        if(i<0){
            return 0;
        }
        if(cap <0){
            return 0;
        }
        if(cap==0) return dp[i][cap]= 0;
        if(dp[i][cap]!=-1) return dp[i][cap];
        int take=0;
        if(cap>=wt[i]) take=val[i]+f(i,cap-wt[i],val,wt,dp);
        int nottake=f(i-1,cap,val,wt,dp);
        
        return dp[i][cap]= max(take,nottake);
        
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity){ //memoization
        
        int n=wt.size();

        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        f(n-1,capacity,val,wt,dp);
        return dp[n-1][capacity];
    }



    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // Tabulation
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,0));
        
        
        
        
        for(int i=0;i<n;i++){
            for(int cap=0;cap<=capacity;cap++ ){
                int take=0;
                if(cap>=wt[i]) take=val[i]+dp[i][cap-wt[i]];
                int nottake=0;
                if(i>=1)nottake= dp[i-1][cap];
        
                dp[i][cap]= max(take,nottake);
            }
        }
        return dp[n-1][capacity];
    }

int main (){
    
    return 0;
}