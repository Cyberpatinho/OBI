#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int ii[4] = {1, -1, 0, 0};
int jj[4] = {0, 0, 1, -1};

int g[105][105], vis[105][105];

int DFS(int x, int y){
    int ans = 0;
    if(!vis[x][y]){
        vis[x][y] = 1;
        ans++;
    }

    for(int i = 0; i<4; i++){
        int movx = x + ii[i];
        int movy = y + jj[i];
        if(!vis[movx][movy] && g[movx][movy] >= g[x][y]){
            ans += DFS(movx, movy);
        }
    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    int x, y; cin >>x >>y;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >>g[i][j];
        }
    }

    int ans = DFS(x, y);

    cout <<ans <<endl;

    return 0;
}
