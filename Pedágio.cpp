#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define endl '\n'

const int N = 50;

int t;
int g[N+5][N+5];

int main(){

    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, e, l, p;
    while(cin >>n >>e >>l >>p){

        if(!n && !e && !l && !p) break;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(i == j) g[i][j] = 0;
                else g[i][j] = INF;
            }
        }

        int a, b;
        for(int i = 1; i<=e; i++){
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

        cout <<"Teste " <<++t <<endl;
        for(int i = 1; i<=n; i++){
            if(i != l && g[l][i] <= p) cout <<i <<" ";
        }

        cout <<endl <<endl;

    }

    return 0;
}
