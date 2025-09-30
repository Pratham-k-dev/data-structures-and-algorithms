// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool f(int i, int t, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (t == 0)
            return true;
        if (i < 0)
            return false;
        if (i == 0)
        {
            if (arr[i] == t)
                return true;
            return false;
        }

        if (dp[i][t] != -1)
            return dp[i][t];
        bool notpick = f(i - 1, t, arr, dp);
        bool pick = false;
        if (t >= arr[i])
            pick = f(i - 1, t - arr[i], arr, dp);
        return dp[i][t] = (pick || notpick);
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    { // memoization
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return f(n - 1, sum, arr, dp);
    }

    bool isSubsetSum2(vector<int> &arr, int sum)
    { // tabulation
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
         if(arr[0]<=sum) dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int t = 1; t <= sum; t++)
            {

                bool notpick = dp[i - 1][t];
                bool pick = false;
                if (t >= arr[i])
                    pick = dp[i - 1][t - arr[i]];
                dp[i][t] = (pick || notpick);
                
            }
        }

        return dp[n-1][sum];
    }
    bool isSubsetSum3(vector<int> &arr, int sum)
    { // spaceOptimized
        
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        vector<int> prev (sum+1,0);
        vector<int> cur (sum+1,0);
        prev[0]=1;
         if(arr[0]<=sum) prev[arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= sum; t++)
            {

                bool notpick = prev[t];
                bool pick = false;
                if (t >= arr[i])
                    pick = prev[t - arr[i]];
                cur[t] = (pick || notpick);
                
            }
            prev=cur;
        }

        return cur[sum];
    }
};

int main()
{

    return 0;
}