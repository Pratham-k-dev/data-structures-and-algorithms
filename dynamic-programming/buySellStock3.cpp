#include<bits/stdc++.h>
using namespace std;
int f(vector<int> &p,int i,int buy,int tr,vector<vector<vector<int>>> &dp){
     if(i>=p.size()) return 0;
    if(tr>1) return dp[i][buy][tr]=0;
    if(dp[i][buy][tr]!=-1) return dp[i][buy][tr];
    if(!buy){
        return dp[i][buy][tr]=max(p[i]+f(p,i+1,1,tr+1,dp),f(p,i+1,0,tr,dp));
    }
    return dp[i][buy][tr]= max(-p[i]+f(p,i+1,0,tr,dp),f(p,i+1,1,tr,dp));
     
}

int main (){
    vector<int> p={3,3,5,0,0,3,1,4};
    int n=p.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    cout<<f(p,0,1,0,dp)<<endl;
    return 0;
}