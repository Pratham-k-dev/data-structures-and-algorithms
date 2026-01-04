// https://leetcode.com/problems/edit-distance/
#include <bits/stdc++.h>
using namespace std;
int f(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0)
        return i + 1;
    if (i < 0)
        return j + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] != s2[j])
    {
        int case1 = 1 + f(s1, s2, i - 1, j, dp);     // deleting
        int case2 = 1 + f(s1, s2, i, j - 1, dp);     // insert
        int case3 = 1 + f(s1, s2, i - 1, j - 1, dp); // replace

        return dp[i][j] = min({case1, case2, case3});
    }
    return dp[i][j] = f(s1, s2, i - 1, j - 1, dp);
}
int minDistance(string word1, string word2)
{ // memoization
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(word1, word2, n - 1, m - 1, dp);
}
int minDistance2(string word1, string word2)
{ // tabulation
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = i;
    for (int i = 0; i < m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] != word2[j - 1])
            {
                int case1 = 1 + dp[i - 1][j];     // deleting
                int case2 = 1 + dp[i][j - 1];     // insert
                int case3 = 1 + dp[i - 1][j - 1]; // replace

                dp[i][j] = min({case1, case2, case3});
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[n][m];
}
int minDistance3(string word1, string word2)
{ // space optimized
      int n = word1.size();
    int m = word2.size();
    
    vector<int> cur(m+ 1, 0);
    vector<int> prev(m + 1, 0);

    for (int i = 0; i <= m; i++)
        prev[i] = i;
    cur=prev;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
            {
                cur[0] = i;
                continue;
            }
            if (word1[i - 1] != word2[j - 1])
            {
                int case1 = 1 + prev[j];     // deleting
                int case2 = 1 + cur[j - 1];  // insert
                int case3 = 1 + prev[j - 1]; // replace

                cur[j] = min({case1, case2, case3});
            }
            else
            {
                cur[j] = prev[j - 1];
            }
        }
        prev = cur;
    }
    return cur[m];
}
int main()
{
    cout << minDistance("intention", "execution");
    return 0;
}