#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e2;

int mat[5*N+5][5*N+5];

bool solve(int n, int m){

    int start = -1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j <= start){
                if(mat[i][j] != 0) return false;
            }
            else if(j > start && mat[i][j] != 0){
                start = j; break;
            }
            else if(j == m-1) start = m;
        }
    }

    return true;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >>n >>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >>mat[i][j];
        }
    }

    bool ok = solve(n, m);

    cout <<(ok? "S" : "N") <<endl;

    return 0;
}
