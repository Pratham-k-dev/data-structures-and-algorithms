// https://leetcode.com/problems/trapping-rain-water/

#include<bits/stdc++.h>
using namespace std;
 int trap(vector<int>& ht) {//better sol O(n) space
         int n=ht.size();
        vector<int> l(n);
        vector<int> r(n);
        int lmax,rmax;
         lmax=rmax=INT_MIN;
         for(int i=0;i<n;i++){
            if(ht[i]>lmax){
                l[i]=ht[i];
                lmax=ht[i];
            }
            else l[i]=lmax;
         }
         for(int i=n-1;i>=0;i--){
            if(ht[i]>rmax){
                r[i]=ht[i];
                rmax=ht[i];
            }
            else r[i]=rmax;
         }
         int ans=0;
         for(int i=0;i<n;i++){
            int w=min(l[i],r[i])-ht[i];
            if(w>0) ans+=w;
         }
         return ans;

    }
    int trap_opt(vector<int> &ht){// two pointer
         
         int n=ht.size();
         if(n==1) return 0;
        int ans=0;
       int i=0,j=n-1,lmax=-1,rmax=-1;
       while(i<j){
            lmax=max(lmax,ht[i]);
            rmax=max(rmax,ht[j]);
            ans+=(min(lmax,rmax)-min(ht[i],ht[j]));
            
             if(ht[i]<=ht[j]){
                i++;
            }
            else j--;
       }
       return ans;

    

    }
int main (){
    
    return 0;
}