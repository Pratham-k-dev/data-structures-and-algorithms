//https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int ans=-1;
        
        ;
        while(j<n){
            mp[s[j]]++;
            
                while(i<j && mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
            
            if(mp.size()==k) ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};

int main (){
    
    return 0;
}