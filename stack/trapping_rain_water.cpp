#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> prevGreat(vector<int> &h){
        int n=h.size();
        vector<int> ans=h;
        
        for(int i=1;i<n;i++){
            ans[i]=max(ans[i-1], ans[i]);
        }
        for(int x: ans) cout<<x<<' ';
        cout<<endl;
        return ans;
    }
    vector<int> nextGreat(vector<int> &h){

        int n=h.size();
        vector<int> ans=h;
        
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i+1],ans[i]);
        }
        for(int x: ans) cout<<x<<' ';
        cout<<endl;
        return ans;
    }
public:
    int trap(vector<int>& height) {
        vector<int> left=prevGreat(height);
        vector<int> right=nextGreat(height);
        int ans=0;
        int n=height.size();
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
        
    }
    int trapOpt(vector<int> &height){// space optimized
        int tot=0;
        int lmax=0,rmax=0;
        int n=height.size();
        int l=0,r=n-1;
        while(l<r){
            if(height[l]<=height[r]){// traverse smaller first
                if(lmax> height[l]) { // nothing on left of l is > rmax 
                    tot+=lmax-height[l];
                }
                else lmax=height[l];
                l++;
            }
            else{
                if(rmax> height[r]){ // wlog
                    tot+=rmax-height[r];
                }
                else rmax=height[r];
                r--;
            }
        }
        return tot;
    }
};

int main (){
Solution s;
vector<int> h={4,2,0,3,2,5};
s.trap(h);
    
    return 0;
}