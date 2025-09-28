#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
         int l=0,r=nums.size()-1;
         int ans=0;
        while(l<r){
            int mid=l+(r-l)/2;
            
            if(nums[r]<nums[mid]){// right sside not sorted then min is in it

                l=mid+1;

            }
            else{ // mid can be min , min in left half only
               
                r=mid;
            }
        }
        return nums[l];
    }

int main (){
    
    return 0;
}