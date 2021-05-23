#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define endl '\n'

ll solve(ll n){

    ll I[2][2] = {{2, 2}, {2, 3}};
    ll M[2] = {6, 6}, aux1[2], aux2[2][2];

    for(ll base = n-1; base>0; base/=2){
        memset(aux1, 0, sizeof aux1);
        memset(aux2, 0, sizeof aux2);
        if(base%2){
            for(int i = 0; i<2; i++){
                for(int j = 0; j<2; j++){
                    aux1[i] = (aux1[i] + (M[j]*I[j][i])%MOD)%MOD;
                }
            }
            for(int i = 0; i<2; i++) M[i] = aux1[i];
        }

        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                for(int k = 0; k<2; k++){
                    aux2[i][j] = (aux2[i][j] + (I[i][k]*I[k][j])%MOD)%MOD;
                }
            }
        }
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                I[i][j] = aux2[i][j];
            }
        }

    }

    return (M[0] + M[1])%MOD;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n; cin >>n;
    cout <<solve(n) <<endl;

    return 0;
}
