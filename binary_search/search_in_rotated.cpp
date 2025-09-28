#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid]){
                if(target >= nums[l] &&target <nums[mid]) r=mid-1;
                else l=mid+1;

            }
            else{
                 if(target > nums[mid] &&target <=nums[r]) l=mid+1;
                else r=mid-1;
            }
        }

        return -1;
    }

     bool search2(vector<int>& nums, int target) {// in case of repeatitons
          int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return true;
            if(nums[l]==nums[mid] && nums[mid]==nums[r]){
                l++;
                r--;
            }
            else if(nums[l]<=nums[mid]){
                if(target >= nums[l] &&target <nums[mid]) r=mid-1;
                else l=mid+1;

            }
            else {
                 if(target > nums[mid] &&target <=nums[r]) l=mid+1;
                else r=mid-1;
            }
            

        }

        return false;
    }
};

int main (){
    
    return 0;
}