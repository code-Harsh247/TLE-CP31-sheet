#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

bool minormax(int k, set<int>&s){
    if(*(s.begin()) == k) return true;
    if(*(s.rbegin()) == k) return true;
    return false;
}

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    set<int> s(nums.begin(), nums.end());
    int l=0, r=n-1;
    while(l<r){
        if(minormax(nums[l],s)){
            s.erase(nums[l]);
            l++;
            continue;
        }
        if(minormax(nums[r],s)){
            s.erase(nums[r]);
            r--;
            continue;
        }
        break;
    }
    if(l<r){
        cout<<(l+1)<<" "<<(r+1)<<"\n";
    }
    else cout<<-1<<"\n";
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