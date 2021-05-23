#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

const int N = 505;

char g[N][N];
char g2[N][N];
bool vis[N][N];

map<char, pii> m;

bool DFS(int i, int j, int n){

    bool bad = 0;
    vis[i][j] = 1;
    pii mov = m[g[i][j]];
    int movi = i + mov.fi;
    int movj = j + mov.se;

    if(movi <= 0 || movj <= 0 || movi > n || movj > n) bad = 1;
    else if(!vis[movi][movj]) bad = DFS(movi, movj, n);
    else if(g2[movi][movj] == 'x') bad = 1;

    if(bad) g2[i][j] = 'x';

    return bad;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    m['A'] = {-1, 0};
    m['V'] = {1, 0};
    m['<'] = {0, -1};
    m['>'] = {0, 1};

    int n; cin >>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >>g[i][j];
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(!vis[i][j]){
                DFS(i, j, n);
            }
        }
    }

    int ans = n*n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            ans -= (g2[i][j] == 'x');
        }
    }

    cout <<ans <<endl;

    return 0;
}
