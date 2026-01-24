#include<bits/stdc++.h>
using namespace std;
class Solution {
    
    int isPal(string& s, int i, int j) {
        if (i > j)
            return 0;
        while (i < j) {
            if (s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    int f(int i, int j, string& s, vector<vector<int>>& dp) {//without front partiton
        if (dp[i][j] != -1)
            return dp[i][j];
        if (isPal(s, i, j))
            return 0;
        int ans = j - i;
        for (int k = i; k < j; k++) {
            ans = min(ans, 1 + f(i, k, s, dp) + f(k + 1, j, s, dp));
        }
        return dp[i][j] = ans;
    }
    int f2(string& s, int i, vector<int>& dp) {//front partition 
        if (i >= s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = s.size() - i - 1;
        for (int k = i; k < s.size(); k++) {
            bool chk = isPal(s, i, k);
            if (chk && k == s.size() - 1)
                ans = 0;
            else if (chk)
                ans = min(ans, 1 + f2(s, k + 1, dp));
        }
        return dp[i] = ans;
    }

public:
    int minCut(string s) {
        int n = s.size();
       
        vector<int> dp(n+1, 0);
        // return f2(s, 0, dp);

    
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
        //using dp to compute palindromes

        for (int i = n - 1; i >= 0; i--) {
            int ans = n - i - 1;
            for (int k = i; k <n; k++) {
                bool chk = pal[i][k];
                if (chk && k ==n - 1)
                    ans = 0;
                else if (chk)
                    ans = min(ans, 1 + dp[k+1]);
            }
             dp[i] = ans;
        }
        return dp[0];
    }
};

int main (){
    
    return 0;
}