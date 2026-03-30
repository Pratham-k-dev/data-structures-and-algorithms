#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();
        int ans = n + 1;
        int it1 = -1;
        int i = 0, j = 0;

        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        for (int i = 0; i < m; i++){

            
            mp1[t[i]]++;
        }
        int c = m;
        while (j < n) {
            if (mp1.find(s[j]) != mp1.end() ){
                mp[s[j]]++;
                if(mp[s[j]] >= mp1[s[j]]) c++;
            
               

            }

            while (i<=j && c == 0) {
                
                if (i<=j &&  j - i + 1 < ans) {
                    it1 = i;
                    ans=j-i+1;
                }
                if (mp1.find(s[i]) != mp1.end() ){

                     c++;
                    mp[s[i]]++;


                }
        
                
                
                i++;
            }
            j++;
        }
        cout<<it1<<' '<<ans<<' ';

        return (it1 !=-1? s.substr(it1, ans) : "");
    }
int main() {
	// your code goes here
	string s="ADOBECODEBANC";
	string t="ABC";
	cout<<minWindow(s,t);

}
