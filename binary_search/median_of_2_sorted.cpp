//median of two sorted
#include<bits/stdc++.h>
using namespace std;


class Solution {
  
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()==0 && nums2.size()==0) return 0;
        if(nums1.size()==0) return (nums2.size()&1 ? (double)nums2[nums2.size()/2]:( (double)(nums2[nums2.size()/2]+nums2[nums2.size()/2 -1])/2.0));
        else if(nums2.size()==0) return (nums1.size()&1 ? (double)nums1[nums1.size()/2]:( (double)(nums1[nums1.size()/2]+nums1[nums1.size()/2 -1])/2.0));

        int l=min(nums1[0],nums2[0]),r=max(nums1.back(),nums2.back());
        int sum=nums1.size()+nums2.size();

        while(l<=r){
            int mid=l+(r-l)/2;
            int c=lower_bound(nums1.begin(),nums1.end(),mid)-nums1.begin()+lower_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();
            if(c<=(sum/2)) l=mid+1;
            else r=mid-1;
        }
        if((nums1.size()+nums2.size())&1) return (double)r;
    int l1=min(nums1[0],nums2[0]),r1=max(nums1.back(),nums2.back());
        while(l1<=r1){
            int mid=l1+(r1-l1)/2;
             int c=lower_bound(nums1.begin(),nums1.end(),mid)-nums1.begin()+lower_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();
            if(c<=(sum/2 -1))  l1=mid+1;
            else r1=mid-1;
        }
        // if (l1>max(nums1.back(),nums2.back())) l1--;
        //  if (l>max(nums1.back(),nums2.back())) l--;

         return (double)((double)(r+r1)/2.0);
    }
};
int main (){
    
    return 0;
}