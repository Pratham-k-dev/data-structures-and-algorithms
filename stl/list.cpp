#include<bits/stdc++.h>
using namespace std;

int main (){
    list<int> l;
    l.push_back(3);
    l.emplace_back(4);
    l.push_front(2);
    l.pop_front();
    for(auto i:l){
        cout<<i<<' ';
    }
    //rest functions aresame as vector
    return 0;
}