//https://www.geeksforgeeks.org/dsa/merging-intervals/
#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        
        // Code here
        
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        int s=arr[0][0];
        int e=arr[0][1];
        vector<vector<int>> ans;
        
        for(int i=1;i<n;i++){
            if(arr[i][0]> e){
                ans.push_back({s,e});
                s=arr[i][0];
                e=arr[i][1];
                continue;
                
            }
            
            s=min(s,arr[i][0]);
            e=max(e,arr[i][1]);
        }
        ans.push_back({s,e});
        
        return ans;
        
    }
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
       map<int ,pair<int,int>> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
                mp[arr[i][0]].first++;
                mp[arr[i][1]].second++;
        }
        int s=-1,e=-1;
        int o=0,c=0;
        vector<vector<int>> ans;
        for(auto x:mp){
            if(s==-1 && x.second.first>0){
                s=x.first;
                o+=x.second.first;
            }
            else if(x.second.first>0){
                o+=x.second.first;
            }
            if(e==-1 && x.second.second>0){
                e=x.first;
                o-=x.second.second;
            }
            else if(x.second.second>0){
                e=x.first;
                 o-=x.second.second;

            }
            
            if(o==0 && s!=-1 && e!=-1){
                ans.push_back({s,e});
                s=-1;
                e=-1;
            }
        }
        return ans;
        
    }



int main (){
    vector<vector<int>> v={{1,3},{2,4},{6,8},{9,10}};
    vector<vector<int>> ans=mergeOverlap(v); 

    for(auto x: ans){
        for (auto y:x) cout<<y<<' ';
        cout<<endl;
    }



    return 0;
}