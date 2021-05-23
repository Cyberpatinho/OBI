#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define endl '\n'

const int N = 1e3;

int vis[N+5];
vector<pii> g[N+5];

pii Dijkstra(int src){

    pii ans = make_pair(INF, -INF);
    set<pii> qu;
    qu.insert({0, src});

    while(!qu.empty()){
        pii aux = *qu.begin();
        qu.erase(qu.begin());
        int v = aux.se; int w = aux.fi;
        if(vis[v]) continue;

        vis[v] = 1;
        if(v != src){
            ans.fi = min(ans.fi, w);
            ans.se = max(ans.se, w);
            //cout <<ans.fi <<" " <<ans.se <<endl;
        }

        for(int i = 0; i<g[v].size(); i++){
            pii ne = g[v][i];
            if(!vis[ne.se]){
                qu.insert({ne.fi + w, ne.se});
            }
        }

    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    int n, m; cin >>n >>m;
    int a, b, w;
    while(m--){
        cin >>a >>b >>w;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    int src; cin >>src;
    pii ans = Dijkstra(src);

    cout <<ans.se - ans.fi <<endl;
    return 0;
}
