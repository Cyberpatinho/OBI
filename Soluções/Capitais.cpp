#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define endl '\n'

const int N = 1e5+5;

vector<int> g[N];
int deg[N], dist[N], par[N];

int BFS(int n){

    memset(dist, -1, sizeof dist);

    queue<int> qu;
    for(int i = 1; i<=n; i++){
        if(deg[i] == 1){
            qu.push(i);
            dist[i] = 0;
        }
    }

    int ans = INF;
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(int i = 0; i<g[u].size(); i++){
            int v = g[u][i];
            if(dist[v] != -1){
                if(par[u] == v) continue;
                ans = min(ans, dist[v] + dist[u] + 1);
                //cout <<u <<" " <<v <<" " <<dist[u] + dist[v] + 1 <<endl;
            }
            else{
                qu.push(v);
                par[v] = u;
                dist[v] = dist[u] + 1;
            }
        }

    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n-1; i++){
        int u, v; cin >>u >>v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    int ans = BFS(n);

    cout <<ans <<endl;

    return 0;
}
