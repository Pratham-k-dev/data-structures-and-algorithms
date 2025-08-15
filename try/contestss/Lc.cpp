#include<bits/stdc++.h>
using namespace std;
int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> hash;
        
        int j=0;
        int ans=1;
        for(int i=0;i<n;i++){
            hash[fruits[i]]++;
            // st.insert(fruits[i]);
            while(hash.size()>2){
             hash[fruits[j]]--;
            if(!hash[fruits[j]]){ hash.erase(fruits[j]);
            //st.erase(fruits[j]);
            }
            j++;
                
            }
            ans=max(ans,i-j+1);
            
            
        }

        return ans;
    }

int main (){
    vector<int> a={5,9,0,9,6,9,6,9,9,9};
    cout<<totalFruit(a);
    return 0;
}