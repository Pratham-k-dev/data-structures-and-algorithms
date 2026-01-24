//https://leetcode.com/problems/maximal-rectangle/
#include <bits/stdc++.h>
using namespace std;
int maximalRectangle(vector<vector<char>> &matrix) //TC=O(n^3) (not the best)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (j == m - 1)
            {
                a[i][j] = (matrix[i][j] == '1');
            }
            else if (matrix[i][j] == '1')
            {
                a[i][j] += 1+(a[i][j + 1]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
                continue;
            int temp = 0, l = 201;

            for (int k = i; k < n; k++)
            {
                l = min(l, a[k][j]);
                ans = max(ans, (k - i + 1) * l);
            }
        }
    }
    return ans;
}

class Solution {//optimised O(n^2)
    int f(vector<int> &a){//largest rectangle in histogram
        int n=a.size();
        stack<int> s;
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i=0;i<n;i++){ //claculating left nearest smaller
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(s.empty()) left[i]=-1;
            else left[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){ //calculating right nearest smaller
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(s.empty()) right[i]=a.size();
            else right[i]=s.top();
            s.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){ 
            ans=max(ans,a[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> a(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
                if(i==n-1) {
                    a[i][j]=(matrix[i][j]=='1');
                }
                else if(matrix[i][j]=='1'){
                    a[i][j]+=1+(a[i+1][j]);
                }
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
           ans=max(ans,f(a[i]));
        }
        return ans;

    }
};

int main()
{
    vector<vector<char>> m =  {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
};
cout<<maximalRectangle(m);
    return 0;
}