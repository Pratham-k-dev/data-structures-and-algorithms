#include<bits/stdc++.h>
using namespace std;
class Solution {
    int lcs(string &s1, string &s2) { //tabulation
        int n=s1.size(),m=s2.size();
        // vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> prev(m,0);
        vector<int> cur(m,0);
       
        

        for(int i1=0;i1<n;i1++){
            for(int i2=0;i2<m;i2++){
                if(s1[i1]==s2[i2]){
                     cur[i2]=1+(i1>0 && i2>0?prev[i2-1] :0);
                }
                else{
                    int x=0,y=0;
                    if(i1>0) x=prev[i2];
                    if(i2>0) y=cur[i2-1];
                    cur[i2]=max(x,y);
                }
            }
            prev=cur;
        }
        return prev[m-1];

    }
public:
    int longestPalindromeSubseq(string s) {
        string s1(s.rbegin(),s.rend());
        return lcs(s,s1);
    }
};

int main (){
    
    return 0;
}