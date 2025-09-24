//https://leetcode.com/problems/house-robber-ii/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    
    int findMaxSum(vector<int>& arr,int l,int r) {
        // code here
        int n=arr.size();
        vector<int> dp(n,-1);
        dp[l]=arr[l];
        
        for(int i=l+1;i<=r;i++){
            int pick=arr[i]+((i-2>=l)?dp[i-2]:0);
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
            
        }
        return dp[r];
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(findMaxSum(nums,0,n-2),findMaxSum(nums,1,n-1));
         
    }
};

int main (){
    
    return 0;
}