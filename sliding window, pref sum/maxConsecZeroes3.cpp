//https://leetcode.com/problems/max-consecutive-ones-iii/
#include<bits/stdc++.h>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
            
            int i=0,j=0;
            int zeroes=0;
           
        while(i<n && j<n){

                
            if(zeroes+(nums[j]==0)<=k){
                ans=max(ans,j-i+1);
                if(!nums[j]) zeroes++;
                j++;
            }
            else{
                if(nums[i]==0) zeroes--;
                i++;
            }

        }
        return ans;

        
    }

int main (){
    
    return 0;
}