#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e2;

char g[N+5][N+5];

int solve(int n){

    int ans = 0, temp = 0;
    for(int i = 0; i<n; i++){
        if(i%2 == 0){
            for(int j = 0; j<n; j++){
                if(g[i][j] == 'o') temp++;
                if(g[i][j] == 'A'){
                    ans = max(ans, temp);
                    temp = 0;
                }
                if(i == n-1 && j == n-1) ans = max(ans, temp);
            }
        }
        else{
            for(int j = n-1; j>=0; j--){
                if(g[i][j] == 'o') temp++;
                if(g[i][j] == 'A'){
                    ans = max(ans, temp);
                    temp = 0;
                }
                if(i == n-1 && j == 0) ans = max(ans, temp);
            }
        }
    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >>g[i][j];
        }
    }

    int ans = solve(n);

    cout <<ans <<endl;
    return 0;
}
