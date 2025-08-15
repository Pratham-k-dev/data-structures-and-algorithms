#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &vec,int m){
    
    int n=vec.size();
    int ans=n;
    int high=n-1;
    int low=0;
    while(low<=high){
        int mid=(high+low)/2;
        if(vec[mid]>=m){
            high=mid-1;
            ans=mid;
        }
        else if(vec[mid]<m){
            low=mid+1;


        }
    }
    return ans;
}

int main (){
    int n=10;
    vector<int> vec(n);
    vec={1,2,3,5,5,7,8,10,10};
    // cout<<lowerBound(vec,9);

    auto i=upper_bound(vec.begin(),vec.end(),5);

    cout<<*(i++);

    
    return 0;
}