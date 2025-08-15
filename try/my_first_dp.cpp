// https:www.codechef.com/problems/DIREP



#include<bits/stdc++.h>
#define m 998244353
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define tc() ll t; cin>>t; while(t--)
using namespace std;
map<ll,ll> mp;

ll fun(ll x){
    if(x<4) return 1;
    if(x==4 ) return 2;
    ll  a=(mp[x-3] ? mp[x-3] : fun(x-3));
     ll  b=(mp[x-1] ? mp[x-1] : fun(x-1));
    // ll a=fun(x-3);
    // ll b=fun(x-1);
    ll ans=(a+b)%m;
    return mp[x]=ans;
}

int main (){
ios::sync_with_stdio(false);
cin.tie(0);

tc(){
    int n;
    cin>>n;
    cin.ignore();
    string s;
    cin>>s;
    vll v;
  ll sum=1,i=1;
   while(i<n){
       sum=1;
       while(i<n &&s[i]!= s[i-1]) i++,sum++;
       if(sum>=4) v.push_back(sum);
       i++;
   }
//    for(ll j: v) cout<<j<<' ';
//    cout<<endl;
    sum=1;
    f(j,0,v.size()){
        sum=(sum*(fun(v[j])))%m;
    }
    cout<<sum<<endl;
}
// cout<<fun()<<endl;
    
    return 0;
}
