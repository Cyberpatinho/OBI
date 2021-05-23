#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

set<pair<int, int> > s;
void BS(ll lo, ll hi, ll k, ll x){
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        ll aux = k*mid + (k-1)*(mid-1);
        if(aux == x){
            s.insert({min(k, mid), max(k, mid)});
            return;
        }
        else if(aux > x) hi = mid-1;
        else lo = mid+1;
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll x; cin >>x;

    for(int i = 2; i*i<=x; i++){
        BS(2, 2000000000, i, x);
    }

    cout <<s.size() <<endl;

    return 0;
}
