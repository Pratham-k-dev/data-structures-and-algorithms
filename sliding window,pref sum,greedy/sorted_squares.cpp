//https://leetcode.com/problems/squares-of-a-sorted-array/description/

// two pointer
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int i=0;
        
        int j=n-1;
        int k=n-1;
        while(i<n && j>=0 && nums[j]>=0 && nums[i]<0){
            int l=nums[i]*nums[i];
            int r=nums[j]*nums[j];
            if(l>r){
                ans[k--]=l;
                i++;
            }
            else{
                ans[k--]=r;
                j--;
            }
        }
        while(i<n && nums[i]<0) ans[k--]=nums[i]*nums[i++];
        while(j>=0 && nums[j]>=0) ans[k--]=nums[j]*nums[j--];
        return ans;
    }
};

int main (){
    
    return 0;
}