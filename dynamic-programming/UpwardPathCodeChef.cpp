// https://www.codechef.com/problems/UPPATH

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // r1[i] will store the value at (1, i) if a non-decreasing path exists to it.
    // We want this value to be as small as possible to keep options open.
    vector<ll> r1(N, -1);
    
    ll curr = min(a[0], b[0]);
    r1[0] = curr;

    for (int i = 1; i < N; ++i) {
        ll v1 = min(a[i], b[i]);
        ll v2 = max(a[i], b[i]);
        
        if (v1 >= r1[i-1]) {
            r1[i] = v1;
        } else if (v2 >= r1[i-1]) {
            r1[i] = v2;
        } else {
            // Path in Row 1 is broken beyond this point
            break;
        }
    }

    // r2[i] will store the value at (2, i) if a non-decreasing path exists from it to (2, N).
    // We want this value to be as large as possible.
    vector<ll> r2(N, -1);
    curr = max(a[N-1], b[N-1]);
    r2[N-1] = curr;

    for (int i = N - 2; i >= 0; --i) {
        ll v1 = max(a[i], b[i]);
        ll v2 = min(a[i], b[i]);

        if (v1 <= r2[i+1]) {
            r2[i] = v1;
        } else if (v2 <= r2[i+1]) {
            r2[i] = v2;
        } else {
            // Path in Row 2 is broken before this point
            break;
        }
    }

    // Check if there's any column k where we can transition from Row 1 to Row 2
    for (int k = 0; k < N; ++k) {
        if (r1[k] != -1 && r2[k] != -1) {
            // After picking the best values for the paths, 
            // check if the bridge (1,k) -> (2,k) is valid.
            // Note: The value at (2,k) for the path to (2,N) must not be the 
            // same physical element used for (1,k) if they were swapped.
            
            ll v1 = r1[k];
            // The value at (2,k) must be the OTHER value in that column
            ll other = (a[k] + b[k]) - v1;
            
            if (v1 <= other && other <= (k == N-1 ? 2e18 : r2[k])) {
                // Special case: if we transition at k, the value at (2,k) 
                // just needs to be >= r1[k] and <= the path leading to (2,N)
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}