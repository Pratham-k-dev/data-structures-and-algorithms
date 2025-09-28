//https://leetcode.com/problems/koko-eating-bananas/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {

bool f(vector<int>& p,int k,int h){
    int sum=0;
    for(int i=0;i<p.size();i++){
        sum+=(ceil((double)p[i]/(double)k));
        if(sum>h) return false;
    }

    return true;
}
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int l=1;
        int r=*max_element(p.begin(), p.end());
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(f(p,mid,h)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
        
    }
};

int main (){
    
    return 0;
}