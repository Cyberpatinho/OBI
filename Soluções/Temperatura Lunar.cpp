#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define endl '\n'

const int N = 1e4;

int t;
int arr[N+5];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    while(cin >>n >>k){

        if(!n && !k) break;

        int aux;
        for(int i = 1; i<=n; i++){
            cin >>aux; arr[i] = arr[i-1] + aux;
        }

        int mi = INF, ma = -INF;
        for(int i = k; i<=n; i++){
            mi = min(mi, (arr[i] - arr[i-k])/k);
            ma = max(ma, (arr[i] - arr[i-k])/k);
        }

        cout <<"Teste " <<++t <<endl <<mi <<" " <<ma <<endl <<endl;

    }

    return 0;
}
