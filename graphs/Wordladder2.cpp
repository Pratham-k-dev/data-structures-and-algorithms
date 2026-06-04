//https://www.geeksforgeeks.org/problems/word-ladder-ii/1
#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {// not verygood approach, accumulates lot of space
  public:
    vector<vector<string>> findSequences(string b, string e,
                                         vector<string>& w) {
        // code here
          if(b==e) return {};
        int n=w.size();
        
       unordered_set<string> wrd(w.begin(),w.end());
       unordered_set<string> vis;
       vector<vector<string>> ans;
       if(wrd.find(e)==wrd.end()) return {};
        
     
    
        

        queue<vector<string>> q;
        
        int d=1;

        q.push({b});
        int found=0;
        
        while(!q.empty()){
            int s=q.size();
            unordered_set<string> recent;
            while(s--){
                auto st=q.front();
                string wd=st.back();
                recent.insert(wd);
                q.pop();
                for(int j=0;j<wd.size();j++){
                for(int i=0;i<26;i++){
                    string adj=wd;
                    adj[j]='a'+i;
                    if(adj == wd) continue;
                    
                    if(wrd.find(adj) == wrd.end()){
                        // vis.insert(adj);
                        continue;
                    }
                    vector<string> temp=st;
                    temp.push_back(adj);
                    if(adj == e) {
                        found=1;
                        ans.push_back(temp);
                        
                    }
                    else q.push(temp);
                    
                }
                }
            }
            for(const string &x:recent) wrd.erase(x);// erase only when the whole level is complete
            if(found) break;
            d++;
        }
        // cout<<found<<' '<<d;
        return ans;

    }
};
/*

note:
the extra things seen here were done for debugging
*/
class Solution {//little optimized
    bool Dfs(const string &word,vector<vector<string>> &ans, unordered_map<string,unordered_set<string>>&par,vector<string> &cur,int dep,unordered_set<string> &pathvis){
       
       //dfs to construct those parse trees
        if(dep<=0) return false;
        if(pathvis.find(word)!=pathvis.end()) return true;
        if(par[word].empty()){
            ans.push_back(vector<string>(cur.rbegin(),cur.rend()));
            return true;
        }
            pathvis.insert(word);
        bool f =true;
        for(auto &w: par[word]){
            cur.push_back(w);
           f &= Dfs(w,ans,par,cur,dep-1,pathvis);
            cur.pop_back();
        }
           pathvis.erase(word);
        return f;
    }
public:
    vector<vector<string>> findLadders(string b, string e, vector<string>& w) {
         if(b==e) return {{b}};
        int n=w.size();
        
       unordered_set<string> wrd(w.begin(),w.end());
       unordered_map<string,unordered_set<string>> par;//storing parent pointers
       unordered_set<string> vis;
    
     
    
        

        queue<string> q;
        
        int d=1;

        q.push(b);
        par[b]={};
        vis.insert(b);
        int found=0;
        
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string st=q.front();
                q.pop();
                for(int j=0;j<st.size();j++){
                for(int i=0;i<26;i++){
                    string adj=st;
                    adj[j]='a'+i;
                    if(adj == st) continue;
                    
                    if(wrd.find(adj) == wrd.end()){
                        // vis.insert(adj);
                        continue;
                    }
                    if(adj!=b )par[adj].insert(st);
                    if(  vis.find(adj) !=vis.end()) {
                            continue;

                    }
                    if(adj == e) {
                        found=1;
                       
                    }
                    q.push(adj);
                    // par[adj].insert(st);
                    vis.insert(adj);
                }
                
                }
            }
            if(found)break;
            d++;
        }

        if(!found)
        return {};

        
        vector<vector<string>> ans;
        vector<string> cur;
        cur.push_back(e);
        int dep=0;
        unordered_set<string> pathvis;
        
        Dfs(e,ans,par,cur,d+1,pathvis);
        return ans;
        
    }
};

int main (){
    
    return 0;
}