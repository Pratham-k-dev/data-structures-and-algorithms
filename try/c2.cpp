#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int d=0;
        vector<int> vec(n);
        map<int,int> hash;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            hash[vec[i]]++;
            if(hash[vec[i]]>1){
                d=1;
            }
            
        }
        
        if(d==0){
            cout<<n<<endl;
            continue;
        }
        else{
            int ib;
            int ie;
            int iem,ibm;
            int f;
            int max_d=INT_MIN;
            for(int i=0;i<n;i++){
                if(hash[vec[i]]>1){
                     f=vec[i];
                     ib=i;
                     for(int j=n-1;j>=0;j--){
                        if(vec[j]==f){
                             ie=j;
                            break;
                        }
                    }
                    // max_d=max(max_d,ie-ib);
                    if(max_d<ie-ib)
                    {
                        max_d=ie-ib;
                        iem=ie;
                        ibm=ib;

                    }
                    
                    
                }
            }
            int c=0;
            map<int,int> count;
                    for(int i=0;i<ibm;i++){
                        if(!count[vec[i]]) {c++;}
                        count[vec[i]]++;
                    }
                    for(int i=iem+1;i<n;i++){
                        if(!count[vec[i]]) {c++;}
                        count[vec[i]]++;

                    }
            
            
            cout<<c+1<<endl;
        }
    }

}
