//https://leetcode.com/problems/fruit-into-baskets/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& nums) {//O(n+n) solution
        int n= nums.size();
       unordered_map<int,int> mp;
       

        

        int i = 0, j = 0, ans = 0;
        int t1 = -1, t2 = -1;

        while (j < n) {
            mp[nums[j]]++;
            if(mp.size()>2){
                while(i<j && mp.size()>2){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);

                    i++;
                }
            }

            ans=max(ans,j-i+1);
                j++;
           
        }
        return ans;
    }

    int totalFruit(vector<int>& nums) { //O(n) solution
        int n= nums.size();
       unordered_map<int,int> mp;
       

        

        int i = 0, j = 0, ans = 0;
        int t1 = -1, t2 = -1;

        while (j < n) {
            mp[nums[j]]++;
            if(mp.size()>2){
                
                mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);

                    i++;
                    j++; // no shrinking the length only looking for better length


            }
            else{
            ans=max(ans,j-i+1);
                j++;

            }

           
        }
        return ans;
    }
};

int main (){
    
    return 0;
}