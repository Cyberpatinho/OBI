#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

bool vis[1005];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, x; cin >>n;
    for(int i = 0; i<n-1; i++){
        cin >>x;
        vis[x] = 1;
    }

    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            cout <<i <<endl;
            break;
        }
    }

    return 0;
}
