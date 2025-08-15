#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int b[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int p;
	     for(int i=0;i<n;i++){
	        cin>>b[i];
	        if(b[0]==a[i]){
	            p=i;
	        }	    }
	    int d=1;
	    int i=1;
	    int f=0;
	    
	    while(p+d<n && p-d>=0){
	        if(p+d<n && p-d>=0 ){
	            if(a[p-d]<=a[p+d] && b[i]!=a[p-d] && b[++i]!=a[p+d]){
	                f=1;
	                break;
	            }
	            else if(a[p-d]>a[p+d] && b[i]!=a[p+d] && b[++i]!=a[p-d]){
	                f=1;
	                break;
	            }
	        }
	        else if(p+d>=n && b[i]!=a[p-d]) f=1;
	        else if(p-d<0 && b[i]!=a[p+d]) f=1;
	        
	        i++;
	        d++;
	            
	        
	    }
	    
	    if(f){
	        cout<<-1<<endl;
	    }
	    else{
	        cout<<p+1<<endl;
	    }
	}
}
