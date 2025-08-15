
//https://leetcode.com/problems/subarray-product-less-than-k/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n=nums.size();
       int i=0,j=0;
       int ans=0;
       long long prod=1;
 

    while(i<n){
        prod*=nums[i];
        while( prod>=k && j <= i){
            prod/=nums[j];
            j++;
        }
        ans+=i-j+1;
        i++;
    }
      return ans;
    }
};

int main (){
    
    return 0;
}