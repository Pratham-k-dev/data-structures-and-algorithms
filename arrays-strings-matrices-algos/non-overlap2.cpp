//https://leetcode.com/problems/non-overlapping-intervals/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
         int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        int s=arr[n-1][0];
        int e=arr[n-1][1];
       int ans=0;
        
        for(int i=n-2;i>=0;i--){
            if(arr[i][1]<= s){
                
                s=arr[i][0];
                e=arr[i][1];
                continue;
                
            }
            
                ans++;
            
            
        }
        
    
        
        return ans;
    }
};

int main (){
    
    return 0;
}