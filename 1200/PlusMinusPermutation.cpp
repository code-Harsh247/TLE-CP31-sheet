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
    ll n,x,y;
    cin>>n>>x>>y;

    ll g = gcd(x,y);
    ll lcm = (x/g)*y;

    ll cx = n/x;
    ll cy = n/y;
    ll cxy = n/lcm;

    ll cA = cx - cxy;
    ll cB = cy - cxy;

    ll sumA = cA*(2*n - cA + 1)/2;
    ll sumB = cB*(1+cB)/2;

    cout<<sumA-sumB<<"\n";

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