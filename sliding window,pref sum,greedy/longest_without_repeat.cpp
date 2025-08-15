//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           
    int n=s.length();
    int i=0;
    int maxi=0;
        unordered_set<char> st;
        int j=0;
    while(i<n){

        while( st.count(s[i])){
            st.erase(s[j]);
            j++;
        }
        st.insert(s[i]);
        maxi=max(maxi,i-j+1);
        i++;
    }
    return maxi;
    
        
    }
};
int main (){
    
    return 0;
}