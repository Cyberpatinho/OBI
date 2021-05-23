#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5+5;

int a[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++) cin >>a[i];

    int ans1 = 0, ans2 = 0, sum = 0, sum1 = 0, sum2 = 0;
    for(int i = 0; i<n; i++){
        sum += a[i];
        sum1 += a[i];
        if(sum1 < 0) sum1 = 0;
        ans1 = max(ans1, sum1);
    }

    for(int i = 0; i<n; i++){
        sum2 += a[i];
        if(sum2 > 0) sum2 = 0;
        ans2 = max(ans2, sum - sum2);
    }

    cout <<max(ans1, ans2) <<endl;

    return 0;
}
