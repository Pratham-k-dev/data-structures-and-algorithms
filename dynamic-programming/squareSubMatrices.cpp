//https://leetcode.com/problems/count-square-submatrices-with-all-ones/
#include<bits/stdc++.h>
using namespace std;


    int countSquares(vector<vector<int>>& mat) { //my sol (o(n^3)) {not the best}
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> top(n, vector<int>(m, -1)); //stores topmost 1
        vector<vector<int>> left(n, vector<int>(m, -1)); // stores left most
        for (int j = 0; j < m; j++) {
            int i = 0, p = -1;
            while (i < n) {
                while (i < n && mat[i][j] == 0)
                    i++;
                p = i;
                while (i < n && mat[i][j] == 1) {
                    top[i][j] = p;
                    i++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int j = 0, p = -1;
            while (j < m) {
                while (j < m && mat[i][j] == 0)
                    j++;
                p = j;
                while (j < m && mat[i][j] == 1) {
                    left[i][j] = p;
                    j++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a=i,b=j;
                while(a<n && b<m && mat[a][b]==1 && top[a][b]<=i && left[a][b]<=j){
                    a++;
                    b++;
                    ans++;
                }
            }
        }   
        return ans;    
    }


      int countSquares(vector<vector<int>>& mat) { // TC optimized to O(n*m)
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++) dp[i][0]=mat[i][0];
        for(int i=0;i<m;i++) dp[0][i]=mat[0][i];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j])
                dp[i][j]=1+min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]}); // A square grows only as much as its weakest side (left, top, diagonal).
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=dp[i][j];
            }
        }
        return ans;
        
    }



int main (){
    
    return 0;
}