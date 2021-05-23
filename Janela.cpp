#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

bool v[605];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b, c; cin >>a >>b >>c;
    for(int i = a; i<a+200; i++) v[i] = 1;
    for(int i = b; i<b+200; i++) v[i] = 1;
    for(int i = c; i<c+200; i++) v[i] = 1;


    int ans = 0;
    for(int i = 0; i<600; i++) ans += !v[i];

    cout <<ans*100 <<endl;

    return 0;
}
