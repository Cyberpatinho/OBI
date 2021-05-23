#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e3;

char g[N+5][N+5];

bool check(int n){

    bool ok = 1;
    int cmp = 0;
    char last = '.';
    for(int i = 0; i<n; i++){
        cmp = 0; last = '.';
        for(int j = 0; j<n; j++){
            if(g[i][j] == '*' && last == '.') cmp++;
            last = g[i][j];
        }
        if(cmp > 1) return false;
    }

    for(int i = 0; i<n; i++){
        cmp = 0; last = '.';
        for(int j = 0; j<n; j++){
            if(g[j][i] == '*' && last == '.') cmp++;
            last = g[j][i];
        }
        if(cmp > 1) return false;
    }

    return true;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >>g[i][j];
        }
    }

    bool ok = check(n);

    cout <<(ok? "S" : "N") <<endl;
    return 0;
}
