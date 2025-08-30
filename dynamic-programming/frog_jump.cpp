//https://www.geeksforgeeks.org/problems/geek-jump/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
    
    int f(int n,vector<int>& h,vector<int> &dp){
        if(n==0) return (dp[0]=0);
        if(dp[n] != -1) return dp[n];
        int x=INT_MAX,y=INT_MAX;
       if(n>=1) x=f(n-1,h,dp)+abs(h[n]-h[n-1]);
       if(n>=2) y=f(n-2,h,dp)+abs(h[n]-h[n-2]);
       
       return dp[n]=min(x,y);
    }
  public:
    int minCost(vector<int>& height) { //memoization (includes stack space)
        // Code here
        int n=height.size();
        vector<int> dp(n,-1);
        return f(n-1,height,dp);
    }
    int minCost2(vector<int> &height){ // tabulation (down to , no stack space)
        int n=height.size();
        vector<int> dp (n,0);
        for(int i=1;i<n;i++){

            dp[i]=min(dp[i-1]+abs(height[i]-height[i-1]),(i>=2)? dp[i-2]+abs(height[i]-height[i-2]) : INT_MAX);
        }
        return dp[n-1];

    }
    int minCost3(vector<int> &height){ //space optimizaation 
          int n=height.size();
        int prev2=0,prev=0;
        
        for(int i=1;i<n;i++){
            int temp=prev2;
            prev2=prev;
            
            prev=min(prev+abs(height[i]-height[i-1]),(i>=2 ? temp+abs(height[i]-height[i-2] ): INT_MAX));
        }
        return prev;

    }
};
int main (){
    
    return 0;
}