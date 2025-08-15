#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pow_2(ll exp){
    return (ll) (pow(2,exp)+0.5);
  }
int log_2(ll x){
    int ans;
    ll left=0;
    ll right=x;
    ll mid;
    while((right-left)>1){
         mid=left+(right-left)/2;
        if(pow_2(mid)>x){
            right=mid-1;
        }
        else{
            ans=mid;
            left=mid;
        }
    }
    if(pow_2(right)<=x){
        ans=right;
    }
    
    return ans;
}

int main (){
    cout<<log_2(120);
    
    return 0;
}