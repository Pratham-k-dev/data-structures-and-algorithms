
// problem : https://takeuforward.org/plus/dsa/problems/book-allocation-problem
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
using namespace std;

bool pred(vll &a,ll m,ll ans){
    ll n=a.size();
    ll sum=a[0];
    ll c=1;
    f(i,1,n){
        if(sum+a[i] > ans ){
            sum=a[i];
            c++;
        }
        else sum+=a[i];
    }
    return (c>m) ;

}
ll bs(vll &a,ll m){
    ll r=(1e10);
    ll l=*max_element(all(a));
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(pred(a,m,mid)) l=mid+1;
        else r=mid-1;
    }
    return l;
}

int main (){
ios::sync_with_stdio(false);
cin.tie(0);
// vi a={25, 46, 28, 49, 24};
// ll m=4;
// vi a={12, 34, 67, 90};
// ll m=2;
tc(){
    ll n,m;
    cin>>n>>m;
    vll a(n);
    for(ll &i: a) cin>>i;
    cout<<bs(a,m)<<endl;
}
    
    return 0;
}