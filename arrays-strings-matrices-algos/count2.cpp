#include<bits/stdc++.h>
using namespace std;
void Count_sort(int arr[],int n){
int ans[n];
// int *p=&ans[0];
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int temp[max+1]={0};
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    for(int i=1;i<=max;i++){
        temp[i]+=temp[i-1];
    }
    
    
    for(int j=n-1;j>=0;j--){
        ans[temp[arr[j]]-1]=arr[j];
        temp[arr[j]]--;
       

    }
    for(int i=0;i<n;i++)
{
    arr[i]=ans[i];
}

    
    }


int main (){
 int   arr[]={2,0,2,3,4,1,5};
Count_sort(arr,7);
 for(int i=0;i<7;i++) cout<<arr[i]<<" ";
    
    return 0;
}