#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e2;

int t = 1;
int w[N+5];
int par[N+5];

int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void join(int x, int y){

    x = find(x); y = find(y);
    if(x == y) return;
    if(w[x] > w[y]) par[y] = x;
    else if(w[x] < w[y]) par[x] = y;
    else{
        par[x] = y;
        w[y]++;
    }

}

struct Edge{
    int from, to, d;
};

bool sort_e(Edge a, Edge b){
    return a.d < b.d;
}

Edge e[((N*(N-1))/2)+15];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    while(cin >>n >>m){
        if(n == 0 && m == 0) break;

        for(int i = 1; i<=n; i++){
            par[i] = i; w[i] = 0;
        }

        for(int i = 1; i<=m; i++) cin >>e[i].from >>e[i].to >>e[i].d;
        sort(e+1, e+m+1, sort_e);

        int size = 0; Edge now;
        int from, to;
        cout <<"Teste " <<t++ <<endl;
        for(int i = 1; i<=m; i++){
            now = e[i];
            from = now.from, to = now.to;
            if(find(from) != find(to)){
                size++; join(from, to);
                cout <<min(from, to) <<" " <<max(from, to) <<endl;
            }
            if(size >= n) break;
        }

        cout <<endl;
    }

    return 0;
}
