#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

const int N = 505;

int ii[4] = {1, -1, 0, 0};
int jj[4] = {0, 0, -1, 1};

char g[N][N];
int A = 0, B = 0;

bool check(int i, int j, int n, int m){
    return (i <= n && i >= 1 && j <= m && j >= 1);
}

pii DFS(int i, int j, int n, int m){

    pii ans = make_pair(0, 0);
    if(g[i][j] == 'k') ans.fi++;
    if(g[i][j] == 'v') ans.se++;

    g[i][j] = '*';

    for(int k = 0; k<4; k++){
        int movi = i + ii[k];
        int movj = j + jj[k];
        if(check(movi, movj, n, m) && g[movi][movj] != '*' && g[movi][movj] != '#'){
            pii aux = DFS(movi, movj, n, m);
            ans.fi += aux.fi;
            ans.se += aux.se;
        }
    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >>n >>m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >>g[i][j];
            if(g[i][j] == 'k') A++;
            if(g[i][j] == 'v') B++;
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(g[i][j] != '*' && g[i][j] != '#'){
                pii aux = DFS(i, j, n, m);
                if(aux.fi > aux.se) B -= aux.se;
                else A -= aux.fi;
            }
        }
    }

    cout <<A <<" " <<B <<endl;

    return 0;
}
