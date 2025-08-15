#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sum3_better(vector<int> &vec, int k)
{
    set<vector<int>> st;

    int n = vec.size();
    for (int l = 0; l < n - 1; l++)
    {
        set<int> hash;
        for (int r = l + 1; r < n; r++)
        {
            int third = k - vec[l] - vec[r];
            if (hash.find(third) != hash.end())
            {
                vector<int> temp = {vec[l], vec[r], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hash.insert(vec[r]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
vector<vector<int>> sum3_opt(vector<int> nums, int r)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0;
    while (i < n - 2)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == r)
            {
                vector<int> temp;
                temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                j++;
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                k--;
                while (k > j && nums[k] == nums[k + 1])
                    k--;
            }
            else if (sum < r)
            {
                j++;
                // while(j<k &&  vec[j]==vec[j-1]){
                //     j++;
                // }
            }
            else
            {
                k--;
                // while(k>j && vec[k]==vec[k-1]) k--;
            }
        }
        i++;
        while (i < n - 2 && nums[i] == nums[i - 1])
        {
            i++;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4, -1, 0, 2};
    vector<vector<int>> ans = sum3_better(nums, 1);
    // for(int i=0;i<ans.size();i++){

    //         cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;

    // }
    sum3_opt(nums, 0);

    return 0;
}