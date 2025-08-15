#include<bits/stdc++.h>
using namespace std;
void transpose(vector<vector<int>> &mat){
    int n=mat.size();
    int i=0,j;
    while(i<n-1){
        j=i+1;
        while(j<n){
            swap(mat[i][j],mat[j][i]);
            j++;
        }
        i++;
    }

    
}

int main (){
    int n=3;
    vector<vector<int>> mat={{1,2,3},{3,4,5},{6,7,8}};
    transpose(mat); 
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(mat[i][j],mat[i][n-1-j]);

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}