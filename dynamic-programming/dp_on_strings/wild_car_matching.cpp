#include <bits/stdc++.h>
using namespace std;
class Solution
{ // Dp Solution
    bool f(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if (j < 0 && i < 0)
            return 1;
        if (j < 0)
            return 0;
        if (i < 0)
        {
            if (p[j] == '*')
            {
                while (j >= 0)
                {
                    if (p[j] != '*')
                        return 0;
                    j--;
                }
                return 1;
            }
            else
                return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int case1 = 0, case2 = 0, case3 = 0, case4 = 0;
        if (p[j] == '*')
        {
            case1 = f(s, p, i - 1, j - 1, dp); // skip it
            case2 = f(s, p, i - 1, j, dp);     // keep it
            case3 = f(s, p, i, j - 1, dp);     // blank
        }
        else if (p[j] == '?')
            case4 = f(s, p, i - 1, j - 1, dp);
        else if (s[i] != p[j])
            return dp[i][j] = 0;
        else
        {
            return dp[i][j] = f(s, p, i - 1, j - 1, dp);
        }
        return dp[i][j] = (case1 | case2 | case3 | case4);
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(s, p, n - 1, m - 1, dp);
    }
};

class Solution2
{ // O(n+m) solution
public:
    bool isMatch(string s, string p)
    {
        int n = s.length(), m = p.length();
        if (n == 0)
        {
            for (int i = 0; i < m; i++)
                if (p[i] != '*')
                    return false;

            return true;
        }
        int i = 0, j = 0, k = 0, l = 0;
        int star = 0; //flag to see if '*' is available behind
        while (i < n)
        {

            if (k < m && p[k] == '*')
            {
                star = 1;
                j = k + 1; // position after '*' in pattern
                k++;
                l = i; //l=> last available 'i' for merging in '*'
                
            }

            else if (k < m && (s[i] == p[k] || p[k] == '?'))
            {

                k++;
                i++;
            }
            else if (star)
            {
                k = j;// backtracking to j index to start matching again
                i = ++l; // expand string in '*' to continue matching
            }
            else
                return false; // cannot match return false
        }
        while (k < p.size() && p[k] == '*')
            k++; //skipping tailing '*' 's
        
        return (k >= m);// pattern exausted return true
    }
};

int main()
{

    return 0;
}