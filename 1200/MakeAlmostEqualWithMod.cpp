#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Test powers of 2: k = 2^1, 2^2, ..., 2^60
    for (int p = 1; p <= 60; p++) {
        ll k = 1LL << p;
        unordered_set<ll> remainders;
        for (int i = 0; i < n; i++) {
            remainders.insert(arr[i] % k);
        }
        if (remainders.size() == 2) {
            cout<<k<<"\n";
            return;
        }
    }
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