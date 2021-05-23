#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    int ans = 0, x;
    for(int i = 0; i<n; i++){
        cin >>x;
        ans += (x-1);
    }

    cout <<ans <<endl;

    return 0;
}
