#include<bits/stdc++.h>
using namespace std;

  
    int numberOfSubstrings1(string s) { //O(2n)
        int n=s.size();

        int i=0,j=0,c=0;;
        

        vector<int> h(3,0);//ele, freq map
        while(j<n){
            

            h[s[j]-'a']++;
            while(i<j && h[0] && h[1] && h[2]){
                h[s[i]-'a']--;
                
                i++;

                c++;
                c+=(n-j-1); // all substrings extended to end are valid
            }
            j++;
        }
        return c;
        
    }


    int numberOfSubstrings(string s) {// using (ele, index) map
       int n=s.size();

        int i=0,j=0,c=0;;
        

        vector<int> h(3,-1);
        while(j<n){ 
            // counting substring ending at j

            h[s[j]-'a']=j;
            if( h[0]!=-1 && h[1]!=-1 && h[2]!=-1){

                int ind=min_element(h.begin(),h.end())-h.begin();
               

                c+=h[ind]+1; //0 to min index all are valid substrings 
                
            }
            j++;
        }
        return c;
        
    }

int main (){
    cout<<numberOfSubstrings("aaabc");
    return 0;
}