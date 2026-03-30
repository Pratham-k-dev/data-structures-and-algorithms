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
    int n,k;
    cin>>n>>k;
    vi a(n),fr(n+1,0);
    int fl=0;
    f(i,0,n){
        cin>>a[i];
        if(a[i]>k) fl=1;
        fr[a[i]]++;
    }

    int i=0,m=0;
    while(i<k && fr[i]){
        i++;
        m++;
    }
    if(m==k ){
        cout<<m-1<<endl;

    }
    else cout<<m<<endl;
    
}
    return 0;
}