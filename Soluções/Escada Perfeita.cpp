#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

const int N = 1e5+5;

ll arr[N], S[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >>n;
    ll sum = 0;
    for(int i = 0; i<n; i++){
        cin >>arr[i];
        sum += arr[i];
    }

    ll start = -1, ans = 0;
    for(int i = 1; i<=N; i++){
        S[i] = S[i-1] + i;
        if(i >= n){
            ll aux = S[i] - S[i-n];
            if(aux >= sum){
                if(aux == sum) start = i-n+1;
                break;
            }
        }
    }

    if(start == -1) cout <<-1 <<endl;
    else{
        for(int i = 0; i<n; i++){
            ans += abs(arr[i] - (start+i));
        }
        cout <<ans/2 <<endl;
    }

    return 0;
}
