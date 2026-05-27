//https://leetcode.com/problems/sliding-window-maximum/submissions/2014566773/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n=nums.size();

         vector<int> ans;
        for(int i=0;i<k;i++){
            if(q.empty()) q.push_back(nums[i]);
            else {
                while(q.size() && nums[i]> q.back()){ // monotonic implementation  in decresing fasion
                    q.pop_back();
                }
                q.push_back(nums[i]);
            }
        }

        ans.push_back(q.front());// push front as thats the windows max

       
        for(int i=k;i<n;i++){
            while(q.size() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);
            if(q.front()== nums[i-k]) q.pop_front();// if the front is == the pointer we are leaving behind, then pop it , else no need to worry as it already doesnt exist
            ans.push_back(q.front());

        }

        return ans;
        
    }
};

int main (){
    
    return 0;
}