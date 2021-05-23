#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define endl '\n'

const int N = 1e5+5;

ld radius(ld x, ld y){
    return sqrt(x*x + y*y);
}

ld a[N];
ll BS(ll lo, ll hi, ll n, ld rad){

    ll idx = -1;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(a[mid] >= rad){
            idx = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    if(idx == -1) return 0;
    else return n - idx + 1;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q; cin >>n >>q;
    for(int i = 0; i<n; i++) cin >>a[i];

    ld x, y;
    ll ans = 0, t = 0;
    while(q--){
        cin >>x >>y;
        if(radius(x, y) <= a[0]) ans += n;
        else ans += BS(0, n-1, n-1, radius(x, y));
    }

    cout <<ans <<endl;

    return 0;
}
