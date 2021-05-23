#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e4+5;

map<string, int> node;

int dist[N];
vector<int> g[N];
vector<string> v;

int BFS(int src, int dest){

    memset(dist, -1, sizeof dist);

    dist[src] = 0;
    queue<int> qu;
    qu.push(src);

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();

        for(int i = 0; i<g[u].size(); i++){
            int v = g[u][i];
            if(dist[v] == -1){
                dist[v] = 1 + dist[u];
                qu.push(v);
            }
            if(v == dest) return dist[v];
        }
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;

    int c = 0;
    for(int i = 0; i<n; i++){
        string s1, s2; cin >>s1 >>s2;
        if(node.find(s1) == node.end()){
            node[s1] = ++c; v.push_back(s1);
        }
        if(node.find(s2) == node.end()){
            node[s2] = ++c; v.push_back(s2);
        }
        g[node[s1]].push_back(node[s2]);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i<v.size()-1; i++){
        g[node[v[i]]].push_back(node[v[i+1]]);
        g[node[v[i+1]]].push_back(node[v[i]]);
    }

    string s1, s2; cin >>s1 >>s2;
    int ans = BFS(node[s1], node[s2]);

    cout <<ans <<endl;

    return 0;
}
