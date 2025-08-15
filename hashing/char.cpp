#include<bits/stdc++.h>

using namespace std;
int main (){
    map<int,char> m1;
    auto it=m1.begin();
    for(int i=0;i<5;i++){
        char c;
        cin>>c;
        m1[c-'a'+1]=c;

    }
    for(auto it:m1){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}