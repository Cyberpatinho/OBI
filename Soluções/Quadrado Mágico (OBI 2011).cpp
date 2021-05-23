#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

ll has[1000050];
ll a[1050][1050];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, sum = 0; cin >>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >>a[i][j];
            has[a[i][j]]++;
            if(!i) sum += a[i][j];
        }
    }

    bool ok = 1;
    for(int i = 0; i<n; i++){
        int aux = 0;
        for(int j = 0; j<n; j++){
            aux += a[i][j];
        }
        ok &= (sum == aux);
    }

    for(int i = 0; i<n; i++){
        int aux = 0;
        for(int j = 0; j<n; j++){
            aux += a[j][i];
        }
        ok &= (sum == aux);
    }

    ll aux = 0;
    for(int i = 0; i<n; i++){
        aux += a[i][i];
    }
    ok &= (sum == aux);

    for(int i = 1; i<=n*n; i++){
        ok &= (has[i] == 1);
    }

    cout <<(ok? sum : 0) <<endl;

    return 0;
}
