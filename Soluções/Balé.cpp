#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e5+5;

ll a[N];
ll seg[4*N+1];

void update(ll node, ll l, ll r, ll pos){
    if(l >= pos && r <= pos){
        seg[node] = 1;
        return;
    }
    else if(l > pos || r < pos) return;
    ll mid = (l+r)/2;
    update(2*node, l, mid, pos);
    update(2*node+1, mid+1, r, pos);
    seg[node] = seg[2*node] + seg[2*node+1];
    return;
}

ll query(ll node, ll l, ll r, ll a, ll b){
    if(l >= a && r <= b) return seg[node];
    else if(l > b || r < a) return 0;
    ll mid = (l+r)/2;
    return query(2*node, l, mid, a, b) + query(2*node+1, mid+1, r, a, b);
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >>n;
    for(int i = 0; i<n; i++) cin >>a[n-i-1];

    ll ans = 0;
    for(int i = 0; i<n; i++){
        update(1, 1, n, a[i]);
        ans += query(1, 1, n, 1, a[i]-1);
    }

    cout <<ans <<endl;

    return 0;
}
