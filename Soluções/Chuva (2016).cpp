#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5+5;

int seg[4*N+1];
void update(int node, int l, int r, int pos, int v){
    if(l >= pos && r <= pos){
        seg[node] = v;
        return;
    }
    if(l > pos || r < pos) return;
    int mid = (l+r)/2;
    update(2*node, l, mid, pos, v);
    update(2*node+1, mid+1, r, pos, v);
    seg[node] = max(seg[2*node], seg[2*node+1]);
    return;
}

int query(int node, int l, int r, int a, int b){
    if(l >= a && r <= b) return seg[node];
    if(l > b || r < a) return -2000000000;
    int mid = (l+r)/2;
    return max(query(2*node, l, mid, a, b), query(2*node+1, mid+1, r, a, b));
}

int a[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 1; i<=n; i++){
        cin >>a[i]; update(1, 1, n, i, a[i]);
    }

    int ans = 0;
    for(int i = 2; i<=n-1; i++){
        if(a[i] < query(1, 1, n, 1, i-1) && a[i] < query(1, 1, n, i+1, n)) ans++;
    }

    cout <<ans <<endl;

    return 0;
}
