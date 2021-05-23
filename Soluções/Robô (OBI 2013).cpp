#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e3+5;

int ii[4] = {1, -1, 0, 0};
int jj[4] = {0, 0, 1, -1};

int g[N][N];
int vis[N][N];
void solve(int x, int y, int n, int m){
    bool dest = 1;
    g[x][y] = 0;
    for(int i = 0; i<4; i++){
        int movi = x + ii[i];
        int movj = y + jj[i];
        if(movi > 0 && movj > 0 && movi <= n && movj <= m && g[movi][movj] == 1){
            solve(movi, movj, n, m);
            dest = 0;
        }
    }

    if(dest) cout <<x <<" " <<y <<endl;

    return;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >>n >>m;
    int x, y; cin >>x >>y;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >>g[i][j];
        }
    }

    solve(x, y, n, m);

    return 0;
}
