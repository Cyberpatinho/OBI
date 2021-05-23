#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

const int N = 1e5;

vector<int> v;

int f(int l, int r, int x){
    return min(abs(x - l), abs(x - r));
}

int TS(int lo, int hi, int l, int r){

    int x1, x2, f1, f2;
    while(hi - lo >= 3){
        x1 = lo + (hi-lo)/3;
        x2 = hi - (hi-lo)/3;
        f1 = f(l, r, x1);
        f2 = f(l, r, x2);
        if(f1 < f2) lo = x1;
        else hi = x2;
    }

    int ret = 0;
    for(int i = lo; i<=hi; i++){
        ret = max(ret, f(l, r, i));
    }

    return ret;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, l, r;
    cin >>n >>l >>r;
    int last = l, x;
    for(int i = 0; i<n; i++){
        cin >>x; v.push_back(x);
    }

    sort(v.begin(), v.end());

    bool L = (l < v[0]);
    bool R = (r > v[v.size()-1]);

    int ans = 0;
    for(int i = 0; i<v.size()-1; i++){
        int ts = TS(max(l, v[i]), min(v[i+1], r), v[i], v[i+1]);
        //cout <<v[i] <<" " <<v[i+1] <<" " <<ts <<endl;
        ans = max(ans, ts);
    }

    if(L) ans = max(ans, abs(l - v[0]));
    if(R) ans = max(ans, abs(r - v[v.size()-1]));

    cout <<ans <<endl;
    return 0;
}
