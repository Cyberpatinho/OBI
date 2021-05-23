#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define endl '\n'

const int N = 1e5;

int deg[N+5];
vector<int> g[N+5];
pii DFS(int u, int from, int n){

    int w = 1, ans = INF;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v != from){
            pii aux = DFS(v, u, n);
            ans = min(ans, aux.se);
            w += aux.fi;
        }
    }

    ans = min(ans, abs(n - 2*w));
    return {w, ans};
}

int main(){

    //ios_base::sync_with_stdio(0);
    int n, a, b; cin >>n;
    for(int i = 1; i<n; i++){
        cin >>a >>b;
        deg[a]++; deg[b]++;
        g[a].push_back(b); g[b].push_back(a);
    }

    int start;
    for(int i = 1; i<=n; i++){
        if(deg[i] == 1){
            start = i; break;
        }
    }

    pii ans = DFS(start, -1, n);

    cout <<ans.se <<endl;
    return 0;
}
