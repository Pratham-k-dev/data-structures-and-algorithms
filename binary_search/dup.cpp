// https://leetcode.com/problems/find-the-duplicate-number/description/?envType=problem-list-v2&envId=binary-search
#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=1,r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            int c=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid) c++;
            }
            if(c>mid) r=mid-1;
            else l=mid+1;
        }
        return l;
    }

int main (){
    vector<int> nums={3,3,3,3,3,5};
    cout<<findDuplicate(nums);

    return 0;
}