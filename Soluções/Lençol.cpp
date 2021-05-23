#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a[2], b[2], l, h;
    cin >>a[0] >>a[1] >>b[0] >>b[1] >>l >>h;

    bool ok = 0;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            int x = a[i] + b[j];
            int y = min(a[1-i], b[1-j]);
            if(min(x, y) >= min(l, h) && max(x, y) >= max(l, h)) ok = 1;
        }
    }

    if(min(a[0], a[1]) >= min(l, h) && max(a[0], a[1]) >= max(l, h)) ok = 1;
    if(min(b[0], b[1]) >= min(l, h) && max(b[0], b[1]) >= max(l, h)) ok = 1;

    cout <<(ok? "S" : "N") <<endl;

    return 0;
}
