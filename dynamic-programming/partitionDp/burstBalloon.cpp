#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        // if(i>=j) return 0;
        // if(i==j) return nums[i-1];
        if (j - i == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        long long ans = 0;
        for (int k = i + 1; k < j; k++)
        {

            ans = max(ans, 1LL * nums[i] * nums[k] * nums[j] + f(i, k, nums, dp) + f(k, j, nums, dp));
        }
        return dp[i][j] = (int)ans;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));

        return f(1, nums.size(), nums, dp);
    }

    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
          vector<vector<int>> dp(n , vector<int>(n , 0));
       for (int l=2;l<n;l++)
        {
            for (int i=0;i<n-l;i++)

            {   int j=i+l;
                
                long long ans = 0;
                for (int k = i + 1; k < j; k++)
                {

                    ans = max(ans, 1LL * nums[i ] * nums[k ] * nums[j ] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = (int)ans;
            }
        }
        return dp[0][n-1];
    }
};

int main()
{

    return 0;
}