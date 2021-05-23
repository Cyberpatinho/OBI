#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5;

int seg[4*N+5];

void update(int node, int l, int r, int pos, int val){

    if(l == pos && r == pos){
        seg[node] = val;
        return;
    }
    if(pos < l || pos > r) return;

    int mid = (l+r)/2;
    update(2*node, l, mid, pos, val);
    update(2*node+1, mid+1, r, pos, val);
    seg[node] = seg[2*node] + seg[2*node+1];
    return;
}

int query(int node, int l, int r, int a, int b){

    if(l >= a && r <= b){
        return seg[node];
    }
    if(l > b || r < a){
        return 0;
    }
    int mid = (l+r)/2;
    return query(2*node, l, mid, a, b) + query(2*node+1, mid+1, r, a, b);
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, p, op; cin >>n >>q;
    for(int i = 1; i<=n; i++){
        cin >>p; update(1, 1, n, i, p);
    }

    int a, b;
    while(q--){
        cin >>op;
        if(!op){
            cin >>a >>b; update(1, 1, n, a, b);
        }
        if(op){
            cin >>a;
            cout <<query(1, 1, n, 1, a) <<endl;
        }
    }

    return 0;
}
