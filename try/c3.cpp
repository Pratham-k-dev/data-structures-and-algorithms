#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	   ll arr[n];
	   ll max=INT_MIN;
	   for(int i=0;i<n;i++){
	       cin>>arr[i];
	       if(arr[i]>max){
	           max=arr[i];
	       }
	   }
	   vector<int> ind;
	   for(int i=0;i<n;i++){
	       if(arr[i]==max) ind.push_back(i);
	   }
	   int f=0;
	   for(int i=0;i<ind.size();i++){
	       if(ind[i]%2) f=1;
	   }
	   
	   if(f){
	       cout<<max+(n-1)/2<<endl;
	   }
	   else{
	       cout<<max-1+(n-1)/2<<endl;
	   }
	   
	    
	}

}
