#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e3;
int g[N+5];

int main(){

    ios_base::sync_with_stdio(0);
    int ori = 0, ans = 0;
    int m, n; cin >>m >>n;
    int a, v, b;
    while(m--){
        cin >>a >>v >>b;
        g[a] -= v; g[b] += v; ori += v;
    }

    for(int i = 1; i <= n; i++){
        if(g[i] > 0) ans += g[i];
    }

    bool okay = (ori - ans);
    cout <<(okay? 'S' : 'N') <<endl <<ans <<endl;
    return 0;
}
