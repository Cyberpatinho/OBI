#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int cnt[10];

bool solve(int pos, int last){

    if(pos >= 8) return 1;

    bool ok = 0;
    for(int i = 0; i<=9; i++){
        if(cnt[i] && i != last){
            cnt[i]--;
            ok |= solve(pos+1, i);
            cnt[i]++;
        }
    }

    return ok;
}

int main(){

    int x;
    for(int i = 0; i<8; i++){
        cin >>x; cnt[x]++;
    }

    bool ok = solve(0, -1);

    cout <<(ok? "S" : "N") <<endl;

    return 0;
}
