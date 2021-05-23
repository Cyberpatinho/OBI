#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define x first
#define y second
#define endl '\n'

bool cmp(pll p1, pll p2){
    if(p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}

bool cw(pll p1, pll p2, pll p3){
    return (p2.y - p1.y)*(p3.x - p2.x) - (p2.x - p1.x)*(p3.y - p2.y) > 0;
}

bool ccw(pll p1, pll p2, pll p3){
    return (p2.y - p1.y)*(p3.x - p2.x) - (p2.x - p1.x)*(p3.y - p2.y) < 0;
}

ll Convex_Hull(vector<pll> &v){

    sort(v.begin(), v.end(), cmp);
    pll p1 = v[0], p2 = v.back();
    vector<pll> up, down;
    down.push_back(p1);
    up.push_back(p1);

    for(int i = 1; i<v.size(); i++){
        if(i == v.size()-1 || cw(p1, v[i], p2)){
            while(up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], v[i])){
                up.pop_back();
            }
            up.push_back(v[i]);
        }
        if(i == v.size()-1 || ccw(p1, v[i], p2)){
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], v[i])){
                down.pop_back();
            }
            down.push_back(v[i]);
        }
    }

    return up.size() - 1;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >>n;
    vector<pll> v;
    for(int i = 0; i<n; i++){
        ll x, y; cin >>x >>y;
        v.push_back({x, y});
    }

    ll ans = Convex_Hull(v);

    cout <<ans <<endl;

    return 0;
}
