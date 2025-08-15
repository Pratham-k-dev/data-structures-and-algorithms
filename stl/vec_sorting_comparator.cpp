#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>p1,pair<int,int>p2){//comparator //sort according to second element, if same descending of first


    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;


    if(p1.first<p2.first) return false;
    return true;

}

int main (){
    pair<int,int> a[]={{2,4},{3,4},{1,2}};

    int n=sizeof(a)/sizeof(a[0]);


    // sort(a,a+n,greater<int>); //for 1d array descending

    sort(a,a+n,comp);

    for(auto i:a){
        cout<<i.first<<' '<<i.second<<endl;
    }


    int m=123;
    int n2=__builtin_popcount(m); //no. of set bits // for long long n :  __builtin_popcountll(n)
    cout<<n2<<endl;

    string s="231";
    next_permutation(s.begin(),s.end());
    cout<<s;

    return 0;
}