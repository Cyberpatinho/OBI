#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e5+5;

ll vis[N];
vector<ll> g[N];

ll DFS(ll u){
    vis[u] = 1;
    ll ans = 1;
    for(int i = 0; i<g[u].size(); i++){
        ll v = g[u][i];
        if(!vis[v]) ans += DFS(v);
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >>n;
    for(int i = 1; i<n; i++){
        int u, v, c; cin >>u >>v >>c;
        if(!c){
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    ll ans = (n*(n-1))/2;
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            ll cmp = DFS(i);
            ans -= (cmp*(cmp-1))/2;
        }
    }

    cout <<ans <<endl;

    return 0;
}
