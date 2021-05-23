#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5+5;

vector<int> g[N];
int on[N], tin[N], low[N];

stack<int> st;
int scc = 0, t = 0;
void Tarjan(int u, int p){

    tin[u] = low[u] = ++t;
    st.push(u); on[u] = 1;
    for(int i = 0; i<g[u].size(); i++){
        int v = g[u][i];
        if(tin[v]){
            if(on[v]) low[u] = min(low[u], tin[v]);
            else continue;
        }
        else{
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
    }

    if(tin[u] == low[u]){
        while(!st.empty()){
            int now = st.top();
            st.pop(); on[now] = 0;
            if(now == u){
                scc++; break;
            }
        }
    }

    return;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, u, v; cin >>n;
    for(int i = 0; i<n; i++){
        cin >>u >>v;
        g[u].push_back(v);
    }

    for(int i = 1; i<=n; i++){
        if(!tin[i]) Tarjan(i, -1);
    }

    cout <<(scc == 1? "S" : "N") <<endl;

    return 0;
}
