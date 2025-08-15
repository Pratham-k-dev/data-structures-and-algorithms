#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int a[n];
    int f=0;
    map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<n) f=1;
        m[a[i]]++;
    }
    if(!f){
        cout<<n<<endl;
        continue;
        
    }
    int sum=0;
    int k=0,p;
    for(auto i:m){
        
        // if(i.first>=i.second){
        //     sum+=i.second;
        // }

        // if(k==0 && i.first<i.second ){
        //     sum+=i.first;
        //     p=i.first;
        //     k=1;
        //     continue;
        // }
        // else if(k && (i.first-p)<i.second){
        //     sum+=(i.first-p);
        //     p=i.first;
        // }

        if((i.first-p)<i.second){
            k=1;
            p=i.first;
        }
       

    }
    if(k){
        for(int i=0;i<n;i++) {
            if(a[i]>p) sum++;
        }
        cout<<sum+p<<endl;
    }
    else cout<<n<<endl;
    
    
}
}
