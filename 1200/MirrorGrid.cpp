#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

pii rotate(int i,int j,int n){
    return {n-1-j,i};
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            grid[i][j] = c-'0';
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vector<int> temp;
            pii r1 = rotate(i,j,n);
            pii r2 = rotate(r1.first,r1.second,n);
            pii r3 = rotate(r2.first,r2.second,n);
            temp.push_back(grid[i][j]);
            temp.push_back(grid[r1.first][r1.second]);
            temp.push_back(grid[r2.first][r2.second]);
            temp.push_back(grid[r3.first][r3.second]);
            int t1=0,t2=0;
            for(int k=0;k<4;k++){
                if(temp[k]==0) t1++;
                else t2++;
            }
            count += min(t1,t2);
        }
    }
    cout<<count/4<<"\n";
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