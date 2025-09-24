//https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxSum(vector<int> &arr) //O(n^2)
    {
        // code here
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        int ans = 0;
        ans = max(ans, dp[0]);
        if (n > 1)
        {
            dp[1] = arr[1];
            ans = max(ans, dp[1]);
        }

        for (int i = 2; i < n; i++)
        {
            int msum = 0;
            for (int j = i - 2; j >= 0; j--)
            {
                if (msum > arr[i] + dp[j])
                    break;
                else
                    msum = arr[i] + dp[j];
            }
            dp[i] = msum;
            ans = max(dp[i], ans);
        }
        return ans;
    }


    int findMaxSumOpt(vector<int>& arr) {// O(n) (space can be optimized by taking previous variables)
        // code here
        int n=arr.size();
        vector<int> dp(n,-1);
        dp[0]=arr[0];
        
        for(int i=1;i<n;i++){
            int pick=arr[i]+((i-2>=0)?dp[i-2]:0);
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
            
        }
        return dp[n-1];
    }


    
};
int main()
{
    

    return 0;
}
