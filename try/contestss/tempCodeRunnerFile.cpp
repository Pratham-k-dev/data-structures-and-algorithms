#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define tc() int t; cin>>t; while(t--)
using namespace std;

int main (){
ios::sync_with_stdio(false);
cin.tie(0);
      tc()
      {

        int n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        int m=0;
        int am,bm;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                int temp=(a*(n-j)+b*(j)+c*(i*j)+d*(j*(n-i-j)));
                if((n-i-j)>=0 && m<temp ){
                    m=temp;
                    am=i,bm=j;
                }
            }
        }
        cout<<m<<endl;
   }
    return 0;
}

