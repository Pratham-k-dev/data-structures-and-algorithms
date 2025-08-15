#include<bits/stdc++.h>

using namespace std;
void linear(int n){
    if(n==0){
        return;
    }
    linear(n-1);
    cout<<n<<endl;
}
int main (){
    linear(5);
    
    return 0;
}