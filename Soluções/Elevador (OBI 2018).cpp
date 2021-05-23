#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5+5;

int a[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 1; i<=n; i++) cin >>a[i];

    sort(a, a+n+1);

    bool ok = 1;
    for(int i = 1; i<=n; i++){
        if(a[i] - a[i-1] > 8) ok = 0;
    }

    cout <<(ok? "S" : "N") <<endl;

    return 0;
}
