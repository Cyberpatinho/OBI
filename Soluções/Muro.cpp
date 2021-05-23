#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define endl '\n'

const int N = 1e4;

ll dp[N+5];

ll solve(ll n){
    if(n < 0) return 0;
    if(n == 0 || n == 1) return 1;

    ll &r = dp[n];
    if(r != -1) return r;

    return r = (2*solve(n-3)%MOD + 4*solve(n-2)%MOD + solve(n-1)%MOD)%MOD;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >>n;

    memset(dp, -1, sizeof dp);

    cout <<solve(n) <<endl;

    return 0;
}
