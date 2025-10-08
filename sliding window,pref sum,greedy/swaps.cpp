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
bool isinc(vi &a, vi &b){
    f(i,1,a.size()){
        if(a[i]<a[i-1]) return false;
    }
    f(i,1,a.size()){
        if(b[i]<b[i-1]) return false;
    }
    return true;
}
int fun(int i,vi &a,vi &b,vi &dp){
    if(i==0) return dp[0]=isinc(a,b);

    // if(dp[i]!=-1) return dp[i];
    swap(a[i-1],b[i-1]);

   int x=( fun(i-1,a,b,dp))%m;
    swap(a[i-1],b[i-1]);
    int y=fun(i-1,a,b,dp)%m;
    return dp[i]= ((x+y)%m);

}
void solve(){
}
int main (){
ios::sync_with_stdio(false);
cin.tie(0);
tc(){
    int n;
    cin>>n;
    vi a(n),b(n);
    f(i,0,n) cin>>a[i];
    f(i,0,n) cin>>b[i];
    vector<int> dp(n+1,-1);
    
    cout<<fun(n,a,b,dp)<<endl;
}
    return 0;
}
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
using namespace std;

void solve(){
}
int main (){
ios::sync_with_stdio(false);
cin.tie(0);
tc(){
    
}
    return 0;
}