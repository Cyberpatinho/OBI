#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m; cin >>n >>m;
    int last, ma = 0; cin >>last;
    for(int i = 1; i<n; i++){
        int x; cin >>x;
        ma = max(ma, x - last);
        last = x;
    }

    ma = max(ma, 42195 - last);

    cout <<(m >= ma? 'S' : 'N') <<endl;

    return 0;
}
