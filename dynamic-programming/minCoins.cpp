#include <bits/stdc++.h>

#define tc()  \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;
int f(int i, int sum, vector<int> &coins, vector<vector<int>> &dp)
{
    if (i >= coins.size() || sum < 0)
        return 1e5;
    if (sum == 0)
        return dp[i][sum] = 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];
    int x = 1 + f(i, sum - coins[i], coins, dp);
    int y = f(i - 1, sum, coins, dp);
    int z = 1 + f(i - 1, sum - coins[i], coins, dp);

    return dp[i][sum] = min(min(x, y), z);
}

int minCoins(vector<int> &coins, int sum)
{ // memoization

    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    f(n - 1, sum, coins, dp);
    if (dp[n - 1][sum] >= 1e5)
        return -1;
    else
        return dp[n - 1][sum];
}
int minCoins2(vector<int> &coins, int sum)
{ // tabulation

    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    for (int i = 0; i < n; i++)
    {
        for (int tar = 0; tar <= sum; tar++)
        {
            if (tar == 0)
            {
                dp[i][tar] = 0;
                continue;
            }

            int x = 1e5, y = 1e5, z = 1e5;
           if(coins[i]<=tar) x = 1 + dp[i][tar - coins[i]];
           if(i>=1) y = dp[i - 1][tar];
           if(i>=1 && tar>=coins[i]) z = 1 + dp[i - 1][tar - coins[i]];
            dp[i][tar] = min(min(x, y), z);
        }
    }
    return dp[n-1][sum];
}
int minCoinsOpt(vector<int> &coins,int sum){// space optimized

    int n = coins.size();

    // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    vector<int> prev(sum+1,0);
    vector<int> cur(sum+1,0);
    
    for (int i = 0; i < n; i++)
    {
        for (int tar = 0; tar <=sum; tar++)
        {
            

            int x = 1e5, y = 1e5, z = 1e5;
           if(coins[i]<=tar) x = 1 + cur[tar - coins[i]];
           if(i>=1) y = prev[tar];
           if(i>=1 && tar>=coins[i]) z = 1 + prev[tar - coins[i]];
            cur[tar] = min(min(x, y), z);
        }
        prev=cur;
        
    }
    return (prev[sum]>=1e5?-1:prev[sum]);

}

int main()
{

    tc()
    {
        int n, sum;
        cin >> n >> sum;
        vector<int> coins(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }

        cout << minCoins(coins, sum);
    }
    return 0;
}
