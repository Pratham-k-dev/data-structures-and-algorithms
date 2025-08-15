#include<bits/stdc++.h>
using namespace std;
int bs(vector<int> &vec,int n){
    
    int beg=0;
    int end=n-1;
    while(end-beg>1){
        int mid=(beg+end)/2;
        if(vec[mid]<0){
            beg=mid;
        }
        else{
            end=mid-1;
        }

    }
      if(vec[end]==-1 && vec[end+1]>0){
            return end;
      }
      if(vec[beg]==-1 && vec[end]>0){
        return beg;
      }
      else return -1;

    
}

int main (){
    vector<int> vec={1,1,1,1,1,1,1,1};

    int n=vec.size();

    cout<<bs(vec,n);

    return 0;
}