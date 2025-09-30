//https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

#include<bits/stdc++.h>
using namespace std;
class Solution {
     int f(int i,int sum,int tsum,vector<int> &nums,vector<vector<int>> &dp){
        if(i<0){
            return abs(2*sum-tsum);
            
        }
            
        if(dp[i][sum] !=-1) return dp[i][sum];
       dp[i][sum]=min( f(i-1,sum+nums[i],tsum,nums,dp),
        
        f(i-1,sum,tsum,nums,dp));
        return dp[i][sum];
    }

  public:
    int minDifference(vector<int>& nums) {// memoization
         int n=nums.size();
        // vector<int> s;
        int tsum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp (n,vector<int>(tsum+1,-1));
        return f(nums.size()-1,0,tsum,nums,dp);
        
    }

    int minDifference(vector<int> &nums){//Tabulation
        int n=nums.size();
        // vector<int> s;
        int tsum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp (n,vector<int>(tsum+1,-1));  

        for(int i=0;i<=tsum;i++){
            dp[0][i]=min(abs(2*i-tsum),abs(2*(i+nums[0])-tsum));
        }

        for (int i = 1; i < n; i++)
        {
            for (int sum = 0; sum <= tsum ; sum++)
            {
                dp[i][sum]=min(dp[i-1][sum+nums[i]],dp[i-1][sum]);
            }
            
        }
        return dp[n-1][0];


    }
};


int main (){
    
    return 0;
}