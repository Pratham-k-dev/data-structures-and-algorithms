//https://leetcode.com/problems/jump-game-ii/?envType=problem-list-v2&envId=greedy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) { //greedy
        int n = nums.size();
        int i = 0, j = 0, c = 0;  // i = current index within level
                                  // j = farthest we can reach in current jump
                                  // c = number of jumps taken

        // Continue until we've reached or passed the last index
        while (j < n - 1) {
            int m = 0;  // m = max reach in the next jump

            // Explore all indices within the current jump range [i, j]
            while (i <= j) {
                m = max(m, i + nums[i]);  // update farthest reach
                i++;
            }

            // Move to the next "level"
            i = j + 1;
            j = m;  // update boundary for next level
            c++;    // increment jump count
        }

        return c;  // total jumps needed to reach the end
    }
};


int main (){
    
    return 0;
}