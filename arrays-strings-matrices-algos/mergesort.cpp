#include<bits/stdc++.h>
int comparisions=0;
void merge(int arr[],int beg,int mid,int end){
    int temp[end-beg+1];
    int k=0;
    int left=beg,right=mid+1;
    while(left<=mid && right <=end){
        comparisions++;
        if(arr[left]<=arr[right]){
            temp[k++]=arr[left];
            left++;
        }
        else{
            temp[k++]=arr[right];
            right++;

        }
    }
    while(left<=mid){
        temp[k++]=arr[left];
        left++;
    }
    while(right<=end){
        temp[k++]=arr[right];
        right++;
    }
    for(int i=beg;i<=end;i++){
        arr[i]=temp[i-beg];

    }

}
void merge_sort(int arr[],int beg,int end){
    if(beg>=end){
        return;
    }
    int mid=(beg+end)/2;
    merge_sort(arr,beg,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,beg,mid,end);
}


using namespace std;
int main (){
    // int n=7;
    int arr[]={4,7,3,2,9,4,5};
    int n=sizeof(arr)/sizeof(int);
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"comparisions: "<<comparisions;
    return 0;
}