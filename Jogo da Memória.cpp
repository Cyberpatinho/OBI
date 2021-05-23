#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e4;

int lvl[5*N+5];
int par[5*N+5][32];
vector<int> g[5*N+5];
vector<int> pairs[5*N+5];

void DFS(int u, int from){

    lvl[u] = (u == 1? 0 : lvl[from]+1);
    par[u][0] = from;

    for(int i = 0; i<g[u].size(); i++){
        int v = g[u][i];
        if(v != from) DFS(v, u);
    }

}

void build(int n){
    for(int j = 1; j<=20; j++){
        for(int i = 1; i<=n; i++){
            if(par[i][j-1] != -1){
                par[i][j] = par[par[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int u, int v){

    if(lvl[u] < lvl[v]) swap(u, v);

    for(int i = 20; i>=0; i--){
        if(lvl[u] - (1 << i) >= lvl[v]) u = par[u][i];
    }

    if(u == v) return u;

    for(int i = 20; i>=0; i--){
        if(par[u][i] != -1 && par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a, b; cin >>n;
    for(int i = 1; i<=n; i++){
        cin >>a;
        pairs[a].push_back(i);
    }

    for(int i = 1; i<n; i++){
        cin >>a >>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(par, -1, sizeof par);
    DFS(1, -1);
    build(n);

    int ans = 0, u, v;
    for(int i = 1; i<=n/2; i++){
        u = pairs[i][0]; v = pairs[i][1];
        ans += lvl[u] + lvl[v] - 2*lvl[LCA(u, v)];
    }

    cout <<ans <<endl;

    return 0;
}
