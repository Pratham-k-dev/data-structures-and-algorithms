#include<bits/stdc++.h>
using namespace std;
int check_palindrome(char str[],int n,int i){
    if(i>=n/2) {return 1;}
    if(str[i]!=str[n-i-1]) {return 0;}
     check_palindrome(str,n,i+1);
}
int main (){
    
    char str[10];
   
    cin.getline(str,10);
     int n=strlen(str);
cout<<check_palindrome(str,n,0);
    
    return 0;
}