#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define endl '\n'

const int N = 1e4;

int vis[N+5];
vector<int> g[N+5];
int DFS(int u, int to){

    vis[u] = 1;
    if(u == to) return 0;

    int ans = INF;
    for(int i = 0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!vis[v]){
            ans = min(ans, 1 + DFS(v, to));
        }
    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    int n, from, to, a, b; cin >>n >>from >>to;
    for(int i = 1; i<n; i++){
        cin >>a >>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = DFS(from, to);

    cout <<ans <<endl;
    return 0;
}
