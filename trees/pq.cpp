#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(int a,int b){
        return a<b;
    }
};

int main (){
    priority_queue<int,vector<int> , cmp> pq;
    for(int i=1;i<10;i++) pq.push(i);
    while(!pq.empty()){
        cout<<pq.top()<<' ';
        pq.pop();
    }
    return 0;
}