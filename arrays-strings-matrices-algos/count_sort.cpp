#include<bits/stdc++.h>
using namespace std;

void Count_sort(vector<int> &vec){
    int n=vec.size();
    int max=vec[0];
    for(int i=0;i<n;i++){
        if(vec[i]>max){
            max=vec[i];
        }
    }
    vector<int> temp(max+1,0);
    for(int i=0;i<n;i++){
        temp[vec[i]]++;
    }
    
    int i=0;
    for(int j=0;j<=max;j++){
    while(temp[j]!=0){
        vec[i]=j;
        i++;
        temp[j]--;
       

    }
    }

}

int main (){
    vector<int> vec={3,1,9,7,1,2,4};
    
    Count_sort(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }

    
    return 0;
}