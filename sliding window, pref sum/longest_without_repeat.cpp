//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {// method 1 using (char,count) map
        int n=s.size();
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            while(i<j && mp[s[j]]){
                mp[s[i]]--;
             i++;
            }

            ans=max(ans,j-i+1);
            mp[s[j]]++;
            j++;
        }
        return ans;
        
    }
     int lengthOfLongestSubstring(string s) {//method 2 using (char,prev seen index) map
        int n=s.size();
        vector<int> hash(255,-1);
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            if(hash[s[j]]>=i){
                i=hash[s[j]]+1;
            }

            ans=max(ans,j-i+1);
            hash[s[j]]=j;
            j++;
        }
        return ans;
        
    }
};
int main (){
    
    return 0;
}