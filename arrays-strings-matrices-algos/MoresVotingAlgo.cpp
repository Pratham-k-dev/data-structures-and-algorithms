#include<bits/stdc++.h>
using namespace std;
// to compute majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el=-1;
        int cnt=0,f=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0) {  // if count cancel outs assume other element as majority 
                el=nums[i];//assume an element as majority
                cnt=1;
                
            }
            else{
                cnt+= (el==nums[i]?1:-1);
                
            }

        }

        //if majority exists the last persisting value of "el" is majority 

        /*
        
        need a majority check for el here

        Leetcode assumes majority exists always


        */
        return el;

        
    }


};

class Solution {// for freq> (n/3) as majority
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1=1e9+1,el2=1e9+1,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                el1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=el1){
                el2=nums[i];
                cnt2=1;
            }
            else if(el1 == nums[i]) cnt1++;
            else if(el2 ==nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) cnt1++;
            if(nums[i]==el2) cnt2++;

        }
        vector<int> ans;
        if(cnt1> (n/3)) ans.push_back(el1);
        if(cnt2> (n/3)) ans.push_back(el2);
        // ans.push_back(el1);
        // ans.push_back(el2);
        return ans;
        
    }
};
int main (){
    
    return 0;
}