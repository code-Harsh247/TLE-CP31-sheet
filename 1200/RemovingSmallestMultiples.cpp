#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> removed(n,0);
    ll total = 0;
    for(int k=1;k<=n;k++){
        for(int m=k;m<=n;m+=k){
            if(s[m-1] == '1') break;
            else if(!removed[m-1]){
                removed[m-1] = 1;
                total += k;
            }
        }
    }
    cout<<total<<"\n";
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