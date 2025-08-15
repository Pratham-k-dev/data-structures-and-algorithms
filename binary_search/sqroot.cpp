#include<bits/stdc++.h>
using namespace std;
int sqroot(int n){
    int low=1;
    int high=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid>n){
            high=mid-1;
        }
       
        else {
            low=mid+1;
        }
         
    }
    return high;

}
int main (){
    
    cout<<sqroot(35);
    return 0;
}