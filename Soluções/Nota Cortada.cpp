#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int b, t; cin >>b >>t;
    int a1 = 160*70;
    int a2 = ((b+t)*70)/2;

    if(a2 == a1/2) cout <<0 <<endl;
    else if(a2 > a1/2) cout <<1 <<endl;
    else cout <<2 <<endl;

    return 0;
}
