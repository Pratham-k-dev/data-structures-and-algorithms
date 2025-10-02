#include<bits/stdc++.h>
using namespace std;
int f(int i,int w,vector<int> &val, vector<int> &wt,vector<vector<int>> &dp){
        if(i<0) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        return dp[i][w]= max(f(i-1,w,val,wt,dp),
        (w>=wt[i] ?val[i]+f(i-1,w-wt[i],val,wt,dp):0));
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int> (W+1,-1));
        return f(n-1,W,val,wt,dp);
    }


    int knapsack1(int W,vector<int> &val,vector<int> &wt){//tabulation

        int n=val.size();
        vector<vector<int>> dp(n,vector<int> (W+1,0));

        for (int i = 0; i < n; i++)
        {
            for (int w = 0; w <=W; w++)// rem weights
            {
                if(i==0){ 
                  if(w>=wt[0]) dp[i][w]=val[0]; //i can take only if remaining> its weight
                    continue;
                }
                dp[i][w]= max(dp[i-1][w],//nottake
                (w>=wt[i] ?val[i]+dp[i-1][w-wt[i]]:0));//take
            }
            
        }
        return dp[n-1][W];
        
    }
int main (){
    vector<int> val={6,3,8,6,9,8,2,4,10,9};
    vector<int> wt={2,1,3,1,4,1,2,2,5,7};

    cout<<knapsack(4,val,wt);
    return 0;
}