#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0);

    int n; cin >>n;

    int a, b, d = 0, x = 0;
    while(n--){
        cin >>a >>b;
        if((a+1)%5 == b || (a+2)%5  == b) d++;
        else x++;
    }

    cout <<(d > x? "dario" : "xerxes") <<endl;
    return 0;
}
