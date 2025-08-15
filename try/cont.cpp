// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// your code goes here
// int t;
// cin>>t;
// while(t--){
//     int n,k;
//     cin>>n>>k;
//     if(n<2*k ){
//         cout<<-1<<endl;
//         continue;
        
//     }
    
   
    
//     int val=k+1;
//     while(val < (n+1)) cout<<val++<<' ';
//     for(int i=n-k+1;i<=n;i++) cout<<((i%k)?(i%k):k)<<' ';
//     cout<<endl;
// }
// }
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define tc() ll t; cin>>t; while(t--)
using namespace std;

int main (){
ios::sync_with_stdio(false);
cin.tie(0);
    tc(){
      ll n;
      vll a(n);
      set<ll> st;
      ll maxi=0;
      f(i,0,n) {
          
      cin>>a[i];
     
      
      auto it=st.begin();
      if(i>0&& a[i]> *it && (a[i]-(*it) >maxi)) maxi=a[i]-(*it);
      st.insert(a[i]);
      }
      cout<<maxi<<endl;
      
    //   if(n==1){
    //       cout<<"UNFIT"<<endl;
    //       continue;
    //   }
    //   if(maxi != 0){
    //       cout<<maxi<<endl;
    //   }
    //   else cout<<"UNFIT"<<endl;
      
        
    }
    return 0;
}
