#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define endl '\n'

const int N = 1e5+5;

struct Node{
    int s, pref, suff, sum, cntS, cntPref, cntSuff, cntSum;
};

Node seg[4*N+5];

void update(int no, int l, int r, int pos, int val){

    if(l >= pos && r <= pos){
        seg[no].s = val;
        seg[no].pref = val;
        seg[no].suff = val;
        seg[no].sum = val;
        seg[no].cntS = 1;
        seg[no].cntPref = 1;
        seg[no].cntSuff = 1;
        seg[no].cntSum = 1;
        return;
    }
    else if(l > pos || r < pos) return;

    int mid = (l+r)/2;
    update(2*no, l, mid, pos, val);
    update(2*no+1, mid+1, r, pos, val);

    seg[no].sum = seg[2*no].sum + seg[2*no+1].sum;
    seg[no].cntSum = seg[2*no].cntSum + seg[2*no+1].cntSum;

    if(seg[2*no].pref == seg[2*no].sum + seg[2*no+1].pref){
        seg[no].pref = seg[2*no].pref;
        seg[no].cntPref = max(seg[2*no].cntPref, seg[2*no].cntSum + seg[2*no+1].cntPref);
    }
    else if(seg[2*no].pref > seg[2*no].sum + seg[2*no+1].pref){
        seg[no].pref = seg[2*no].pref;
        seg[no].pref = seg[2*no].cntPref;
    }
    else{
        seg[no].pref = seg[2*no].sum + seg[2*no+1].pref;
        seg[no].cntPref = seg[2*no].cntSum + seg[2*no+1].cntPref;
    }

    if(seg[2*no+1].suff == seg[2*no+1].sum + seg[2*no].suff){
        seg[no].suff = seg[2*no+1].suff;
        seg[no].cntSuff = max(seg[2*no+1].cntSuff, seg[2*no+1].cntSum + seg[2*no].cntSuff);
    }
    else if(seg[2*no+1].suff > seg[2*no+1].sum + seg[2*no].suff){
        seg[no].suff = seg[2*no+1].suff;
        seg[no].cntSuff = seg[2*no+1].cntSuff;
    }
    else{
        seg[no].suff = seg[2*no+1].sum + seg[2*no].suff;
        seg[no].cntSuff = seg[2*no+1].cntSum + seg[2*no].cntSuff;
    }

    if((seg[2*no].s >= seg[2*no+1].s) && (seg[2*no].s >= seg[2*no].suff + seg[2*no+1].pref)){
        seg[no].s = seg[2*no].s;
        seg[no].cntS = seg[2*no].cntS;
        if(seg[2*no].s == seg[2*no+1].s) seg[no].cntS = max(seg[no].cntS, seg[2*no+1].cntS);
        if(seg[2*no].s == seg[2*no].suff + seg[2*no+1].pref) seg[no].cntS = max(seg[no].cntS, seg[2*no].cntSuff + seg[2*no+1].cntPref);
    }
    else if((seg[2*no+1].s >= seg[2*no].s) && (seg[2*no+1].s >= seg[2*no].suff + seg[2*no+1].pref)){
        seg[no].s = seg[2*no+1].s;
        seg[no].cntS = seg[2*no+1].cntS;
        if(seg[2*no+1].s == seg[2*no].s) seg[no].cntS = max(seg[no].cntS, seg[2*no].cntS);
        if(seg[2*no+1].s == seg[2*no].suff + seg[2*no+1].pref) seg[no].cntS = max(seg[no].cntS, seg[2*no].cntSuff + seg[2*no+1].cntPref);
    }
    else{
        seg[no].s = seg[2*no].suff + seg[2*no+1].pref;
        seg[no].cntS = seg[2*no].cntSuff + seg[2*no+1].cntPref;
        if(seg[2*no].suff + seg[2*no+1].pref == seg[2*no].s) seg[no].cntS = max(seg[no].cntS, seg[2*no].cntS);
        if(seg[2*no].suff + seg[2*no+1].pref == seg[2*no+1].s) seg[no].cntS = max(seg[no].cntS, seg[2*no+1].cntS);
    }


    return;
}

Node query(int no, int l, int r, int a, int b){
    if(l >= a && r <= b){
        return {seg[no].s, seg[no].pref, seg[no].suff, seg[no].sum, seg[no].cntS, seg[no].cntPref, seg[no].cntSuff, seg[no].cntSum};
    }
    if(l > b || r < a) return {-INF, -INF, -INF, -INF, -INF, -INF, -INF, -INF};

    int mid = (l+r)/2;
    Node aux1 = query(2*no, l, mid, a, b);
    Node aux2 = query(2*no+1, mid+1, r, a, b);

    Node ans;

    ans.sum = aux1.sum + aux2.sum;
    ans.cntSum = aux1.cntSum + aux2.cntSum;

    if(aux1.pref == aux1.sum + aux2.pref){
        ans.pref = aux1.pref;
        ans.cntPref = max(aux1.cntPref, aux1.cntSum + aux2.cntPref);
    }
    else if(aux1.pref > aux1.sum + aux2.pref){
        ans.pref = aux1.pref;
        ans.pref = aux1.cntPref;
    }
    else{
        ans.pref = aux1.sum + aux2.pref;
        ans.cntPref = aux1.cntSum + aux2.cntPref;
    }

    if(aux2.suff == aux2.sum + aux1.suff){
        ans.suff = aux2.suff;
        ans.cntSuff = max(aux2.cntSuff, aux2.cntSum + aux1.cntSuff);
    }
    else if(aux2.suff > aux2.sum + aux1.suff){
        ans.suff = aux2.suff;
        ans.cntSuff = aux2.cntSuff;
    }
    else{
        ans.suff = aux2.sum + aux1.suff;
        ans.cntSuff = aux2.cntSum + aux1.cntSuff;
    }

    if((aux1.s >= aux2.s) && (aux1.s >= aux1.suff + aux2.pref)){
        ans.s = aux1.s;
        ans.cntS = aux1.cntS;
        if(aux1.s == aux2.s) ans.cntS = max(ans.cntS, aux2.cntS);
        if(aux1.s == aux1.suff + aux2.pref) ans.cntS = max(ans.cntS, aux1.cntSuff + aux2.cntPref);
    }
    else if((aux2.s >= aux1.s) && (aux2.s >= aux1.suff + aux2.pref)){
        ans.s = aux2.s;
        ans.cntS = aux2.cntS;
        if(aux2.s == aux1.s) ans.cntS = max(ans.cntS, aux1.cntS);
        if(aux2.s == aux1.suff + aux2.pref) ans.cntS = max(ans.cntS, aux1.cntSuff + aux2.cntPref);
    }
    else{
        ans.s = aux1.suff + aux2.pref;
        ans.cntS = aux1.cntSuff + aux2.cntPref;
        if(aux1.suff + aux2.pref == aux1.s) ans.cntS = max(ans.cntS, aux1.cntS);
        if(aux1.suff + aux2.pref == aux2.s) ans.cntS = max(ans.cntS, aux2.cntS);
    }


    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >>t;
    while(t--){

        int n, x; cin >>n;
        for(int i = 1; i<=n; i++){
            cin >>x; update(1, 1, n, i, x);
        }

        int q; cin >>q;
        while(q--){
            int a, b; cin >>a >>b;
            Node ans = query(1, 1, n, a, b);
            cout <<ans.s <<" " <<ans.cntS <<endl;
        }

        Node reset = {0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 0; i<=4*n+1; i++){
            seg[i] = reset;
        }
    }

    return 0;
}
