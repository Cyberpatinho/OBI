#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

int cost[105];
vector<pii> g[105];
void Dijkstra(){

    set<pii> qu;
    qu.insert({0, 1});

    while(!qu.empty()){
        pii aux = *qu.begin();
        qu.erase(qu.begin());

        int v = aux.se;
        int c = aux.fi;
        if(cost[v] != -1) continue;
        cost[v] = c;

        for(int i = 0; i<g[v].size(); i++){
            pii ne = g[v][i];
            if(cost[ne.se] == -1) qu.insert({ne.fi + c, ne.se});
        }

    }

}

int main(){

    ios_base::sync_with_stdio(0);
    int n, m; cin >>n >>m;

    int a, b, c;
    while(m--){
        cin >>a >>b >>c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    memset(cost, -1, sizeof cost);
    Dijkstra();

    //for(int i = 1; i<=n; i++) cout <<cost[i] <<" ";

    cout <<cost[n] <<endl;
    return 0;
}
