#include<bits/stdc++.h>
using namespace std;

int main (){
    int n=2, k=3;
    int sum=0;
    // vector<char> s(1<<n,'0');
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(1<<(n-i));j++){

            sum+=i;
            if(sum>=k) break;
        }
         if(sum>=k) break;
    }

    if(sum>k) cout<<"no"<<endl;
    else if(sum==k){
        cout<<"yes";
    }
    return 0;
}