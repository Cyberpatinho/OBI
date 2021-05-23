#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5+5;

int arr[N];
bool vis[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    int ans = 0;
    for(int i = 0; i<n; i++){
        cin >>arr[i];
        vis[arr[i]] = 1;
        if(!vis[arr[i]-1]) ans++;
    }

    cout <<ans <<endl;

    return 0;
}
