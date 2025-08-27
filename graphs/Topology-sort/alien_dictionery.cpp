#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool DFS(int cur,vector<int> &v,unordered_map<int,unordered_set<int>> &m,string &ans,vector<int> &pv){
         v[cur]=2;
         pv[cur]=1;
         for(auto i: m[cur]){
             if(pv[i]) return true;
             
             
            if(v[i]==1&&  DFS(i,v,m,ans,pv)) return true;
         }
         ans.push_back(cur+'a');
         pv[cur]=0;
         return false;
     }
  public:
    string findOrder(vector<string> &words) {
        // code here
        string ans;
        unordered_map<int,unordered_set<int>> m;
        int n=words.size();
        int i=1;
        int c=0;
        vector<int> v(26,0);
        while(i<n){
            int j=0;
            while(j<words[i-1].size() && j<words[i].size() && words[i-1][j]==words[i][j]  ) j++;
                
                
                
                
                
            
            if(j<words[i-1].size() && j<words[i].size()){ m[words[i-1][j]-'a'].insert(words[i][j]-'a');
                
                v[words[i-1][j]-'a']=1;
                v[words[i][j]-'a']=1;
                
                
            }
            else if(j>= words[i].size() && j<words[i-1].size()) return "";
            
            
            
            
            i++;
            
            
        }
        
        
        i=0;
        vector<int> pv(26,0);
        while(i<n){
            
            for(auto j:words[i]) {
                
            
                    v[j-'a']=1;
                
              
            }
            i++;
        }
        for(int j=0;j<26;j++){
            if(v[j]!=1) continue;
            if(DFS(j,v,m,ans,pv)) return "";
        }
       reverse(ans.begin(),ans.end());
       
       return ans;
       
        
    }
};

int main (){
    Solution o;

    vector<string> s={"dddc", "a" ,"ad" ,"ab" ,"b" ,"be", "cd" ,"cded"};
    o.findOrder(s);
    return 0;
}
