#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

map<char, char> aux;

int main(){

    ios_base::sync_with_stdio(0);
    string s; cin >>s;
    for(int i = 2, j = 65; i<=9; i++){
        for(int k = ((i == 7 || i == 9)? 0 : 1); k < 4; k++, j++){
            aux[j] = i + '0';
        }
    }

    for(int i = 0; i < s.length(); i++){
        if(aux.find(s[i]) != aux.end()) cout <<aux[s[i]];
        else cout <<s[i];
    }

    cout <<endl;
    return 0;
}
