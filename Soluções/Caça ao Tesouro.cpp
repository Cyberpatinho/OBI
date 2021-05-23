#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e2;

int t;
int arr[N+5];
int dp[N+5][2*100*N];

bool solve(int pos, int x, int y, int amnt, int n){

    if(pos >= n) return x == y;

    int dif = abs(x-y);

    if(amnt < dif) return 0;

    int &r = dp[pos][dif];
    if(r != -1) return r;

    bool ok = 0;

    ok |= solve(pos+1, x+arr[pos], y, amnt-arr[pos], n);
    ok |= solve(pos+1, x, y+arr[pos], amnt-arr[pos], n);

    return r = ok;
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y, n;
    while(cin >>x >>y >>n){

        if(!x && !y && !n) break;

        memset(dp, -1, sizeof dp);

        int amnt = 0;
        for(int i = 0; i<n; i++) { cin >>arr[i]; amnt += arr[i]; }

        bool ok = solve(0, x, y, amnt, n);

        cout <<"Teste " <<++t <<endl <<(ok? "S" : "N") <<endl <<endl;
    }


    return 0;
}
