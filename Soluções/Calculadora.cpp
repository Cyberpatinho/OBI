#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

vector<ll> a;
ll b[10];

ll pow(ll a, ll b){
    ll ans = 1;
    while(b--) ans *= a;
    return ans;
}

int main(){

    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >>n;
    for(int i = 0; i<n; i++){
        char x, y; cin >>x >>y;
        if(y == '*') a.push_back(x-'0');
        else b[x-'0']++;
    }

    a.push_back(1);

    ll ans = 1;
    for(int i = 0; i<a.size(); i++){
        ans *= a[i];
        for(int j = 1; j<=9; j++){
            if(b[j] && ans%j == 0){
                ans /= j; b[j]--;
            }
        }
    }

    cout <<ans <<endl;

    return 0;
}
