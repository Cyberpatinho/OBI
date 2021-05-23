#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0);

    ll n, m; cin >>n >>m;

    ll ans = 0;
    for(int i = 1; i <= m; i++){
        ll aux = n-i;
        if(2*m >= aux){
            ll mi = max(1LL, aux-m);
            ll ma = min(m, aux-1);
            ans += (ma - mi + 1);
        }
    }

    cout <<ans <<endl;
    return 0;
}
