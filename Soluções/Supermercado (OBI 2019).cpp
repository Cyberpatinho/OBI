#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(2);

    int n; cin >>n;

    long double ans = 99999999.0;
    long double p, q;
    while(n--){
        cin >>p >>q;
        //cout <<p <<" " <<q <<" " <<p/q <<" " <<(p/q)*1000 <<endl;
        if((p/q)*1000 < ans) ans = (p/q)*1000;
    }

    cout <<ans <<endl;

    return 0;
}
