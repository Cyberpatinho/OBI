#include<bits/stdc++.h>
using namespace std;
#define end '\n'

int mat[10][10];

int fact(int n){
    int ret = 1;
    for(int i = 0; i < n; i++){
        ret *= (n-i);
    }
    return ret;
}

int main(){

    ios_base::sync_with_stdio(0);
    int n, x; cin >>n;

    int loop = fact(n) - 1;
    while(loop--){
        for(int i = 1; i<=n; i++){
            cin >>x; mat[i][x]++;
        }
    }

    int aux = fact(n-1);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(mat[i][j] != aux){
                cout <<j <<" ";
                break;
            }
        }
    }

    cout <<endl;
    return 0;
}
