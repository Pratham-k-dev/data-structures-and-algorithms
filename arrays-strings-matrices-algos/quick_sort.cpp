#include<bits/stdc++.h>

using namespace std;
void quick_sort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    int n=high-low+1;
    int left=low+1;
    int right=high;
    int pivot=arr[low];
    while(right>=left){
        for(;left<=high;left++){
            if(arr[left]<pivot){
                break;
            }
        }
         for(;right>low;right--){
            if(arr[right]<=pivot){
                break;
            }
        }
        if(left<right){
        swap(arr[left],arr[right]);
        }
    }
    swap(arr[right],arr[low]);
    
    quick_sort(arr,low,right-1);
    quick_sort(arr,right+1,high);

}
int main (){
    int arr[]={5,4,7,1,6,0,1,-1,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}