#include<bits/stdc++.h>
using namespace std;
vector<int> spiral(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<int> arr(n*m);


    int c=0;
    for(int k=0;k<n/(2.0);k++){
        int i=k;
        int j=k;
        while(j<m-k){
           if(c<n*m) arr[c++]=mat[i][j];
            j++;
        }
        j--;
        i++;

        while(i<n-k){
            if(c<n*m) arr[c++]=mat[i][j];
            i++;

        }
        i--;
        j--;
        while(j>=k){
            if(c<n*m) arr[c++]=mat[i][j];
            j--;
        }
        j++;
        i--;
        while(i>k){
            if(c<n*m) arr[c++]=mat[i][j];
            i--;

        }



    }
    // if(n%2==1){
    //     int j=n/2;
    //     for(int i=(n/2);i<m-(n/2);i++){
    //         arr[c++]=mat[j][i];
    //     }
    // }
   
    return arr;
    

}

int main (){
    vector<vector<int>> mat={{1,2},{3,4},{5,6},{7,8},{9,10}};
    int n=mat.size();
    int m=mat[0].size();
    vector<int> arr=spiral(mat);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";

    }
    // cout<<n<<' '<<m;
    
    return 0;
}