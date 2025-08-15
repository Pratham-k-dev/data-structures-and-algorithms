#include<bits/stdc++.h>
using namespace std;
void sum2_brute(vector<int> vec,int k){
map<int,int> m;
int n=vec.size();
for(int i=0;i<n;i++){
    if(m.find(k-vec[i])!=m.end()){
        if(i<m[k-vec[i]]){
        cout<<"("<<i<<","<<m[k-vec[i]]<<")"<<endl;
        return;
        }
        else{
            cout<<"("<<m[k-vec[i]]<<","<<i<<")"<<endl;
        return;
        }
    }
    m[vec[i]]=i;

}
cout<<"no such pair"<<endl;
}
void sum2_better(vector<int> vec ,int k)
{   
    sort(vec.begin(),vec.end());
    int n=vec.size();
    int i=0;
    int j=n-1;
    while(i<j){
        int sum=vec[i]+vec[j];
       if(sum==k){
        cout<<"yes"<<endl;
        return;
       }
       else if(sum<k){
        i++;
       }
       else {
        j--;
       }
    }

cout<<"no"<<endl;

}
int main (){
    vector<int> vec;
    vec={1,2,3,4,5};
    // sum2_brute(vec,6);
    // sum2_better(vec,10);
   
   
    return 0;
}