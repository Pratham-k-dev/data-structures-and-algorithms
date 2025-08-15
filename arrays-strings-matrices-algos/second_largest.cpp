#include<bits/stdc++.h>
int second_smallest(int arr[],int n){
    int min=INT16_MAX;
    int sec_min=INT16_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            sec_min=min;
            min=arr[i];
            
        }
        else if(arr[i]>min && arr[i]<sec_min){
            sec_min=arr[i];
        }

    }
    return sec_min;
}

using namespace std;
int main (){
    int arr[]={2,3,5,7,1,-1,-2,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<second_smallest(arr,n);
    
    return 0;
}