#include<bits/stdc++.h>
using namespace std;
int bs(vector<int> &vec,int n,int q){
    if(q-vec[0]<=0){
        int beg=0;
    int end=n-1;
    while(end-beg>1){
        int mid=(beg+end)/2;
        if(q-vec[mid]<0){
            beg=mid;
        }
        else{
            end=mid-1;
        }

    }
    if(end==n-1 && q-vec[end]<=0) return end;
    if(q-vec[end]<0 && q-vec[end+1]>=0){
        return end;
  }
  if(q-vec[beg]<0 && q-vec[end]>=0){
    return beg;
  }
  else return -1;
    }
    else{
        int beg=0;
        int end=n-1;
        while(end-beg>1){
            int mid=(beg+end)/2;
            if(q-vec[mid]>0){
                beg=mid;
            }
            else{
                end=mid-1;
            }
    
        }
        if( q-vec[n-1]>0) return end;
        if(q-vec[end]>0 && q-vec[end+1]<=0){
            return end;
      }
      if(q-vec[beg]>0 && q-vec[end]<=0){
        return beg;
      }
      else return -1;

    }
    
}
int main (){
    vector<int> vec={1,3,5,100};
    int n=vec.size();
    int q=107;
    int i=bs(vec,n,q);
    cout<<i<<endl;
    if(q-vec[0]<=0){
        if(i==-1){
            if(vec[0]==0) cout<<0<<endl;
            else cout<<1<<endl;
        }
        else if(i<n && q-vec[i+1]==0) cout<<0<<endl;
        else if(i%2==0) cout<<-1<<endl;
        else if(i%2!=0) cout<<1<<endl;
        
    }
    else{
        if(i<n && q-vec[i+1]==0) cout<<0<<endl;
        else if((n-i)%2==0) cout<<-1<<endl;
        else if((n-i)%2!=0) cout<<1<<endl;

    }
   
    return 0;
}