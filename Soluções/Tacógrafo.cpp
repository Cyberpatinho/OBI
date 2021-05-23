#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e3+5;

int a[N], b[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++) cin >>a[i] >>b[i];

    int ans = 0;
    for(int i = 0; i<n; i++){
        ans += a[i]*b[i];
    }

    cout <<ans <<endl;

    return 0;
}
