#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> preMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty())
                st.push(i);
            else {
                if (arr[i] > arr[st.top()]) {
                    st.push(i);
                } else {
                    while (st.size() && arr[i] <= arr[st.top()]) {
                        ans[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        
        return ans;
    }
    vector<int> sufMin(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty())
                st.push(i);
            else {
                if (arr[i] >= arr[st.top()]) {
                    st.push(i);
                } else {
                    while (st.size() && arr[i] < arr[st.top()]) {
                        ans[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        vector<int> p=preMin(heights);
        vector<int> s=sufMin(heights);
        int n=heights.size();
        for(int i=0;i<n;i++){
            int l=p[i];
            int r=s[i];
            ans=max(ans,heights[i]*(r-l-1)); // trying to expand a perticular height in both directions
        }
        return ans;
    }
};

int main (){
    
    return 0;
}