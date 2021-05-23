#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e6+5;

int cnt[N], rem[N];
int solve(int n, int m){

    for(int i = 0; i<=n; i++){
        if(!cnt[i]){
            for(int j = 1; j<=m; j++){
                cnt[i+j]++;
                rem[i+j] = j;
            }
        }
        else if(cnt[i] == 1 && rem[i] <= n){
            cnt[i + rem[i]]++;
            rem[i + rem[i]] = rem[i];
        }
    }

    return cnt[n];
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >>n >>m;
    cout <<(solve(n, m)? "Paula" : "Carlos") <<endl;

    return 0;
}
