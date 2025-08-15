//https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(sum,ans);
            if(sum<=0){
                sum=0;
            }
        }
    return ans;
    }
};

int main (){
    
    return 0;
}