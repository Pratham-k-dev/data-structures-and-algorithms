#include<bits/stdc++.h>
using namespace std;
class Solution {
    int f(int i,vector<int> &arr,int k,vector<int> &dp){
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=0,ans=0;
        for(int j=i;j<min(i+k,(int)arr.size());j++){
            maxi=max(maxi,arr[j]);
            ans=max(ans,(j-i+1)*maxi+f(j+1,arr,k,dp));

        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,k,dp);
    }
};
int main (){
    
    return 0;
}