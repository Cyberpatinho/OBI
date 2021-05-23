#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

int ii[4] = {0, 0, 1, -1};
int jj[4] = {1, -1, 0, 0};

char mat[105][105];

pii BFS(pii start){

    pii ans;
    queue<pii> qu;
    qu.push(start);

    while(!qu.empty()){
        pii aux = qu.front();
        mat[aux.fi][aux.se] = '.';
        qu.pop();

        bool end = 1;
        int movi, movj;
        for(int i = 0; i<4; i++){
            movi = aux.fi + ii[i];
            movj = aux.se + jj[i];
            if(mat[movi][movj] == 'H'){
                qu.push({movi, movj}); end = 0;
            }
        }

        if(end) ans = {aux.fi, aux.se};

    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);

    pii start;
    int l, c; cin >>l >>c;
    for(int i = 1; i<=l; i++){
        for(int j = 1; j<=c; j++){
            cin >>mat[i][j];
            if(mat[i][j] == 'o') start = {i, j};
        }
    }

    pii ans = BFS(start);

    cout <<ans.fi <<" " <<ans.se <<endl;
    return 0;
}
