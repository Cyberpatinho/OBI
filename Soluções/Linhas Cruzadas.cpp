#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 6*1e4+5;

ll BIT[N], a[N];

void update(ll x, ll v){
    while(x <= N){
        BIT[x] += v;
        x += (x&-x);
    }
    return;
}

ll get(ll x){
    ll ret = 0;
    while(x){
        ret += BIT[x];
        x -= (x&-x);
    }
    return ret;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >>n;
    for(int i = 0; i<n; i++) cin >>a[i];

    ll ans = 0;
    for(int i = 0; i<n; i++){
        ans += get(n) - get(a[i]);
        update(a[i], 1);
    }

    cout <<ans <<endl;

    return 0;
}
