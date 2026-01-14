// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/0
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        
       vector<int> dp1(n,1);// lis from from
       vector<int> dp2(n,1);// lis from end (reverse)
       
       
       for(int i=1;i<n;i++){// optimal tabulation
        
        for(int j=0;j<i;j++){
            
            if(nums[j]<nums[i] && 1+dp1[j]>dp1[i]) {
                dp1[i]=1+dp1[j];
                
            }

        }
       }
       for(int i=n-2;i>=0;i--){
        
        for(int j=n-1;j>i;j--){
            
            if(nums[j]<nums[i] && 1+dp2[j]>dp2[i]) {
                dp2[i]=1+dp2[j];
                
            }

        }
       }
       int ans=0;
       for(int i=0;i<n;i++){
           if(dp1[i]==1 || dp2[i]==1) continue;
           ans=max(ans,dp1[i]+dp2[i]-1); // here i is break point where we switch from inc to desc
       }
        
        
        return ans;
       


       
    }
};


int main (){
    
    return 0;
}