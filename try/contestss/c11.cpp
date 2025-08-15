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
    int n,k;
    cin>>n>>k;
    vi a(n);
    f(i,0,n) cin>>a[i];
    int i=0,ans=0;
    
    while(i<n){
       
        int c=0;
        while(c<k && i<n && a[i]==0) i++,c++;
        if(c==k) ans++;
        i++;

        
        


    }
    cout<<ans<<endl;
   
}
    return 0;
}