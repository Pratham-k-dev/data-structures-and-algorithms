#include<bits/stdc++.h>
using namespace std;
class Solution {

    void fn1(vector<int> &a, vector<int> &t ){
        int n=a.size();
         stack<int> st;
        for(int i=0;i<n;i++){
            if(a[i] > 0){
                if(st.size() && a[st.top()] <= a[i] ) st.push(i);
                else if(!st.size()) st.push(i);
            }
            else{
                
                    while(st.size() && a[st.top()] < -a[i]){
                        st.pop();
                    }
                    if(st.size()) t[i]=0;
                    if(st.size() && a[st.top()] == -a[i]) st.pop();
                
                
            }
        }
    }
    void fn2(vector<int> &a, vector<int> &t ){
        int n=a.size();
         stack<int> st;
        for(int i=n-1;i>=0;i--){
            if(a[i] < 0){
                if(st.size() && -a[st.top()] <= -a[i] ) st.push(i);
                else if(! st.size()) st.push(i);
            }
            else{
                
                    while(st.size() && -a[st.top()] < a[i]){
                        st.pop();
                    }
                    if(st.size()) t[i]=0;
                    if(st.size() && a[st.top()] == -a[i]) st.pop();
                
                

            }
        }
    }
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n=a.size();
        vector<int> t(n,1);
        fn1(a,t);
        fn2(a,t);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(t[i]) ans.push_back(a[i]);
        }
        return ans;

        
    }
};

int main (){
    Solution s;
    vector<int> v={-2,1,-1,-1};
    s.asteroidCollision(v);
    
    return 0;
}