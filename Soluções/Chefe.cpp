#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define endl '\n'

const int N = 505;

int a[N], pos[N], vis[N];
vector<int> g[N];

int DFS(int u, int src){

    vis[u] = 1;

    int ans = INF;
    if(u != src) ans = min(ans, a[u]);
    for(int i = 0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!vis[v]) ans = min(ans, DFS(v, src));
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, q, u, v; cin >>n >>m >>q;
    for(int i = 1; i<=n; i++){
        cin >>a[i]; pos[i] = i;
    }
    for(int i = 0; i<m; i++){
        cin >>u >>v;
        g[v].push_back(u);
    }

    char op;
    int x, y;
    while(q--){
        cin >>op;
        if(op == 'T'){
            cin >>u >>v;
            x = pos[u], y = pos[v];
            swap(a[x], a[y]);
            swap(pos[u], pos[v]);
        }
        else{
            cin >>u;
            x = pos[u];
            memset(vis, 0, sizeof vis);
            int ans = DFS(x, x);
            if(ans >= INF) cout <<"*" <<endl;
            else cout <<ans <<endl;
        }

    }

    return 0;
}
