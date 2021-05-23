#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int h, l; cin >>h >>l;
    int a[2], b[2];
    cin >>a[0] >>a[1] >>b[0] >>b[1];

    bool ok = 0;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            int x = a[i] + b[j];
            int y = max(a[1-i], b[1-j]);
            if(min(x, y) <= min(h, l) && max(x, y) <= max(h, l)) ok = 1;
        }
    }

    cout <<(ok? "S" : "N") <<endl;

    return 0;
}
