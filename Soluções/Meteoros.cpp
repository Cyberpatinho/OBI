#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int t = 0;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2;
    while(cin >>x1 >>y1 >>x2 >>y2){
        if(!x1 && !y1 && !x2 && !y2) break;
        int n, i, j, ans = 0; cin >>n;
        while(n--){
            cin >>i >>j;
            ans += ((i >= x1 && i <= x2) && (j <= y1 && j >= y2));
        }

        cout <<"Teste " <<++t <<endl <<ans <<endl <<endl;

    }

    return 0;
}
