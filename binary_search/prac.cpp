#include<bits/stdc++.h>
using namespace std;



int * lb(vector<int> &vec, int k){
    sort(vec.begin(),vec.end());

    int low=0,high=vec.size(),mid;
    while(high-low>1){
        mid=(high+low)/2;
        if(vec[mid]>=k) high=mid;
        else if(vec[mid]<k) low=mid+1;


    }

    if(vec[low]>=k) return &vec[low];
    else return &vec[high];


}


 vector<int> searchRange(vector<int>& nums, int t) {
        vector<int> ans (2,-1);
        int n=nums.size();
       int low= 0,high=n-1,mid;
       while(low<high){
        mid=(low+high)/2;
        if(nums[mid]<=t) low=mid;
       }


        
    }
int main (){
    vector<int> vec={};
    // cout<<*lb(vec,3);

    
    return 0;
}