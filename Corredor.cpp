#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int arr[50050];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++) cin >>arr[i];

    int ans = arr[0], aux = arr[i];
    for(int i = 1; i<n; i++){
        aux = max(arr[i], aux + arr[i]);
        ans = max(ans, aux);
    }

    cout <<ans <<endl;
    return 0;
}
