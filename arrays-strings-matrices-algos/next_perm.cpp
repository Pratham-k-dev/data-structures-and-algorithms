#include<bits/stdc++.h>
using namespace std;

int * next_perm(vector <int> &vec){//O(n) 
 int n=vec.size();
    int i=n-1;
     // Step 1: Find the largest index i such that vec[i-1] < vec[i]
    // (this identifies the pivot point where the next permutation changes)
    while(i>=1 && vec[i-1]>=vec[i]) i--; 



    if(i){
        // Step 2: Find the smallest number greater than vec[i-1]
        for(int j=n-1;j>=i;j--) {
            if(vec[j]>vec[i-1]) {
                swap(vec[i-1],vec[j]); 
                break;
            }

        }
         // Step 3: Reverse the suffix starting at i
        reverse(vec.begin()+i,vec.end());
        return &vec[0];
    }
    else return nullptr; // or reverse(vec.begin(),vec.end());
}

int fact(int n) {
    if (n==0) return 1;
    return n*fact(n-1);
}

int main (){
    vector<int> vec({1,1,2,3});
    sort(vec.begin(),vec.end());

    int n=vec.size();


int i=0;
do{
    for(int j=0;j<n;j++) cout<<vec[j]<<' ';
    cout<<endl;
     
    i++;
}
while(next_perm(vec));
    return 0;
}