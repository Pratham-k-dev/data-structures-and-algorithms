//https://leetcode.com/problems/largest-divisible-subset/
#include<bits/stdc++.h>
using namespace std;

 vector<int> largestDivisibleSubset(vector<int>& nums) { // most optimal space comp =O(n)
        sort(nums.begin(), nums.end());
        int n = nums.size();
       
        vector<int> dp(n, 1); // dp[i]=len(lis) ending at i
        vector<int> child(n, 0);
        for (int i = 0; i < n; i++)
            child[i] = i;
        for (int i = 1; i < n; i++) { // optimal tabulation

            for (int j = 0; j < i; j++) {

                if (nums[i] % nums[j] ==0 &&
                    1 + dp[j] > dp[i]) { // if nums[j] able to be prev of
                                         // nums[i] we consider it
                    dp[i] = 1 + dp[j];
                    child[i] = j; // child pointers to backtrac
                }
            }
        }

        int ind = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i] > dp[ind])
                ind = i;
        }

        vector<int> ans;

        while (true) {
            ans.push_back(nums[ind]);
            if (ind == child[ind])
                break; // if child points to it self end
            ind = child[ind];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
int main (){
    
    return 0;
}