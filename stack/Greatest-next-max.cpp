//https://leetcode.com/problems/next-greater-element-ii/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++) { // loop once
            if(!st.size()) st.push(i);
            else{
                if(nums[i]<=nums[st.top()]) st.push(i);
                else{
                    while(st.size() && nums[st.top()] < nums[i]){
                        if(ans[st.top()]==-1){
                            ans[st.top()]=nums[i];

                        }
                        st.pop();
                    }
                    st.push(i);
                }

            }
        }
        for(int i=0;i<n;i++) { // loop again 
            if(!st.size()) st.push(i);
            else{
                if(nums[i]<=nums[st.top()]) st.push(i);
                else{
                    while(st.size() && nums[st.top()] < nums[i]){
                        if(ans[st.top()]==-1){
                            ans[st.top()]=nums[i];

                        }
                        st.pop();
                    }
                    st.push(i);
                }

            }
        }
        return ans;
    }
};

int main (){
    
    return 0;
}