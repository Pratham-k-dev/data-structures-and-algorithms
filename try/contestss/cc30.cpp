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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a (n,vector<int> (m,0));
    int maxi=INT_MIN;
    for(auto & i: a){
        for(auto &j:i){
            cin>>j;
            maxi=max(maxi,j);

        }
    }
   unordered_map<int,int> r;
   unordered_map<int,int> c;
    int cnt=0;
    cout<<">>";
    f(i,0,n){
        f(j,0,m){
            if(a[i][j]==maxi){
                r[i]++;
                c[j]++;
                cnt++;
            }
        }
    }
    
    int ok=0;
    int val=0;
   f(i,0,n){
    f(j,0,m){
        if(a[i][j]==maxi){
            if(r[i]+c[j]-1 == cnt){
                ok=1;
                break;
            }
        }
        else if(r[i]+c[j] == cnt){
            ok=1;
            break;
        }
    }
    if(ok) break;
    
   }
   if(!ok) cout<<maxi<<endl;
   else cout<<maxi-1<<endl;

    
}
    
    return 0;
}

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

int main (){
ios::sync_with_stdio(false);
cin.tie(0);
    
    return 0;
}