
//https://leetcode.com/problems/remove-k-digits/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char> st;
        int n=num.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            
            while(st.size() && st.top() > num[i] && cnt<k ){
                st.pop();
                cnt++;
            }
            st.push(num[i]);
            
        }
        while(st.size() && cnt<k ){
                st.pop();
                cnt++;
            }

        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size() && ans.back()=='0'){
            ans.pop_back();
        }
        if(!ans.size()) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

int main (){
    
    return 0;
}