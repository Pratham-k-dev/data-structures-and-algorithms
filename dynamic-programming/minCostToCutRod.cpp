// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

#include <bits/stdc++.h>
using namespace std;
int fn(int i, int j, int n, vector<int> &cuts, vector<vector<int>> &dp)
{ // i,j are indexes along 'cuts'
    int m = cuts.size();
    if (dp[i][j] != -1)
        return dp[i][j];
    int minCost = 1e7;
    int s = 0, e = n; // 0=>left extream i.e 0 and m+1=>right extream i.e n
    if (i != 0)
        s = cuts[i - 1];
    if (j != m + 1)
        e = cuts[j - 1];
    for (int k = i; k < j - 1; k++)
    {

        minCost = min(minCost, e - s + fn(i, k + 1, n, cuts, dp) + fn(k + 1, j, n, cuts, dp)); // split at cuts[k]
    }
    return dp[i][j] = (minCost == 1e7 ? 0 : minCost);
}
// memoization return dp[0][m+1]

int minCost(int n, vector<int> &cuts)
{
    int m = cuts.size();
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

    // return fn(0,m+1,n,cuts,dp);

    for (int l = 1; l <= m + 1; l++)
    { // lower length to higher length
        for (int i = 0; i <= m - l + 1; i++)
        {
            int j = i + l;
            int s = 0, e = n;
            if (i != 0)
                s = cuts[i - 1];
            if (j != m + 1)
                e = cuts[j - 1];
            int minCost = 1e7;
            for (int k = i; k < j - 1; k++)
            {

                minCost = min(minCost, e - s + dp[i][k + 1] +
                                           dp[k + 1][j]);
            }
            dp[i][j] = (minCost == 1e7 ? 0 : minCost);
        }
    }
    return dp[0][m + 1];
}

int main()
{

    return 0;
}