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
    int n,m;
    cin>>n>>m;
    vector<int> infected(m);
    for(int i=0;i<m;i++) cin>>infected[i];
    vector<int> gaps;
    sort(infected.begin(), infected.end());
    for(int i=0;i<m-1;i++){
        int g = infected[i+1] - infected[i]-1;
        gaps.push_back(g);
    }
    gaps.push_back(n-infected[m-1]+infected[0]-1);
    sort(gaps.rbegin(), gaps.rend());
    int day = 0;
    int saved = 0;
    for(auto g : gaps){
        int seg = g - 2*day;
        if(seg<0) break;
        if(seg == 1 || seg == 2){
            saved++;
            day++;
        }
        else if(seg>2){
            saved += seg-1;
            day+=2;
        }
    }
    cout<<n-saved<<"\n";
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