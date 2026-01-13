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
    vector<int> printing(vector<int> &nums){// TC=>O(n^2) , sc=> O(n)
        int n=nums.size();
       vector<int> dp(n,1);//dp[i]=len(lis) ending at i
       vector<int> child(n,0);
       for(int i=0;i<n ;i++) child[i]=i;
       for(int i=1;i<n;i++){// optimal tabulation
        
        for(int j=0;j<i;j++){
            
            if(nums[j]<nums[i] && 1+dp[j]>dp[i]) {// if nums[j] able to be prev of nums[i] we consider it
                dp[i]=1+dp[j];
                child[i]=j;// child pointers to backtrac
            }

        }
       }
   
       int ind=0;
       for(int i=1;i<n;i++){
        if(dp[i]>dp[ind]) ind=i;
       }

       vector<int> ans;
      
       while(true){
            ans.push_back(nums[ind]);
            if(ind== child[ind]) break; // if child points to it self end
            ind=child[ind];
       }

       reverse(ans.begin(),ans.end());


       return ans;
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

    
    int lengthOfLIS3(vector<int>& nums) {//space Optimization
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
    vector<int> nums ={10,9,2,5,3,7,101,18};
    vector<int> ans=printing(nums);

    for(int x:ans) cout<<x<<' ';
    cout<<endl;
    return 0;
}