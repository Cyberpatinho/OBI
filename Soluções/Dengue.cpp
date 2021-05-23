#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define endl '\n'

const int N = 1e2;

int t;
int g[N+5][N+5];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a, b;
    while(cin >>n){

        if(!n) break;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(i == j) g[i][j] = 0;
                else g[i][j] = INF;
            }
        }

        for(int i = 1; i<n; i++){
            cin >>a >>b;
            g[a][b] = g[b][a] = 1;
        }

        for(int k = 1; k<=n; k++){
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=n; j++){
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        int ans, mi = INF;
        for(int i = 1; i<=n; i++){
            int ma = 0;
            for(int j = 1; j<=n; j++){
                if(g[i][j] != INF && g[i][j] > ma) ma = g[i][j];
            }
            if(ma < mi){
                mi = ma;
                ans = i;
            }
        }

        cout <<"Teste " <<++t <<endl <<ans <<endl <<endl;
    }

    return 0;
}
