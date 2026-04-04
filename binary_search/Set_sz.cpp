//https://www.codechef.com/problems/SETSZ
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
int n,q;
cin>>n>>q;
vll a(n);
f(i,0,n) cin>>a[i];
sort(all(a));
int u=1;
vll d;

f(i,1,n){//pre computing differences
    if(a[i]!=a[i-1]){
        d.pb(a[i]-a[i-1]);
        u++;
        
    }
    
}
sort(all(d));
vll p(u);
if(d.size()) p[0]=d[0]; //edge case if n==1 p[0] => runtime error
f(i,1,d.size()){
    p[i]=d[i]+p[i-1]; // prefix difference sum
}

while(q--){
    ll x;
    cin>>x;
    // if(n==1) {
    //     cout<<x<<endl;
    //     continue;
    // }
   ll tot =u*x; // total including overlaps
    ll i=lower_bound(all(d),x)-d.begin();
    /*
    if diff is < x

    extras are a[i-1]+x -a[i]
     so we are just accumulating all the extras and subtract from tot
    */
    ll extra=(i>0? -p[i-1]+(i)*x :0);
    cout<<tot-extra<<endl;
}
    return 0;
}