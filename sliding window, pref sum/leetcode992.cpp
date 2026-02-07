//https://leetcode.com/problems/subarrays-with-k-different-integers/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int f(vector<int> &nums,int k){ // countsubarrays uniques <=k
        if(k<=0) return 0;
         int n=nums.size();
        unordered_map<int,int> mp;

        int i=0,j=0,ans=0;

        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(!mp[nums[i]]) mp.erase(nums[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;

    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
        return f(nums,k)-f(nums,k-1);

        
    }
};

int main (){
    
    return 0;
}