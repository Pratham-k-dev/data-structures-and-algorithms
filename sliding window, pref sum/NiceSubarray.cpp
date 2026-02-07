//https://leetcode.com/problems/count-number-of-nice-subarrays/
#include<bits/stdc++.h>
using namespace std;

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,ans=0,c=0;
        vector<int> odds(n+1,0);
        odds[0]=1;
       for(int i=0;i<n;i++){
        if(nums[i]&1) c++;
        odds[c]++;

       }
       c=0;
       for(int i=0;i<n;i++){
            if(nums[i]&1) c++;
            if(c>=k) ans+=odds[c-k];
       }
        return ans;
    }

    class Solution { // O(1) extra space
    int func(vector<int> &nums,int k){ //number of subarray odds<=k
        if(k<0) return 0;
        int n=nums.size();
        int i=0,j=0,ans=0,c=0;

        while(j<n){//counting subarrays ending at j
            if(nums[j]&1) c++;
            while(c>k){
                if(nums[i]&1) c--;
                i++;
            }
            ans+=(j-i+1);
            j++;

        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
        
    }
};

int main (){
    vector<int> nums={2,2,2,1,2,2,1,2,2,2};
    int k=2;
    cout<<numberOfSubarrays(nums,k);
    
    return 0;
}