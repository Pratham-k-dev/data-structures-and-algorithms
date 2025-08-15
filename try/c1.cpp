#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    
	    int n,k;
	    cin>>n>>k;
	     if( (n/k)<=0|| n==k ){
	         cout<<-1<<endl;
	        
	     }
	     else if(n%k==0){
	     int c[n];
	     for(int i=0;i<n;i++){
	         c[i]=i+1;
	     }
	     int count=0;
	     for(int i=k;count<n;i=(i+1)%n,count++){
	         cout<<c[i]<<' ';
	         
	     }
	     cout<<endl;
	     }
	     else{
	         vector<int> ans;
	         int c[n];
             int flag=1;
	     for(int i=0;i<n;i++){
	         c[i]=i+1;
	     }
	         for(int i=k;i<n;i++){
	         ans.push_back(c[i]);
	         if(ans[ans.size()-1]==ans.size()){
	             flag=0;
	             break;
	         }
	         
	     }
	     for(int i=n-k;i<n;i++){
	         if((i+1)%k !=0) {
	             ans.push_back((i+1)%k);
	              if(ans[ans.size()-1]==ans.size()){
	             flag=0;
	             break;
	         }
	         }
	         else{
	             ans.push_back(k);
	             if(ans[ans.size()-1]==ans.size()){
	            flag=0;
	             break;
	         }
	             
	         }
	         
	     }
         if(flag==0){
            cout<<-1<<endl;
            continue;
         }
	     
	     for(int i=0;i<ans.size();i++){
	         cout<<ans[i]<<' ';
	     }
	     cout<<endl;
	         
	     }
	     
	}

}
