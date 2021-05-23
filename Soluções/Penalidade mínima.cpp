#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

const int N = 1e3+5;

int g[N][N];
pii dist[N][N];

int calc(int x, int n){
    int ret = 0;
    while(x%n == 0){
        x /= n; ret++;
    }
    return ret;
}

void Dijkstra(int n, int x, int y){

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dist[i][j].fi = -1;
        }
    }

    set<pair<pii, pii > > qu;
    qu.insert({{calc(g[1][1], x), calc(g[1][1], y)}, {1, 1}});
    dist[1][1] = mp(calc(g[1][1], x), calc(g[1][1], y));



    int a, b, posi, posj;
    pair<pii, pii> aux;
    while(!qu.empty()){
        aux = *qu.begin();
        qu.erase(aux);

        a = aux.fi.fi;
        b = aux.fi.se;
        posi = aux.se.fi;
        posj = aux.se.se;

        if(posi + 1 <= n && g[posi+1][posj] && dist[posi+1][posj].fi == -1){
            dist[posi+1][posj] = mp(a + calc(g[posi+1][posj], x), b + calc(g[posi+1][posj], y));
            qu.insert(mp(mp(a + calc(g[posi+1][posj], x), b + calc(g[posi+1][posj], y)), mp(posi+1, posj)));

        }

        if(posj + 1 <= n && g[posi][posj+1] && dist[posi][posj+1].fi == -1){
            dist[posi][posj+1] = mp(a + calc(g[posi][posj+1], x), b + calc(g[posi][posj+1], y));
            qu.insert(mp(mp(a + calc(g[posi][posj+1], x), b + calc(g[posi][posj+1], y)), mp(posi, posj+1)));
        }

    }

    return;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >>g[i][j];
        }
    }

    Dijkstra(n, 2, 5);
    int ans = min(dist[n][n].fi, dist[n][n].se);
    Dijkstra(n, 5, 2);
    ans = min(ans, min(dist[n][n].fi, dist[n][n].se));

    cout <<ans <<endl;

    return 0;
}
