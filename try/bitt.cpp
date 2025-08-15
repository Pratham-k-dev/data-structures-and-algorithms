
#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>> vec;
   void merge(vector<int> &nums,int l,int r,int mid,int &c){
        vector<int> L(mid-l+2);
        vector<int> R(r-mid+1);
        for(int i=0;i<L.size()-1;i++) L[i]=nums[l+i];
        L.back()=INT32_MAX;
        for(int i=0;i<R.size()-1;i++) R[i]=nums[mid+1+i];
        R.back()=INT32_MAX;
        int i=0,j=0;
        int k=l;
        while(i<L.size() && j<R.size()){
            if(i>= L.size()-1 && j>=R.size()-1 ) break;
            if(j<R.size()-1 &&i<L.size()-1&& L[i]>2*R[j]){ c+=(L.size()-i);

                vec.push_back({L[i],L.size()-i});
            
            }
            else if(j<R.size()-1 &&i<L.size()-1&& L[i]==2*R[j]){
                int it=i+1;
                while(it<L.size() && L[it]==L[it-1] ) it++;
                if(it != L.size()-1){ c+=(L.size()-it);
                
                vec.push_back({L[it],L.size()-it});
                }
            }

            if(L[i]<=R[j]){
                nums[k++]=L[i++];

            }
            else nums[k++]=R[j++];
        }

   }

 void ms(vector<int> &nums,int l,int r,int &c){
    if(l>=r) return ;

    int mid=l+(r-l)/2;
    ms(nums,l,mid,c);
    ms(nums,mid+1,r,c);
    merge(nums,l,r,mid,c);
 }   

    // int reversePairs(vector<int>& nums) {
    //     int c=0;
    //     ms(nums,0,nums.size()-1,c);
    //     return c;
        
    // }


int main (){
    vector<int>  nums={5,4,3,2,1};
    int c=0;
        ms(nums,0,nums.size()-1,c);
        for(int &i :nums) cout<<i<<' ';
        cout<<endl;
        cout<<c<<endl;
        for(auto &i:vec){
            cout<<i.first<<' '<<i.second<<endl;
        }
    
    return 0;
}