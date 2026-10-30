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
    vector<int> m(n);
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    sort(m.begin(), m.end());
    vector<int> last;
    last.push_back(m[0]);
    int count = 1;
    for(int i=1;i<n;i++){
        auto ub = upper_bound(last.begin(), last.end(),m[i]-1);
        --ub;
        if((*ub)+1 == m[i]){
            *ub = m[i];
        }
        else{
            last.push_back(m[i]);
            count++;
        }
    }
    cout<<count<<"\n";
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