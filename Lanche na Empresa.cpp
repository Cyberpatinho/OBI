#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000/4
#define endl '\n'

const int N = 250 + 5;

ll g[N][N];
ll dist[N][N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll s, c; cin >>s >>c;

    for(int i = 1; i<=s; i++){
         for(int j = 1; j<=s; j++){
            if(i == j) g[i][j] = g[j][i] = dist[i][j] = dist[j][i] = 0;
            else g[i][j] = g[j][i] = dist[i][j] = dist[j][i] = INF;
         }
    }

    ll a, b, d;
    while(c--){
        cin >>a >>b >>d;
        g[a][b] = g[b][a] = d;
        dist[a][b] = dist[b][a] = d;
    }


    for(int k = 1; k<=s; k++){
        for(int i = 1; i<=s; i++){
            for(int j = 1; j<=s; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll ans = INF, ma;
    for(int i = 1; i<=s; i++){
        ma = 0;
        for(int j = 1; j<=s; j++){
            ma = max(ma, dist[i][j]);
        }
        ans = min(ans, ma);
    }

    cout <<ans <<endl;

    return 0;
}
