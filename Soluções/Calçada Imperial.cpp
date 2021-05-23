#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 5*1e2+5;

int arr[N+5];

int solve(int n, int a, int b){
    int ans = 0;
    int last = a;
    for(int i = 0; i<n; i++){
        if(arr[i] != last && (arr[i] == a || arr[i] == b)){
            ans++; last = arr[i];
        }
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >>n;
    bool ok = 0;
    for(int i = 0; i<n; i++){
        cin >>arr[i];
        if(i > 0 && arr[i] != arr[i-1]) ok = 1;
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ans = max(ans, solve(n, arr[i], arr[j]));
        }
    }

    cout <<(ok? ans : 1) <<endl;

    return 0;
}
