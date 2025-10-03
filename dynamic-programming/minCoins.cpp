
//https://www.geeksforgeeks.org/problems/number-of-coins1824/1
//https://leetcode.com/problems/coin-change/description/
#include <bits/stdc++.h>

#define tc()  \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;
int f(int i, int sum, vector<int> &coins, vector<vector<int>> &dp)
{   
    if(i<0){
        if(sum==0) return 0;
        return 1e5;
    }
    if ( sum < 0)
        return 1e5;
    if (sum == 0)
        return dp[i][sum] = 0;

    if (dp[i][sum] != -1)
        return dp[i][sum];
    int x = 1 + f(i, sum - coins[i], coins, dp); //take
    int y = f(i - 1, sum, coins, dp); //not take
    

    return dp[i][sum] = min(x,y);
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

    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int tar = 1; tar <= sum; tar++)
        {
            

            int x = 1e5, y = 1e5;
           if(coins[i]<=tar) x = 1 + dp[i][tar - coins[i]]; // take
           if(i>=1) y = dp[i - 1][tar]; //not take
           
            dp[i][tar] = min(x,y);
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
        for (int tar = 1; tar <=sum; tar++)
        {
            

            int x = 1e5, y = 1e5;
           if(coins[i]<=tar) x = 1 + cur[tar - coins[i]];
           if(i>=1) y = prev[tar];
           
            cur[tar] = min(x,y);
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
