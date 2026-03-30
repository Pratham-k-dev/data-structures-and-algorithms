//https://leetcode.com/problems/sum-of-subarray-minimums/
/*
problem is case sensitive we may encounter repition while counting

so by WLOG,
we will ensure the repeated numbers occur only in one side, i.e while suffix min we consider strict minimum as minimun, but in prefix case we make equal case as minimum too

*/
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
        for(int x:ans) cout<<x<<' ';
        cout<<endl;
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
        for(int x:ans) cout<<x<<' ';
        cout<<endl;
        return ans;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int x = 1e9 + 7;
        vector<int> p = preMin(arr);
        vector<int> s = sufMin(arr);
        int n=arr.size();
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {// counting by considering arr[i] as minimum
            
            long long tot= (1LL*arr[i]*(i - p[i]) * (s[i] - i))%x; // couting subarrays (pref combis)*(suffix combis)
            ans = (ans + 1LL*tot) % x;
            
        }
        return (int)ans;
    }
};

int main (){
    Solution s;
    vector<int> v={71,55,82,55};
    s.sumSubarrayMins(v);
    
    return 0;
}