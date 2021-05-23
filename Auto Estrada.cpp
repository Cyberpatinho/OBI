#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0);
    int n; cin >>n;
    string s; cin >>s;

    int ans = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == 'P' || s[i] == 'C') ans += 2;
        if(s[i] == 'A') ans++;
    }

    cout <<ans <<endl;
    return 0;
}
