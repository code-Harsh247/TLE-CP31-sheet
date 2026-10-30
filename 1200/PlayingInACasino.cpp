#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> pii;

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> cols(m,vector<ll>(n));
    vector<vector<ll>> nums(n,vector<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++){
            cols[i][j] = nums[j][i];
        }
    }
    ll res = 0;
    for(auto v : cols){
        sort(v.rbegin(), v.rend());
        for(ll i=0;i<n;i++){
            res += (n-2*i-1)*v[i]; 
        }
    }
    cout<<res<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}