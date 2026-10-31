#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    int total_sum = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }
    if (total_sum < s) {
        cout << -1 << "\n";
        return;
    }
    if (total_sum == s) {
        cout << 0 << "\n";
        return;
    }

    int max_len = -1;
    int current_sum = 0;
    int left = 0;
    for(int right = 0; right < n; right++){
        current_sum += a[right];
        while(current_sum > s && left <= right){
            current_sum -= a[left];
            left++;
        }
        if(current_sum == s){
            max_len = max(max_len, right - left + 1);
        }
    }
    cout << n - max_len << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}