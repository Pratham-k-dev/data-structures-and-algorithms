//https://leetcode.com/problems/contiguous-array/description/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        // HashMap to store the first index where a particular count occurred
        unordered_map<int, int> m;

        int ans = 0;

        // Initialize with count = 0 at index -1 (important base case)
        m.insert({0, -1});
        
        int c = 0;  // Running count: +1 for 1, -1 for 0

        for (int i = 0; i < n; i++) {
            // Increment or decrement count depending on value
            c += (nums[i] == 1) ? 1 : -1;

            // If this count has been seen before, it means subarray between previous index and current index has equal 0s and 1s
            if (m.find(c) != m.end()) {
                ans = max(ans, i - m[c]);  // Update max length
            } else {
                // Store the first occurrence of this count
                m[c] = i;
            }
        }

        return ans;
    }
};

int main (){
    
    return 0;
}