#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    // Base case for single element array
    if(n == 1) {
        cout << 1 << "\n";
        return;
    }

    // Step 1: Remove consecutive duplicates
    vector<int> b;
    b.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] != b.back()){
            b.push_back(a[i]);
        }
    }

    // If all elements were identical, the size is 1
    if(b.size() == 1){
        cout << 1 << "\n";
        return;
    }

    // Step 2: Count the endpoints and the local extrema (turning points)
    int ans = 2; // We always keep the first and last elements of the compressed array
    
    for(int i = 1; i < (int)b.size() - 1; i++){
        // If it's a local peak (strictly greater than neighbors) 
        // or a local valley (strictly less than neighbors)
        if((b[i] > b[i-1] && b[i] > b[i+1]) || (b[i] < b[i-1] && b[i] < b[i+1])){
            ans++;
        }
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}