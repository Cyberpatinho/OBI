#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 105;

int g[N][N];
int ans[N][N][N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, u, v, w; cin >>n >>m;
    for(int i = 0; i<m; i++){
        cin >>u >>v >>w;
        g[u][v] = w;
        g[v][u] = w;
    }

    int a, b, c, ma = -1;
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            for(int k = j+1; k<=n; k++){
                ans[i][j][k] = g[i][j] + g[j][k] + g[k][i];
                if(ans[i][j][k] >= ma){
                    ma = ans[i][j][k];
                    a = i, b = j, c = k;
                }
            }
        }
    }

    cout <<a <<" " <<b <<" " <<c <<endl;

    return 0;
}
