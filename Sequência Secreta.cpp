#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 5*1e2+5;

int arr[N+5];

int solve(int n, int last){

    int ans = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] != last){
            ans++; last = arr[i];
        }
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++) cin >>arr[i];

    int ans = max(solve(n, 1), solve(n, 2));

    cout <<ans <<endl;

    return 0;
}
