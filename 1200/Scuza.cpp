#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> steps(n);
    vector<ll> pref_sum(n);
    vector<ll> pref_max(n);

    for (int i = 0; i < n; i++) {
        cin >> steps[i];
        pref_sum[i] = steps[i] + (i > 0 ? pref_sum[i - 1] : 0LL);
        pref_max[i] = (i > 0 ? max(pref_max[i - 1], steps[i]) : steps[i]);
    }

    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;

        // upper_bound returns an iterator to the first element > k
        int idx = upper_bound(pref_max.begin(), pref_max.end(), k) - pref_max.begin();

        if (idx == 0) {
            cout << 0 << " ";
        } else {
            cout << pref_sum[idx - 1] << " ";
        }
    }
    cout << "\n";
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