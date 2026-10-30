#include <bits/stdc++.h>
using namespace std;
 
#define INF 1000000000
#define MOD 1000000007
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pll> a(n), b(n), c(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second = i;
        }
        for(int i=0;i<n;i++){
            cin>>b[i].first;
            b[i].second = i;
        }
        for(int i=0;i<n;i++){
            cin>>c[i].first;
            c[i].second = i;
        }
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        sort(c.rbegin(),c.rend());
        ll res = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(a[i].second != b[j].second &&
                       a[i].second != c[k].second &&
                       b[j].second != c[k].second){
                        ll currSum = a[i].first + b[j].first + c[k].first;
                        res = max(currSum, res);
                       }
                }
            }
        }
        cout<<res<<"\n";
    }
 
    return 0;
}