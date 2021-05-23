#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n1; ld d1, v1; cin >>n1 >>d1 >>v1;
    int n2; ld d2, v2; cin >>n2 >>d2 >>v2;

    cout <<((d1*1e-3)/v1 < (d2*1e-3)/v2? n1 : n2) <<endl;

    return 0;
}
