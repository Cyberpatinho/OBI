#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e3+5;

ll mat[N][N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll l, c, n, m, x; cin >>l >>c >>n >>m;

    for(int i = 1; i<=l; i++){
        for(int j = 1; j<=c; j++){
            cin >>x;
            mat[i][j] = x + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }

    ll ans = 0;
    for(int i = n; i<=l; i++){
        for(int j = m; j<=c; j++){
            ll aux = mat[i][j] - mat[i-n][j] - mat[i][j-m] + mat[i-n][j-m];
            ans = max(ans, aux);
        }
    }

    cout <<ans <<endl;

    return 0;
}
