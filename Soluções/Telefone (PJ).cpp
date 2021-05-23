#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

map<char, char> m;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int cnt = 0, n = '2';
    for(int i = 'A'; i<='Z'; i++){
        if(i == 'S' || i == 'Z'){
            m[i] = n-1;
        }
        else{
            m[i] = n;
            cnt++;
        }
        if(cnt == 3){
            cnt = 0;
            n++;
        }
    }

    string s, ans = ""; cin >>s;
    for(int i = 0; s[i]; i++){
        if(s[i] == '-') ans += s[i];
        else ans += m[s[i]];
    }

    cout <<ans <<endl;

    return 0;
}
