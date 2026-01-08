//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include<bits/stdc++.h>
using namespace std;
class Solution { //using transaction number 0 1 2 3 => buy sell buy sell... 
    int f(vector<int> &p,int k,int i,int t,vector<vector<int>> &dp ){
        int n=p.size();
            if(i>=n||t== 2*k) return 0;
    if(dp[i][t]!=-1) return dp[i][t];
        if(t&1){
            return dp[i][t]= max(p[i]+f(p,k,i+1,t+1,dp),f(p,k,i+1,t,dp));
        }
        return dp[i][t]= max(-p[i]+f(p,k,i+1,t+1,dp),f(p,k,i+1,t,dp));
    }
public:
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return f(prices,k,0,0,dp);

    }
};

class Solution {
    int f(vector<int> &p,int i,int buy,int tr,int k,vector<vector<vector<int>>> &dp){ //memoization
     if(i>=p.size()) return 0;
    if(tr>=k) return dp[i][buy][tr]=0;
    if(dp[i][buy][tr]!=-1) return dp[i][buy][tr];
    if(!buy){ // if buy==0 either sell or not sell
        return dp[i][buy][tr]=max(p[i]+f(p,i+1,1,tr+1,k,dp),f(p,i+1,0,tr,k,dp));
    }
    return dp[i][buy][tr]= max(-p[i]+f(p,i+1,0,tr,k,dp),f(p,i+1,1,tr,k,dp));
    //  in main=> return f(p,0,1,0,k,dp);
}

public:
    int maxProfit(int k, vector<int>& prices) {
       int n = prices.size();
        if (n == 0 || k == 0) return 0;

        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int tr = 0; tr < k; tr++) {
                    if (buy) {
                        cur[buy][tr] = max(
                            -prices[i] + prev[0][tr],
                            prev[1][tr]
                        );
                    } else {
                        cur[buy][tr] = max(
                            prices[i] + prev[1][tr + 1],
                            prev[0][tr]
                        );
                    }
                }
            }
            prev = cur; // move to next day
        }

        return prev[1][0];
    }
};
int main (){
    
    return 0;
}