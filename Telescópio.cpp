#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define endl '\n'

const int N = 4*1e7;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll x, n; cin >>x >>n;

    ll ans = 0;
    for(int i = 0; i<n; i++){
        int y; cin >>y;
        ans += (x*y >= N);
    }

    cout <<ans <<endl;

    return 0;
}
