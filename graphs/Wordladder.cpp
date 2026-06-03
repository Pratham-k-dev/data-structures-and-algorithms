//https://leetcode.com/problems/word-ladder/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        if(b==e) return 1;
        int n=w.size();
        
       unordered_set<string> wrd(w.begin(),w.end());
       unordered_set<string> vis;
        
     
    
        

        queue<string> q;
        
        int d=1;

        q.push(b);
        vis.insert(b);
        
        while(!q.empty()){//using bfs
            int s=q.size();
            while(s--){
                string st=q.front();
                q.pop();
                for(int j=0;j<st.size();j++){
                for(int i=0;i<26;i++){// change a letter at a time and check if its in the words set
                    string adj=st;
                    adj[j]='a'+i;
                    if(  vis.find(adj) !=vis.end()) continue;
                    if(wrd.find(adj) == wrd.end()){
                        // vis.insert(adj);
                        continue;
                    }
                    if(adj == e) return d+1;
                    q.push(adj);
                    vis.insert(adj);
                }
                }
            }
            d++;
        }
        return 0;





        
        
    }
};

int main (){
    
    return 0;
}