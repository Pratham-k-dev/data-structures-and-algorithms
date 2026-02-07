//https://leetcode.com/problems/longest-repeating-character-replacement/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {// O(26*n)
        int n=s.size();
        int i=0,j=0,ans=0;
        vector<int> hash(26,0);
        while(j<n){
            hash[s[j]-'A']++;;
            if((j-i+1)-*max_element(hash.begin(),hash.end()) >k){// always lookingfor better window no shrinking
                hash[s[i]-'A']--;
                i++;
                j++;
            }
            else{

            ans=max(ans,(j-i+1));
            j++;
            }
        }
        return ans;
        
    }

      int characterReplacement(string s, int k) {// extra scaning of 26 removed
        int n=s.size();
        int i=0,j=0,ans=0;
        vector<int> hash(26,0);
        
        int maxFreq = 0;
        while(j<n){
            hash[s[j]-'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']); // no need to shrink max freqas we are always looking for longer length
            if( (j-i+1)-maxFreq >k){ 
                hash[s[i]-'A']--;
                i++;
                j++;
            }
            else{

            ans=max(ans,(j-i+1));
            j++;
            }
        }
        
        return ans;
        
    }
};

int main (){
    
    return 0;
}