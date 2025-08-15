#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	        int n,x;
	        cin>>n>>x;
	        vector<int> vec(n);
	        vector<int> used(n,0);
	        unordered_set<int> st;
	        
	        
	        for(int i=0;i<n;i++){

				if(x==(i+1)){

					vec[i]=x;
					st.insert(x);
					used[i]=1;

				}
	            else if((x|(i+1))==x){
	                int j=x^(i+1);
	                if(0<j && j<=n && st.find(j)==st.end()){
	                    vec[i]=j;
	                    st.insert(j);
	                    used[i]=1;
	                }
	            }
	        }
for(int i=0;i<n;i++){
	            cout<<used[i]<<' ';
	        }
            cout<<endl;

            int k=1; 
	        for(int i=0;i<n;i++){
	            if(!used[i] ){
	                
	                while(st.find(k)!=st.end()) k++;
	                vec[i]=k;
	                k++;
	                
	            }
	           
	            
	        }
	        
	        
	        for(int i=0;i<n;i++){
	            cout<<vec[i]<<' ';
	        }
	        cout<<endl;
	}

}
