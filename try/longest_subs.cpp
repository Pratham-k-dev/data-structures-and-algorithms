#include<bits/stdc++.h>
using namespace std;
int f(string s){
    int i=0,j=0;
    int max=INT_MIN;
    int n=s.length();
    while(i<n){
        string sub;
       
        int ind;
        while(j<n && (ind=sub.find(s[j]))==string::npos){
            sub.push_back(s[j]);
            j++;
        }
        int m=sub.length();
        if(max<m){
            max=m;
        }
        if(j>=n){
            break;
        }
        i+=ind+1;
        j=i; 


    }
    return max;
}

int main (){
    string s="pwwkew";
    cout<<f(s);
    
    return 0;
}