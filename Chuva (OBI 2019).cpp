#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

const int N = 5*1e2+5;

int ii[3] = {0, 0, 1};
int jj[3] = {-1, 1, 0};

char g[N+5][N+5];
bool vis[N+5][N+5];

bool check(int n, int m, int ni, int nj){
    return ni >= 0 && ni < n && nj >= 0 && nj < m;
}

void solve(int n, int m, pii start){
    memset(vis, 0, sizeof vis);
    queue<pair<int, int> > qu;
    qu.push(start);

    while(!qu.empty()){
        pii aux = qu.front();
        int i = aux.fi, j = aux.se;
        vis[i][j] = 1;
        qu.pop();

        if(check(n, m, i+1, j)){
            if(g[i+1][j] == '.' && !vis[i+1][j]){
                qu.push({i+1, j});
                g[i+1][j] = 'o';
            }
        }

        if(check(n, m, i, j-1)){
            if(g[i+1][j] == '#' && g[i][j-1] != '#' && !vis[i][j-1]){
                qu.push({i, j-1});
                g[i][j-1] = 'o';
            }
        }

        if(check(n, m, i, j+1)){
            if(g[i+1][j] == '#' && g[i][j+1] != '#' && !vis[i][j+1]){
                qu.push({i, j+1});
                g[i][j+1] = 'o';
            }
        }

    }

}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >>n >>m;
    pii start;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >>g[i][j];
            if(g[i][j] == 'o') start = {i, j};
        }
    }

    solve(n, m, start);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout <<g[i][j];
        }
        cout <<endl;
    }

    return 0;
}
