#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5+5;

int a[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k; cin >>n >>k;
    for(int i = 0; i<n; i++) cin >>a[i];

    sort(a, a+n);

    int ans = 1000000000;
    for(int i = 0; i<=k && (n-1-k+i < n); i++){
        ans = min(ans, a[n-1-k+i] - a[i]);
    }

    cout <<ans <<endl;

    return 0;
}
