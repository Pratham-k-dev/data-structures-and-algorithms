//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool pred(const vector<int>& a,int m,int k,int d){
        int sum=0;
        int temp=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]<=d){
                temp++;
                
                
                
            }
            else{
                sum+=temp/k;
                if(sum>=m) break;
                temp=0;

            }
            if(i==n-1){
                sum+=temp/k;
                if(sum>=m) break;
                temp=0;
            }
        }
        return (sum>=m);
    }

public:
    int minDays(vector<int>& a, int m, int k) {
        int mini=*min_element(a.begin(),a.end());
        int maxi=*max_element(a.begin(),a.end());
        if(a.size()<1LL*m*k) return -1;

        int l=mini,r=maxi;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(pred(a,m,k,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};

int main (){
    
    return 0;
}