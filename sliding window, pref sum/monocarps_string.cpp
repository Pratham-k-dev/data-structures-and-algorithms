//https://codeforces.com/contest/2145/problem/C
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define tc() ll t; cin>>t; while(t--)
#define endl '\n'
using namespace std;

void solve(){
}
int main (){
ios::sync_with_stdio(false);
cin.tie(0);
tc(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ta=0,tb=0;
    f(i,0,n){
        if(s[i]=='a') ta++;
        else tb++;
    }
    if(ta==tb) {
        cout<<0<<endl;
        continue;
    }
    int ans=INT_MAX;
    
    unordered_map<int,int> m;
    m.insert({0,-1});
    int a=0,b=0;
    f(i,0,n){
        if(s[i]=='a') a++;
        else b++;
        if(m.find(tb-ta-b+a)!=m.end()){
            ans=min(ans,i-m[tb-ta-b+a]);
        }
        m[a-b]=i;
    }
    if(ans>=n) cout<<-1<<endl;
    else cout<<ans<<endl;

}
    return 0;
}


