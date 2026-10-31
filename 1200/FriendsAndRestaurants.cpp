#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    // Compute difference d[i] = y[i] - x[i]
    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = y[i] - x[i];
    }

    sort(d.begin(), d.end());

    int l = 0, r = n - 1;
    int groups = 0;

    while (l < r) {
        if (d[l] + d[r] >= 0) {
            // Valid pair found
            groups++;
            l++;
            r--;
        } else {
            // d[l] is too negative to pair with d[r]
            l++;
        }
    }

    cout << groups << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}