#include<bits/stdc++.h>
using namespace std;
int kthRoot(int n,int k){
       int low=1;
    int high=n;
    while(low<=high){
        int mid=(low+high)/2;
        if((int)(pow(mid,k)+0.5)>n){
            high=mid-1;
        }
       
        else {
            low=mid+1;
        }
         
    }
    return high;
}

int main (){
    cout<<kthRoot(347,3);
    
    return 0;
}