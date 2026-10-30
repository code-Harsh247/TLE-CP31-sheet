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
    int size = n*(n-1)/2;
    vector<int> b(size);
    for(int i=0;i<size;i++) cin>>b[i];
    sort(b.begin(), b.end());

    vector<int> res;
    int idx = 0;
    for(int step=n-1;step>0;step--){
        res.push_back(b[idx]);
        idx+=step;
    }
    res.push_back(b.back());
    for(auto a : res){
        cout<<a<<" ";
    }
    cout<<"\n";

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