#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<ld, ld> pld;
#define fi first
#define se second
#define endl '\n'

const int N = 1e3+5;

pld ve[N];
int vis[N];
vector<int> g[N];

ld dist(ld x1, ld y1, ld x2, ld y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void DFS(int u){
    vis[u] = 1;
    for(int i = 0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!vis[v]) DFS(v);
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; ld d; cin >>n >>d;
    for(int i = 0; i<n; i++){
        cin >>ve[i].fi >>ve[i].se;
    }

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(dist(ve[i].fi, ve[i].se, ve[j].fi, ve[j].se) <= d + 1e-6){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    int cmp = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            DFS(i); cmp++;
        }
    }

    cout <<(cmp == 1? "S" : "N") <<endl;

    return 0;
}
