#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e6+5;

ll a[N];
map<ll, ll> m;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, d, sum = 0; cin >>n >>d;
    for(int i = 0; i<n; i++){
        cin >>a[i]; sum += a[i];
    }

    m[0]++;
    ll ans = 0, pref = 0;
    for(int i = 0; i<n; i++){
        pref += a[i];
        if(m[pref-d] > 0){
            //cout <<i <<" " <<pref <<" " <<pref-d<<endl;
        }
        ans += m[pref-d];
        m[pref]++;
    }

    m.clear();
    pref = 0;
    for(int i = 0; i<n-1; i++){
        pref += a[i];
        m[pref]++;
        if(m[d-sum+pref] > 0){
            //cout <<i <<" " <<pref <<" " <<d-sum+pref <<endl;
        }
        ans += m[d-sum+pref];
    }

    cout <<ans <<endl;

    return 0;
}
