#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define endl '\n'

ll g[105][105];
ll dist[105][105];
ll ii[4] = {-1, 0, 1, 0};
ll jj[4] = {0, 1, 0, -1};

bool check_move(ll nx, ll ny, ll l, ll r){
    return nx >= 1 && nx <= l && ny >= 1 && ny <= r;
}

ll Djikstra(ll k, ll l, ll c){

    set<pair<ll, pll> > qu;
    qu.insert({0, {1, 1}});
    dist[1][1] = 0;
    ll ans = -1;

    bool broken;
    pair<ll, pll> aux;
    ll x, y, t, nx, ny, w;
    while(!qu.empty()){
        pair<ll, pll> aux = *qu.begin();
        qu.erase(qu.begin());
        t = aux.fi; x = aux.se.fi; y = aux.se.se;

        dist[x][y] = t;
        if(x == l && y == c){
            ans = t; break;
        }

        ll nx, ny;
        for(int i = 0; i<4; i++){
            nx = x + ii[i];
            ny = y + jj[i];
            if(check_move(nx, ny, l, c) && dist[nx][ny] == -1){
                w = g[nx][ny];
                if(w == -1){
                    qu.insert({1 + t, {nx, ny}});
                }
                else{
                    if(g[x][y] == -1 || ((w - t%k == 1) || (w == 0 && t%k == k-1))){
                        ll d;
                        if(w == t%k) d = k;
                        else if(w == 0 && t%k == k-1) d = 1;
                        else if(t%k > w) d = k - (t%k - w);
                        else d = w - t%k;
                        qu.insert({d + t, {nx, ny}});
                    }

                }

            }

        }

    }

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll l, c, k; cin >>l >>c >>k;
    for(int i = 1; i<=l; i++){
        for(int j = 1; j<=c; j++){
            cin >>g[i][j];
        }
    }

    memset(dist, -1, sizeof dist);

    ll ans = Djikstra(k, l, c);

    cout <<ans <<endl;
    return 0;
}
