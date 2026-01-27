//https://www.codechef.com/practice/course/3-star-difficulty-problems/DIFF1700/problems/BITTUP
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
ll x=1e9+7;
using namespace std;

ll power(ll base,ll exp){ //calculating exponent in log(exp)
    ll ans=1;
    while(exp){
        if(exp&1) ans=(ans*base)%x;
        base=(base*base)%x;
        exp/=2;

    }
    return ans;
}

int main (){
ios::sync_with_stdio(false);
cin.tie(0);
    tc(){
        ll n,m;
        cin>>n>>m;
        ll ans=1,c=1;
        // f(i,0,n){
        //     c=(c*2)%x;
        // }
        c=power(2,n);
        c--;
        // f(i,0,m){
        //     ans=(ans*c)%x;
        // }
        ans=power(c,m);
        cout<<ans<<endl;
    }
    return 0;
}



/*

logic:

bitwise ands are 0 if there is aleast one zero in one column (consider n number of m digit binary nummbers one on another)
so choices of one column = 2^n -1 (only elxuding 1 1 1 1.. and including all combi)

since there are m digits 
answer=(2^n-1)^m



*/