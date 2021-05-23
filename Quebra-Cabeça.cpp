#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5;

struct Edge{
    int to;
    char c;
};

string ans;
vector<Edge> g[2*N+5];
void DFS(int u){
    if(u == 1) return;
    for(int i = 0; i < g[u].size(); i++){
        Edge v = g[u][i];
        ans += v.c;
        DFS(v.to);
    }
    return;
}

int main(){

    //ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    int n; cin >>n;

    int f, t; char l;
    while(n--){
        cin >>f >>l >>t;
        g[f].push_back({t, l});
    }

    DFS(0);

    cout <<ans <<endl;
    return 0;
}
