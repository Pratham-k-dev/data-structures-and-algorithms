//https://codeforces.com/problemset/problem/2144/C

#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define tc() ll t; cin>>t; while(t--)
#define endl '\n'
#define m 998244353
using namespace std;

ll solve(int i,int ps,vll &a,vll &b,vector<vll> &dp){ // ps=previous indices swapped| 1=>yes 0=>no
    if(i==a.size()) return 1;// if reached last its one possibility

    if(i==0){
        return (solve(i+1,0,a,b,dp)+solve(i+1,1,a,b,dp))%m;
    }

    if(dp[i][ps]!=-1) return dp[i][ps];

    ll res = 0;
    // calculate result ensuring the non descending nature
    if(ps){
        if(a[i] >= b[i-1] && b[i] >=a[i-1]) res=(res+solve(i+1,0,a,b,dp))%m; //may notswap
        if(b[i] >= b[i-1] && a[i]>=a[i-1] ) res=(res+solve(i+1,1,a,b,dp))%m; // may swap
    }
    else{
        if(a[i] >= b[i-1] && b[i] >=a[i-1]) res=(res+solve(i+1,1,a,b,dp))%m; // may swap
        if(b[i] >= b[i-1] && a[i]>=a[i-1] ) res=(res+solve(i+1,0,a,b,dp))%m; // maynot swap
    }
    return dp[i][ps]=res;
}
int main (){
ios::sync_with_stdio(false);
cin.tie(0);
tc(){
    int n;
    cin>>n;
    vll a(n),b(n);
    f(i,0,n) cin>>a[i];
    f(i,0,n) cin>>b[i];

    vector<vll> dp(n,vll(2,-1));
    cout<<solve(0,0,a,b,dp)<<endl;
}
    return 0;
}