#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define endl '\n'

ll dist(ll x, ll y){
    return x*x + y*y;
}

const int N = 1e5;

map<ll, ll> compress;
ll seg[4*N+5];
ll cmp[N+5];
pll arr[N+5];


void update(ll node, ll l, ll r, ll v, ll pos){

    if(pos == l && pos == r){
        seg[node] += v;
        return;
    }
    else if(pos < l || pos > r){
        return;
    }

    ll mid = (l+r)/2;
    update(2*node, l, mid, v, pos);
    update(2*node+1, mid+1, r, v, pos);
    seg[node] = seg[2*node] + seg[2*node+1];
}

ll query(ll node, ll l, ll r, ll a, ll b){

    if(l >= a && r <= b){
        return seg[node];
    }
    else if(l > b || r < a){
        return 0;
    }
    ll mid = (l+r)/2;
    return query(2*node, l, mid, a, b) + query(2*node+1, mid+1, r, a, b);
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x, y, cnt = 1, d, q; cin >>n;
    q = n;
    while(q--){
        cin >>x >>y;
        d = dist(x, y);
        cmp[cnt] = d; arr[cnt] = {cnt, d};
        cnt++;
    }

    cnt = 1;
    sort(cmp+1, cmp+n+1);
    for(int i = 1; i<=n; i++){
        if(!compress.count(cmp[i])){
            compress[cmp[i]] = cnt++;
        }
    }

    ll ans = 0;
    for(int i = 1; i<=n; i++){
        ans += query(1, 1, n, 1, compress[arr[i].se]);
        update(1, 1, n, 1, compress[arr[i].se]);
    }

    cout <<ans <<endl;
    return 0;
}
