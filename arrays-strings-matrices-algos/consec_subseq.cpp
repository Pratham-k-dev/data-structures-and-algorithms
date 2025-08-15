//length of longest consecutive sequence

#include<bits/stdc++.h>
using namespace std;

int longest_consec_subseq( vector<int> &vec){//better not best
    sort(vec.begin(),vec.end());
    

    int n=vec.size();
int i=0,l=1;

    while(i<n){
        int j=i,c=1;
        while(j<n-1 ) {
            if(vec[j+1]==vec[j]) j++;
            else if(vec[j+1]==(vec[j]+1)) {
                j++;
                c++;
            }
            else break;
        }

        l=max(l,c);
        i=j;
    }
return l;

}


int longest_consec_subseq_opt( vector<int> &vec){
    int l=1;
    unordered_set<int> st;
    int n=vec.size();
    for(int i=0;i<n;i++) st.insert(vec[i]);

    for(int i: st){
        if(st.find(i-1)==st.end()){
            int c=1;
            int j=i;
            while(st.find(++j)!=st.end())  c++;

            l=max(l,c);


        }

    }
    return l;

}


int main (){
    
    return 0;
}