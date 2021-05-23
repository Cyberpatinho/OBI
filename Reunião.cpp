#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define endl '\n'

int g[105][105];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >>n >>m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }

    int a, b, w;
    for(int i = 0; i<m; i++){
        cin >>a >>b >>w;
        g[a][b] = g[b][a] = w;
    }

    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    int ans = INF, ma;
    for(int i = 0; i<n ; i++){
        ma = 0;
        for(int j = 0; j<n; j++){
            ma = max(ma, g[i][j]);
        }
        ans = min(ans, ma);
    }

    cout <<ans <<endl;

    return 0;
}
