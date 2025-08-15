#include<bits/stdc++.h>

using namespace std;
int main (){
    int arr[10]={2,2,3,5,7,9,10,7,7,7};
    int n=sizeof(arr)/sizeof(arr[0]);
   int hash[n]={0};
   for(int i=0;i<n;i++){
    hash[arr[i]]++;
   }
   int k;
   cin>>k;
   cout<<hash[k];
    return 0;
}