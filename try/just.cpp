#include<bits/stdc++.h>
using namespace std;


   bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            if(abs(nums[i])%n==0) continue;
            int j=i;
            bool f=(nums[i]>0);
            unordered_set<int> s;
            while(true){
                if(s.count(j)) break;
                if((f!=(nums[j]>0))) break;
                s.insert(j);
                sum+=nums[j];
                j=(n+j+nums[j])%n;
                
            if(abs(sum)%n==0) return true;
            }
        }
        return false;
    }


int main (){
   vector<int> a(3);
   a={-2,-3,-9};
   cout<<circularArrayLoop(a);
    return 0;
}
