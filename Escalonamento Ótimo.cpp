#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

const int N = 5*1e4+5;

vector<int> g[N];
int deg[N], vis[N];

bool has_cycle(int u){
    vis[u] = 1;
    bool has = 0;
    for(int i = 0; i<g[u].size(); i++){
        int v = g[u][i];
        if(vis[v] == 2) continue;
        else if(!vis[v]) has |= has_cycle(v);
        else if(vis[v] == 1) has = 1;
    }
    vis[u] = 2;
    return has;
}

vector<int> ans;
void solve(int n){
    set<int> qu;
    for(int i = 0; i<n; i++){
        if(!deg[i]) qu.insert(i);
    }

    while(!qu.empty()){
        int u = *qu.begin();
        qu.erase(u);
        ans.push_back(u);
        for(int i = 0; i<g[u].size(); i++){
            int v = g[u][i];
            deg[v]--;
            if(!deg[v]) qu.insert(v);
        }
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, u, v; cin >>n >>m;
    for(int i = 0; i<m; i++){
        cin >>u >>v;
        g[u].push_back(v);
        deg[v]++;
    }

    bool cycle = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i] && has_cycle(i)){
            cycle = 1; break;
        }
    }

    if(cycle) cout <<"*" <<endl;
    else{
        solve(n);
        for(int i = 0; i<ans.size(); i++) cout <<ans[i] <<endl;
    }

    return 0;
}
