//https://leetcode.com/problems/longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;
int f(vector<int> &nums,int i,int prev,vector<vector<int>> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int pick=0,notpick=0;
        if(prev==0 || nums[i]>nums[prev-1]) pick=1+f(nums,i+1,i+1,dp);
        notpick=f(nums,i+1,prev,dp);
        return dp[i][prev]=max(pick,notpick);
    }

    int lengthOfLIS(vector<int>& nums) {//memoization
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(nums,0,0,dp);
    }
    int lengthOfLIS2(vector<int>& nums) {//Tabulaton
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i; prev >= 0; prev--) {
                int pick = 0, notpick = 0;
                if (prev == 0 || nums[i] > nums[prev - 1])
                    pick = 1 + dp[i+1][i+1];
                notpick = dp[i+1][prev];
                 dp[i][prev] = max(pick, notpick);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {//space Optimization
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        vector<int> prv(n+1,0);
        vector<int> cur(n+1,0);

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i; prev >= 0; prev--) {
                int pick = 0, notpick = 0;
                if (prev == 0 || nums[i] > nums[prev - 1])
                    pick = 1 + prv[i+1];
                notpick = prv[prev];
                 cur[prev] = max(pick, notpick);
            }
            prv=cur;
        }
        return cur[0];
    }

int main (){
    
    return 0;
}