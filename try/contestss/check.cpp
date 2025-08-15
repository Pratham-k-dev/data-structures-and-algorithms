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

int main (){
ios::sync_with_stdio(false);
cin.tie(0);
    tc(){
        ll n;
        cin>>n;
        ll ans=1+(n>2? ((1LL*(n-2)*(4LL+2*(n-3)))/2) :0);
        
    }
    return 0;
}