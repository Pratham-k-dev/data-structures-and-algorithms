//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool pred(vector<int>& nums,int &th,int x){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
                sum+=ceil((float) nums[i]/(float)x );
                if(sum> th) break;
        }
        return (sum <= th);
    }
public:
    int smallestDivisor(vector<int>& nums, int th) {
        int r=*max_element(nums.begin(),nums.end());
        int l=1;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(pred(nums,th,mid)){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};
int main (){
    
    return 0;
}