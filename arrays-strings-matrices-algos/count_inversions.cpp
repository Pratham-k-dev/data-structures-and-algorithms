
// solved using merge sort

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
void merge(vi &a,int l,int mid,int r,int &ans){
    
   int i=0,j=0;

   vi L(mid-l+2);
   vi R(r-mid+1);
   f(i,0,L.size()-1) L[i]=a[l+i];
   L.back()=INT_MAX;
    f(i,0,R.size()-1) R[i]=a[mid+1+i];
    R.back()=INT_MAX;
    int k=l;
    while(i<L.size() && j<R.size()){
        if(L[i]<=R[j]){
            if(L[i]!=INT_MAX) a[k++]=L[i];
            i++;
        }
        else{
            ans+=L.size()-i-1;
            if(R[j]!=INT_MAX) a[k++]=R[j];
            j++;
        }
    }
}


void sol(vi &a,int l,int r,int &ans){
    if(l>=r) return;
    int mid=l+(r-l)/2;

    sol(a,l,mid,ans);
    sol(a,mid+1,r,ans);
    merge(a,l,mid,r,ans);

}

int main (){
ios::sync_with_stdio(false);
cin.tie(0);
tc(){



    int n;
    cin>>n;
    vi a(n);
    // a={2, 3, 7, 1, 3, 5};
    // n=a.size();
    for(int &i:a) cin>>i;
    int ans=0;
    sol(a,0,n-1,ans);
    cout<<ans<<endl;
    // for(int &i:a) cout<<i<<' ';
}

    return 0;
}