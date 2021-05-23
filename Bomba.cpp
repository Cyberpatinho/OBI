#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define endl '\n'

struct Edge{
    int u, v, type;
};

int d[505][3];
vector<Edge> g[505];

void Dijkstra(int src, int dest){

    set<pii> qu;
    qu.insert({0, src});
    d[src][0] = 0;
    while(!qu.empty()){

        pii aux = *qu.begin();
        qu.erase(aux);
        int dist = aux.fi;
        int u = aux.se;

        for(int i = 0; i<g[u].size(); i++){
            Edge e = g[u][i];
            int t = dist%3;
            if(e.type == 0 && t != 0){
                if(dist+1 < d[e.v][(t+1)%3]){
                    d[e.v][(t+1)%3] = dist+1;
                    qu.insert({dist+1, e.v});
                }
            }
            if(e.type == 1 && t == 0){
                if(dist+1 < d[e.v][(t+1)%3]){
                    d[e.v][(t+1)%3] = dist+1;
                    qu.insert({dist+1, e.v});
                }
            }
        }
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, src, dest, m; cin >>n >>src >>dest >>m;
    for(int i = 0; i<m; i++){
        Edge e; cin >>e.u >>e.v >>e.type;
        g[e.u].push_back(e);
    }

    memset(d, INF, sizeof d);

    Dijkstra(src, dest);

    int ans = min(d[dest][0], min(d[dest][1], d[dest][2]));
    if(ans < INF) cout <<ans <<endl;
    else cout <<"*" <<endl;

    return 0;
}
