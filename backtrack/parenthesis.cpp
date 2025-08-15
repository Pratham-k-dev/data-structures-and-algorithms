//https://leetcode.com/problems/generate-parentheses/?envType=problem-list-v2&envId=string
#include<bits/stdc++.h>
using namespace std;
class Solution {
    
   void fun(int a,int b,int n,vector<string> &ans,string temp){
    if(temp.size()==2*n){
        ans.push_back(temp);
        return;
    }

    if(a<n) fun(a+1,b,n,ans,temp+'('); //if opening (less than n
    if(b<a) fun(a,b+1,n,ans,temp+')'); // if closing  ) s less than those open

   }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0) return ans;
        string temp;
        fun(0,0,n,ans,temp);
        return ans;
      
        

    }
};

int main (){
    
    return 0;
}