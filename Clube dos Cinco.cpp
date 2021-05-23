#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0);
    int n; cin >>n;
    int a, b, c, d, e, f, g;
    cin >>a >>b >>c >>d >>e >>f >>g;
    if(n - a - b - c + d + e + f - g) cout <<"S" <<endl;
    else cout <<"N" <<endl;
    return 0;
}
