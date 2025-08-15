#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> spiral(int n){
    vector<vector<int>> mat(n,vector<int>(n));
    int c=1;
    for(int k=0;k<n/2;k++){
        int i=k;
        int j=k;
        while(j<n-k){
            mat[i][j]=c++;
            j++;
        }
        j--;
        i++;

        while(i<n-k){
            mat[i][j]=c++;
            i++;

        }
        i--;
        j--;
        while(j>=k){
            mat[i][j]=c++;
            j--;
        }
        j++;
        i--;
        while(i>k){
            mat[i][j]=c++;
            i--;

        }



    }
    if(n%2==1){
        mat[n/2][n/2]=n*n;
    }
    return mat;

}

int main (){
    int n=2;
    vector<vector<int>> mat=spiral(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";

        }
        cout<<endl;
    }
    
    return 0;
}