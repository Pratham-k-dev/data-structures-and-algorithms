#include<bits/stdc++.h>
using namespace std;

int main (){
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.front();
    cout<<' '<<q.back()<<endl;
    q.pop();
    cout<<q.front();
    cout<<' '<<q.back()<<endl;


    //priority_queue<int> p  //greter in at top //push and pop in logn (since uses heap)
    //priority_queue<int,vector<int>,greater<int>> p  //for smaller at top


    deque<int> dq={1,2,3}; //random access possible
    cout<<dq[2];


    return 0;
}