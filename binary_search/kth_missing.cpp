// /https://leetcode.com/problems/kth-missing-positive-number/
#include<bits/stdc++.h>
using namespace std;
 int findKthPositive(vector<int>& arr, int k) {
        int l=0,r=arr.size()-1;
        if(arr[0]>k) return k;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(arr[mid]-(mid+1) < k){
                l=mid+1;
            }
            else r=mid-1;
        }
        if (r<0) r=0;
        return arr[r]+k-(arr[r]-(r+1));
    }
int main (){
    
    return 0;
}