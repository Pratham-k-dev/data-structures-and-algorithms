#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define f(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi a(n);
        vi b(n);
        unordered_map<int, int> m;
        f(i, 0, n)
        {
            cin >> a[i];
            m[a[i]] = i;
        }
        f(i, 0, n) cin >> b[i];
        vi ans(n);
        

        multiset<int> st;
        ans[m[1]] = 0;
        
        ll sum = 0;
        // int mini = b[m[1]];
        f(i, 2, k + 2)
        {
            sum += b[m[i - 1]];
            

            st.insert(b[m[i-1]]);
            ans[m[i]] = sum;
        }
        f(i, k + 2, n+1)
        {
            auto it=st.begin();
            if (*(it) < b[m[i-1]])
            {
                sum += (b[m[i-1]] - (*it));
                st.erase(it);
                st.insert(b[m[i-1]]);
            }
            

            ans[m[i]] = sum;
            
        }

        f(i, 0, n) cout << ans[i] << ' ';
        cout << "\n";
    }
    return 0;
}