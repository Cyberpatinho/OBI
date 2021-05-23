#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t = 0;
    while(cin >>n){
        if(!n) break;
        cout <<"Teste " <<++t <<endl;
        int x, y, z = 0;
        while(n--){
            cin >>x >>y;
            z += (x-y);
            cout <<z <<endl;
        }
        cout <<endl;
    }

    return 0;
}
