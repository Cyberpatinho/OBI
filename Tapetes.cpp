#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll l, n; cin >>l >>n;

    vector<ll> v;

    ll amnt = 1, ans = 0;
    while(amnt < n && l > 1){
        amnt++; l--; ans++;
    }

    cout <<ans + l*l <<endl;

    return 0;
}
