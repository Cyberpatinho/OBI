#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

const int N = 1e3+5;

int ans[N], call[N*N];

set<int> ok;
set<pii> occ;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, t; cin >>n >>m;
    for(int i = 0; i<m; i++) cin >>call[i];
    for(int i = 1; i<=n; i++) ok.insert(i);

    int T = 0, now;
    for(int i = 0; i<m; i++){
        if(!ok.empty()){
            now = *ok.begin();
            ok.erase(now);
            occ.insert({T+call[i], now});
            ans[now]++;
        }
        else{
            pii aux = *occ.begin();
            occ.erase(aux);
            T = aux.fi;
            occ.insert({T+call[i], aux.se});
            ans[aux.se]++;
        }
        while(!occ.empty() && T >= (*occ.begin()).fi){
            ok.insert((*occ.begin()).se);
            occ.erase(*occ.begin());
        }
    }

    for(int i = 1; i<=n; i++) cout <<i <<" " <<ans[i] <<endl;

    return 0;
}
