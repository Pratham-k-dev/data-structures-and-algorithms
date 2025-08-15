#include<bits/stdc++.h>
using namespace std;
 string convert(string s, int k) {
        if(k==1) return s;
        int sz=s.length();
        string ans;
        ans.resize(sz);
        if(k==2){
            int col=(sz%2==0)?(sz/2):(sz/2 +1);
            
            for(int i=0;i<col;i++){
                ans.push_back(s[2*i]);
            }
            for(int i=0;i<col;i++){
              if(2*i+1<sz)  ans.push_back(s[2*i+1]);
            }

            return ans;
        }
        int col=(sz+k-2)%(2*k-2)?((sz+k-2)/(2*k-2) +1):(sz+k-2)/(2*k-2);
        
        

        

        for(int i=1;i<=k;i++){
            if(i==1 || i==k){
                    int l=i;
                for(int j=0;j<col;j++){
                    if((l-1)<sz) ans.push_back(s[l-1]);
                    l+=k+k-2;
                }
            }
            else{
                int l=i-1;
                int m=i-1 +2*(k-i);
                int c=0;
                for(int j=0;j<(2*col-1);j++){
                    if(j%2==0){
                        
                            if(l<sz) ans.push_back(s[l]);
                            l+=k+k-2;
                        
                    }
                    else{
                        
                            if(m<sz) ans.push_back(s[m]);
                           m=(i-1)+2*(k-i)+(++c)*(k+k-2);
                        
                    }
                }
            }
        }
       return ans;
        
    }

int main (){
    string s="PAYPALISHIRING";
    cout<<convert(s,3);
    return 0;
}