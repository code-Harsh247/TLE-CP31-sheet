#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> last_pos(k + 1, 0);
    vector<int> max1(k + 1, 0);
    vector<int> max2(k + 1, 0);

    // Helper lambda to process a gap
    auto update_gaps = [&](int color, int pos) {
        int gap = pos - last_pos[color] - 1;
        if (gap > max1[color]) {
            max2[color] = max1[color];
            max1[color] = gap;
        } else if (gap > max2[color]) {
            max2[color] = gap;
        }
        last_pos[color] = pos;
    };

    // 1-based indexing for planks
    for (int i = 0; i < n; i++) {
        update_gaps(c[i], i + 1);
    }

    // Don't forget the final gap from the last plank to the house (n + 1)
    for (int i = 1; i <= k; i++) {
        update_gaps(i, n + 1);
    }

    int ans = 1e9; // Infinity
    
    // Find the minimum possible maximum step across all colors
    for (int i = 1; i <= k; i++) {
        // If we split the largest gap in half, the new largest gap is the max of:
        // 1. Half of the largest gap
        // 2. The second largest gap
        int current_max_step = max(max1[i] / 2, max2[i]);
        ans = min(ans, current_max_step);
    }

    cout << ans << "\n";
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