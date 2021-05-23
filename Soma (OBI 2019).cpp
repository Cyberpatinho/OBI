#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e5;

ll arr[5*N+5];
map<ll, ll> bag;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k, x; cin >>n >>k;
    for(int i = 1; i<=n; i++){
        cin >>x; arr[i] = arr[i-1] + x;
    }

    ll ans = 0;
    for(int i = 0; i<=n; i++){
        ans += bag[arr[i] - k];
        bag[arr[i]]++;
    }

    cout <<ans <<endl;

    return 0;
}
