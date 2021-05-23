#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0);
    int n, x1, y1, x2, y2;
    cin >>n >>x1 >>y1 >>x2 >>y2;

    bool okay = 0;
    okay = ((x1 <= n/2 && x2 > n/2) || okay);
    okay = ((x2 <= n/2 && x1 > n/2) || okay);
    okay = ((y1 <= n/2 && y2 > n/2) || okay);
    okay = ((y2 <= n/2 && y1 > n/2) || okay);

    cout <<(okay? 'S' : 'N') <<endl;
    return 0;
}
