#include<bits/stdc++.h>
using namespace std;
void printname(int a){
    

    if(a==0){
        return;
    }
    cout<<"name"<<endl;
      return printname(a-1);
    
    
}


int main (){
    printname(5);
    
    return 0;
}