#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int par[105];
int color[105];
vector<int> g[105];

void DFS(int now, int from, int to, int c){

    par[now] = from;
    for(int i = 0; i<g[now].size(); i++){
        int ne = g[now][i];
        if(!par[ne]) DFS(ne, now, to, c);
    }

    if(now == to){
        color[now] = c;
        int curr = par[now];
        while(curr != -1){
            color[curr] = c;
            curr = par[curr];
        }
    }

    return;
}

int main(){

    ios_base::sync_with_stdio(0);
    int n, m; cin >>n >>m;
    for(int i = 1; i<=n; i++) par[i] = i;
    int a, b, loop = n-1;
    while(loop--){
        cin >>a >>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int p, q, c;
    while(m--){
        cin >>p >>q >>c;
        memset(par, 0, sizeof par);
        DFS(p, -1, q, c);
    }

    for(int i = 1; i<=n; i++) cout <<color[i] <<" ";
    cout <<endl;

    return 0;
}
