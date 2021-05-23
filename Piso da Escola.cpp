#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0);
    int l, c; cin >>l >>c;
    int ans1 = c*l + (c-1)*(l-1);
    int ans2 = 2*(c-1) + 2*(l-1);

    cout <<ans1 <<endl <<ans2 <<endl;
    return 0;
}
