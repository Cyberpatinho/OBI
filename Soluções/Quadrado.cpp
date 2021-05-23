#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define endl '\n'

int m[55][55];
int r[55], c[55];

pii find_dif(int n){

    int idxr = -1;
    if(r[0] == r[1] && r[0] != r[2]) idxr = 2;
    if(r[0] == r[2] && r[0] != r[1]) idxr = 1;
    if(r[1] == r[2] && r[0] != r[1]) idxr = 0;

    if(idxr == -1){
        for(int i = 3; i<n; i++){
            if(r[i] != r[0]){
                idxr = i; break;
            }
        }
    }

    int idxc = -1;
    if(c[0] == c[1] && c[0] != c[2]) idxc = 2;
    if(c[0] == c[2] && c[0] != c[1]) idxc = 1;
    if(c[1] == c[2] && c[0] != c[1]) idxc = 0;

    if(idxc == -1){
        for(int i = 3; i<n; i++){
            if(c[i] != c[0]){
                idxc = i; break;
            }
        }
    }

    return make_pair(idxr, idxc);
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = 0; j<n; j++){
            cin >>m[i][j];
            sum += m[i][j];
        }
        r[i] = sum;
    }

    for(int j = 0; j<n; j++){
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += m[i][j];
        }
        c[j] = sum;
    }

    pii ans = find_dif(n);
    int aux = ans.fi == 0? ans.fi+1 : ans.fi - 1;

    cout <<r[aux] - (r[ans.fi] - m[ans.fi][ans.se]) <<" " <<m[ans.fi][ans.se] <<endl;

    return 0;
}
