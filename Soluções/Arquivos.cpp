#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5+5;

int a[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, b; cin >>n >>b;
    for(int i = 0; i<n; i++) cin >>a[i];

    sort(a, a+n);

    int ans = n, L = 0, R = n-1;
    while(L < R){
        while(R > 0 && (a[L] + a[R] > b)) R--;
        if(a[L] + a[R] <= b && L < R){
            L++; R--; ans--;
        }
    }

    cout <<ans <<endl;

    return 0;
}
