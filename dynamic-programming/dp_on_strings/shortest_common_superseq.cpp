//https://leetcode.com/problems/shortest-common-supersequence/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    void Lcs(string &text1, string &text2,vector<int> &ind1,vector<int> &ind2) { //tabulation , 1 based  indexed
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       
        

        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=m;i2++){
                if(text1[i1-1]==text2[i2-1]){
                     dp[i1][i2]=1+dp[i1-1][i2-1];
                }
                else{
                    
                     int x=dp[i1-1][i2];
                     int y=dp[i1][i2-1];
                    dp[i1][i2]=max(x,y);
                }
            }
        }
        int i=n,j=m;
       
        while(i>0 && j>0){ //storing indexes where lcs chars occur
            if(text1[i-1]==text2[j-1]){
                
                 ind1[i-1]=1;
                 ind2[j-1]=1;
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
            
        }
        

    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        
         string ans="";
         vector<int> ind1(n,0);
         vector<int> ind2(m,0);
         Lcs(str1,str2,ind1,ind2);
         int i=0,j=0;
       

         i=0,j=0;
         int k=0;

         while(i<n && j<m){//pushing in relative order to lcs
            while(i<n && ind1[i]==0){
                ans+=str1[i];
                i++;
            }
            while(j<m && ind2[j]==0){
                ans+=str2[j];
                j++;
            }
           if(i<n) ans+=str1[i];
            i++,j++;
            
         }
         while(i<n){
            ans+=str1[i];
            i++;
         }
         while(j<m){
            ans+=str2[j];
            j++;
         }
        
         return ans;

    }
};

int main (){
    
    return 0;
}