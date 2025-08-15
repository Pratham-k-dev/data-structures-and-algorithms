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
        ll n,c;
        cin>>n>>c;
        vll a(n);
        f(i,0,n){
            cin>>a[i];
        }
        sort(all(a));
        auto it=upper_bound(all(a),c);
        int i=it-a.begin()-1;
        ll ans=0;
        if(n-i-1 >0) ans+=n-i-1;
        
        int k=0;
        
        while(i>=0){
            a[i]=a[i]<<(k);
            if(a[i]>c) ans++;
            else k++;
            i--;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}