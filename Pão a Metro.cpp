#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e4+5;

int a[N];

bool check(int mid, int n, int k){
    int x = 0;
    for(int i = 0; i<k; i++){
        x += a[i]/mid;
    }
    return x >= n;
}

int BS(int lo, int hi, int n, int k){
    int ans = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid, n, k)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k; cin >>n >>k;
    for(int i = 0; i<k; i++) cin >>a[i];

    int ans = BS(1, 10005, n, k);

    cout <<ans <<endl;

    return 0;
}
