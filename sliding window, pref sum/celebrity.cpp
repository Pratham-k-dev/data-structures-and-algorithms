//https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        
        int n=mat.size();
       int i=0,j=n-1;
       
       while(j>i){
           if(mat[i][j] ==1) i++;
           else if(mat[j][i]==1) j--;
           else {
               i++;
               j--;
           }
       }
       
       if(i>j) return -1;
       for(int k=0;k<n;k++){
           if(k!=i && mat[i][k]==0 && mat[k][i]==1) {}
           else if(k!=i) return -1;
       }
       
       return i;
       
       
        
        
    }
};

int main (){
    
    return 0;
}