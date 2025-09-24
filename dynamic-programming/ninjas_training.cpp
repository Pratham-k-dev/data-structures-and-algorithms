//https://www.naukri.com/code360/problems/ninja-s-training_3621003
#include<bits/stdc++.h>
using namespace std;
int fun(vector<vector<int>> &points){
    int n=points.size();
    vector<vector<int>> dp(n,vector<int> (3,0));
    dp[0][0]=points[0][0];
    dp[0][1]=points[0][1];
    dp[0][2]=points[0][2];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=max(dp[i-1][1],dp[i-1][0]);
    }
    int ans=max(dp[n-1][0],dp[n-1][1]);
    ans=max(ans,dp[n-1][2]);
    return ans;
}
int fun2(vector<vector<int>> &points){//memory optimised
    int n=points.size();
    // vector<vector<int>> dp(n,vector<int> (3,0));
    int prev0=points[0][0];
    int prev1=points[0][1];
    int prev2=points[0][2];
    int q0=points[0][0];
    int q1=points[0][1];
    int q2=points[0][2];

    for(int i=1;i<n;i++){
        q0=points[i][0]+max(prev1,prev2);
        q1=points[i][1]+max(prev0,prev2);
        q2=points[i][2]+max(prev1,prev0);

        prev0=q0;
        prev1=q1;
        prev2=q2;
    }
    int ans=max(q0,q1);
    ans=max(ans,q2);
    return ans;
}

int main (){
    
    return 0;
}

