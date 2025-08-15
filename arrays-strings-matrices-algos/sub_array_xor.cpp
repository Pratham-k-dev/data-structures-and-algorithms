#include<bits/stdc++.h>
using namespace std;

int main (){
    int k;
    int c=0;

    vector<int> nums;
    unordered_map<int,int> mp;
    int x=0;
    mp.insert({0,1});
    for(int i=0;i<nums.size();i++){
        x=x^nums[i];
        if(mp.find(x^k)!=mp.end()){
            c+=mp.find(x^k)->second;
        }
        mp[x]++;

    }
    return 0;
}