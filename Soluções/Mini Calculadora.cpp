#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int gcd(int a, int b){
    return (!b? a : gcd(b, a%b));
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int c, d, q; cin >>c >>d >>q;

    int g = gcd(d, q);
    d /= g; q /= g;

    if(d > c || q > c) cout <<"IMPOSSIVEL" <<endl;
    else cout <<d <<" " <<q <<endl;

    return 0;
}
