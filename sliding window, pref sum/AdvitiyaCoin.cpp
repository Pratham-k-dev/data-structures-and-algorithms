//https://www.codechef.com/problems/ADC
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define frev(i,a,b) for(ll i=a;i>=b;i--)
#define tc() ll t; cin>>t; while(t--)
#define endl '\n'
using namespace std;

void solve(){
}
int main (){
ios::sync_with_stdio(false);
cin.tie(0);
tc(){
    ll n,k;
    cin>>n>>k;
    vll a(n);
    f(i,0,n) cin>>a[i];
    
    ll prev=n;
    map<ll,int> mp;
    int ans=0;
    int i=0,j=0;
    ll mx=LLONG_MIN;
    ll mn=LLONG_MAX;
    
    while(j<n){
        
        mn=min(mn,a[j]);
        mx=max(mx,a[j]);
        if( abs(a[j]-mn)-k>0){
            
            mx=LLONG_MIN;
             mn=LLONG_MAX;
             i=j+1;
            ans++;
        }
        else if( abs(a[j]-mx)-k>0){
             mx=LLONG_MIN;
             mn=LLONG_MAX;
            
            i=j+1;
            ans++;
        }
        j++;
        
    }
    
    cout<<ans<<endl;
    
}
    return 0;
}