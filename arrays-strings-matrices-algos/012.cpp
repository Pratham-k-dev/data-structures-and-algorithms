#include<bits/stdc++.h>
using namespace std;
 void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        set<int> row;
        set<int> col;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){ 
                    row.insert(i);
                    col.insert(j);

                }

            }
        }
        for(auto it=row.begin();it!=row.end();++it){
            int r=*it;
            for(int i=0;i<n;i++){
                mat[r][i]=0;
            }
        }
        for(auto it=col.begin();it!=col.end();++it){
            int c=*it;
            for(int i=0;i<m;i++){
                mat[i][c]=0;
            }
        }

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
         }

        
    } 


int main (){
    vector<vector<int>> vec;
    // vec={{1,1,1},{1,0,1},{1,1,1}};
    vec={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(vec);
   
    
    return 0;
}