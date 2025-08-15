#include<bits/stdc++.h>

using namespace std;
void rotateLeft_brute(int arr[],int n,int d){
    d=d%n;
    int temp[d];
    for (int i = 0; i < d; i++)
    {
    temp[i]=arr[i];
    }
    for(int i=0;i<n-d;i++){
        arr[i]=arr[i+d];
    }
    int c=0;
    for(int i=n-d;i<n;i++){
        arr[i]=temp[c++];
    }
    
}
void reverse_array(int arr[],int beg,int end){
    while(end>beg){
        swap(arr[beg++],arr[end--]);
    }
}
void rotateleft_opt(int arr[],int n,int d){
    reverse_array(arr,0,d-1);//reverse(arr,arr+d);
    reverse_array(arr,d,n-1);//reverse(arr+d,arr+n);
    reverse_array(arr,0,n-1);//reverse(arr,arr+n);
}
int main (){
    int arr[]={1,2,3,4,5,6,7};
    int d=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    rotateLeft_brute(arr,n,d);
    // rotateleft_opt(arr,n,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}