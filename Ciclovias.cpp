#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5+5;

vector<int> g[N];
int ans[N], suff[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, u, v; cin >>n >>m;
    for(int i = 0; i<m; i++){
        cin >>u >>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i<=n; i++){
        sort(g[i].begin(), g[i].end());
        ans[i] = 1;
    }

    for(int i = n; i>0; i--){
        for(int j = g[i].size(); j>=0; j--) suff[j] = 0;
        for(int j = g[i].size()-1; j>=0; j--){
            suff[j] = max(ans[g[i][j]], suff[j+1]);
        }
        for(int j = 0; j<g[i].size(); j++){
            ans[g[i][j]] = max(ans[g[i][j]], 2 + suff[j+1]);
        }
    }

    for(int i = 1; i<=n; i++) cout <<ans[i] <<" ";

    return 0;
}
