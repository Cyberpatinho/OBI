#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int fastexp(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;

    int aux = fastexp(a, b/2);
    if(b%2 == 0) return aux*aux;
    else return a*aux*aux;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    int x1, y1, x2, y2, ans = 0;
    for(int i =0; i<n; i++){
        cin >>x1 >>y1 >>x2 >>y2;
        ans += (fastexp(abs(x1-x2), 2) + fastexp(abs(y1-y2), 2));
    }

    cout <<ans <<endl;

    return 0;
}
