#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isPrime(int x){
        if(x==1 ||x==0) return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }

    void DFS(int cur,vector<int> & nums,vector<bool> &visited,unordered_map<int,unordered_set<int>> &m,int j,int &ans){

        int n=nums.size();
        if(cur==n-1){ ans=min(ans,j);
        
        return;
        }
        visited[cur]=true;
        if(cur+1<nums.size() && !visited[cur+1]){ DFS(cur+1,nums,visited,m,j+1,ans);
        
        visited[cur+1]=false;
        }
        if(cur-1>=0 && !visited[cur-1]){ DFS(cur-1,nums,visited,m,j+1,ans);
        visited[cur-1]=false;
        }
        if(isPrime(nums[cur])){
            for(int k=nums[cur];k<=((1e5));k+=nums[cur]){
                for(const int &i: m[k]){
                    if( !visited[i]){ 
                        cout<<j<<' '<<i<<endl;
                        DFS(i,nums,visited,m,j+1,ans);
                    visited[i]=false;
                    }
                }
            }
        }
        // visited[cur]=false;
    }
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,unordered_set<int>> hash;
        for(int i=0;i<n;i++) hash[nums[i]].insert(i);
        vector<bool> v(n,false);
        int ans=INT_MAX;

        DFS(0,nums,v,hash,0,ans);
        return ans;

        
    }
};

int main (){
    vector<int> vec={3,7,5,7,1,6};
    Solution a;
    cout<<a.minJumps(vec);
    
    return 0;
}