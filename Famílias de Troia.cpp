#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 5*1e4+5;

int vis[N];
vector<int> g[N];
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

    int n, m; cin >>n >>m;
    for(int i = 0; i<m; i++){
        int u, v; cin >>u >>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            ans++;
            DFS(i);
        }
    }

    cout <<ans <<endl;

    return 0;
}
