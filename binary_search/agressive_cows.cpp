// given no. of cows , n stalls need to maximise min distance btw cows

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
bool isPossible(vi &a,int c,int ans){
    int n=a.size();
    int last=a[0];
    int cnt=1;
    f(i,1,n){
        if(a[i]-last>=ans) {
            cnt++;
            last=a[i];
            if(cnt==c) return true;
        }
        
        
    }
    return (cnt>=c);
}

 int AggCow(vi &a,int c){
        int n=a.size();
        sort(all(a));
        int l=1,r=a[n-1]-a[0];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(a,c,mid)){
                l=mid+1;
            }
            else r=mid-1;
        }
        return r;
        
    }

int main (){
ios::sync_with_stdio(false);
cin.tie(0);
tc(){
    int n,c;
    cin>>n>>c;
    vi a(n);
    f(i,0,n) cin>>a[i];
    cout<<AggCow(a,c)<<endl;
}
    
    return 0;
}