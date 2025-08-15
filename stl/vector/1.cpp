#include<bits/stdc++.h>
using namespace std;

int main (){
    

    vector<int> v({1,2,3,4,5});



    // v.erase(v.begin()+2);
    // v.erase(v.begin()+1,v.begin()+3);

    // v.insert(v.begin()+2,5);
    
    // v.insert(v.begin()+2,2,5);

    vector<int> v2({2,3,6});
    v.insert(v.begin()+2,v2.begin(),v2.begin()+2);
    for(auto i:v){
        cout<<i<<' ';
    }
    cout<<endl;
    
    return 0;
}
