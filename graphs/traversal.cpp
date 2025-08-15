#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(int n,vector<int> a[],vector<bool> &visited){ //one based //TC=O(N)+O(2*E)
    queue<int> q;
    vector<int> ans;

    for(int i=0;i<n;i++){

        if(visited[i]) continue;

        q.push(i);
        visited[i]=true;
        while(!q.empty()){
            int cur=q.front();
            ans.push_back(cur);
            q.pop();
            // visited[cur]=true;
            for(int it:a[cur]){
               if(!visited[it]){ q.push(it);
            visited[it]=true;
            }
            }
        }
    }
    return ans;
}
void DFS(int cur,vector<int> a[],vector<bool> &visited,vector<int> &ans){

    ans.push_back(cur);
    visited[cur]=true;
    for(int i=0;i<a[cur].size();i++){
        if(visited[a[cur][i]]) continue;
       
        DFS(a[cur][i],a,visited,ans);
    }
}

class Solution {//no. of provinces using bfs
    void BFS(int cur,vector<vector<int>> & a,vector<bool> & v){
        int n=a.size();
        queue<int> q;
        q.push(cur);
        while(!q.empty()){
            int it=q.front();
            q.pop();
            for(int i=0;i<n;i++){
                if(a[it][i] && !v[i]){
                    q.push(i);
                    v[i]=true;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        vector<bool> v(n,false);
       int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]) continue;
        cnt++;
        v[i]=true;
        BFS(i,a,v);
    }
    return cnt;
        
    }
};
int main (){
    vector<int> a[4];
    a[0].push_back(1);
a[1].push_back(0);

a[0].push_back(2);
a[2].push_back(0);

a[1].push_back(3);
a[3].push_back(1);

a[2].push_back(3);
a[3].push_back(2);
vector<bool> v(4,false);
vector<int> t;
DFS(0,a,v,t);
for(int i:t) cout<<i<<' ';
    
    return 0;
}