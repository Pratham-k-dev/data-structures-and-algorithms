#include<bits/stdc++.h>
using namespace std;

 int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
        int dif=20001;
        int r=10001;
        int i=0;
        int f=0;
        while(i<n-2){

            int j=i+1,k=n-1;

            while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum == target ) return target;
            if(!f){

                f=1;
                dif=abs(sum-target);
                r=sum;
            }
            else if(abs(target-sum)<dif){

            dif=abs(target-sum);
            r=sum;
            } 
                // r=sum;
        //   dif = abs(sum -target);


           

              
           
           if(sum<target){
                j++;
               
            }
            else{
               k--;
            }
            }
            i++;
           
                

            
        }

        return r;
    }

int main (){
    vector<int> vec={10,20,30,40,50,60,70,80,90};
    cout<<threeSumClosest(vec,1);
    return 0;
}