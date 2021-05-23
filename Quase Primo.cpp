#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, k) for(int i = j; i<=k; i++)
#define endl '\n'

ll ans, n, k, x;
vector<ll> primes;

void solve(ll pos, ll prod, ll qty){
    if(prod > n) return;
    if(pos > k){
        if(prod != 1){
            if(qty%2) ans -= n/prod;
            else ans += n/prod;
            return;
        }
        else return;
    }

    solve(pos+1, prod, qty);
    solve(pos+1, prod*primes[pos-1], qty+1);
    return;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >>n >>k;
    ans = n;
    rep(i, 1, k){
        cin >>x; primes.push_back(x);
    }

    solve(1, 1, 0);
    cout <<ans <<endl;
    return 0;
}
