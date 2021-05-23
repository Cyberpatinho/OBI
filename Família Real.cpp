#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

const int N = 1e5;

bool in[N+5];
pii party[N+5];
vector<int> g[N+5];

int BFS(){

    int gen = 0;
    queue<pii> qu;
    qu.push({0, 0});

    while(!qu.empty()){

        pii aux = qu.front();
        int v = aux.fi;
        int ge = aux.se;
        qu.pop();

        party[ge].se++;
        party[ge].fi += in[v];
        gen = max(gen, ge);

        for(int i = 0; i < g[v].size(); i++){
            int ne = g[v][i];
            qu.push({ne, ge + 1});
        }

    }

    return gen;
}

int main(){

    ios_base::sync_with_stdio(0);
    int n, m; cin >>n >>m;

    int aux; cout.setf(ios::fixed); cout.precision(2);
    for(int i = 1; i <= n; i++){
        cin >>aux; g[aux].push_back(i);
    }

    for(int i = 1; i<=m; i++){
        cin >>aux; in[aux] = 1;
    }

    int gen = BFS();
    for(int i = 1; i<=gen; i++){
        cout <<100*((1.0*party[i].fi)/party[i].se) <<" ";
    }
    cout <<endl;

    return 0;
}
