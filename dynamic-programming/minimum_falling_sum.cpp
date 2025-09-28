#include<bits/stdc++.h>
using namespace std;
int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 1)
            return mat[0][0];
        int ans = INT_MAX;
        vector<int> cur(n, 0), prev(n, 0);
        for (int i = 0; i < n; i++)
            prev[i] = mat[0][i];
        for (int i = 1 ; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = INT_MAX, y = INT_MAX, z = INT_MAX;
                if (j - 1 >= 0)
                    x = prev[j - 1];
                y = prev[j];
                if (j + 1 < n)
                    z = prev[j + 1];
                cur[j] = mat[i][j] + min(min(x, y), z);
                if (i == n - 1)
                    ans = min(ans,cur[j]);
            }
            prev = cur;
        }
        return ans;
    }

int main (){
    
    return 0;
}