#include <bits/stdc++.h>
using namespace std;
int f_better(vector<int> &vec, int k)//nlogn for ordered map //O(n*1)-->unordered but worst case O(n^2)
{
    map<int, int> m1;
    int max_len = 0;
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];

        if (sum == k)
        {
            max_len = max(max_len, i + 1);
        }
        if (m1.find(sum - k) != m1.end())
        {
            max_len = max(max_len, i - m1[sum - k]);
        }
        if (m1.find(sum) == m1.end())
        {
            m1[sum] = i;
        }
    }

    return max_len;
}
int f_opt(vector<int> &vec, int k) //for 0's and +ves only
{
    int i = 0, j = 0;
    int sum=vec[0];
    int max_len = 0;
    while (j < vec.size())
    {
        
        while (i<=j && sum > k)
        {
            sum -= vec[i];
            i++;
        }
        if (sum == k)
        {
            max_len = max(max_len, j - i + 1);
        }
        
        j++;
        if(j<vec.size()){sum+=vec[j];}
        
    }
    return max_len;
}

int main()
{

    vector<int> vec;
    vec = {1, 2, 3, 1, 1, 1, 4, 2, 3};
    // vec={2,1,0,0,0,3};
    cout << f_opt(vec, 3);

    return 0;
}