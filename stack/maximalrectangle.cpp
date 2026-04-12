//https://leetcode.com/problems/maximal-rectangle/
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
    int histo(vector<int>& heights) {
        int ans=0;
        vector<int> p=preMin(heights);
        vector<int> s=sufMin(heights);
        int n=heights.size();
        for(int i=0;i<n;i++){
            int l=p[i];
            int r=s[i];
            ans=max(ans,heights[i]*(r-l-1)); 
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
    int maximalRectangle(vector<vector<char>>& mt) {
        int n=mt.size();
        int m=mt[0].size();

        vector<vector<int>> nxt(m,vector<int>(n));
        for(int i=0;i<n;i++){
            int z=m;
            for(int j=m-1;j>=0;j--){
                if(mt[i][j]=='1')nxt[j][i]=z-j;
                else z=j;

            }
        }
        int ans=0;
        for(int i=0;i<m;i++){ // imagine as maxi rectangle in histogram for every column
            ans=max(ans,histo(nxt[i]));

        }
        return ans;

    }
};

int main (){
    
    return 0;
}