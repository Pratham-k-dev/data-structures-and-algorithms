#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &arr,int k)//+ves only
{
    int i = 0, j = 0;
    int sum=arr[0];
    int c= 0;
    while (j < arr.size())
    {
        
        while (i<=j && sum > k)
        {
            sum -= arr[i];
            i++;
        }
        if (i<=j && sum == k)
        {
            c++;
        }
        
        j++;
        if(j<arr.size()){sum+=arr[j];}
        
    }
    return c;

}

int g(vector<int> &arr,int k){ //mine
    multimap<int,int> m;
    int c=0;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
       m.insert({sum,i});
        
        // int n=0;
        // auto it=m.begin();
        // while(it!=m.end()){
        //     n++;
        //     if(it->second!=i &&(it->first)==(sum-k) ){
        //         cout<<it->first<<' '<<it->second<<endl;
        //         c++;
        //     }
        //     it++;
        // }

        c+=m.count(sum-k);
        if(sum== sum-k) c--;

        if( sum==k ){
            cout<<i<<endl;
            c++;
        }

        
    }

    return c;
}


int h(vector<int> &arr,int k){ //mostopt  (consider this)
    unordered_map<int,int> m;
    int c=0;
    int sum=0;
    m[0]=1;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
       
        
       c+=m[sum-k];

       
        m[sum]++;

        
    }

    return c;
}
int main (){
    vector<int>arr={-1,-1,1};
    cout<<g(arr,0);
    
    return 0;
}