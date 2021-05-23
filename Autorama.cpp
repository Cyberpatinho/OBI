#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 105;

struct Car{
    int id, p, pos, t;
};

Car car[N];

bool cmp(Car a, Car b){
    if(a.p == b.p) return a.t < b.t;
    else return a.p > b.p;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k, n, m; cin >>k >>n >>m;
    for(int i = 1; i<=n; i++){
        car[i].id = i; car[i].p = 0; car[i].t = 0;
    }

    int x, y;
    for(int i = 1; i<=m; i++){
        cin >>x >>y;
        if(car[x].pos == y-1){
            car[x].p++;
            car[x].pos = y%k;
            car[x].t = i;
        }
    }

    sort(car+1, car+n+1, cmp);
    for(int i = 1; i<=n; i++) cout <<car[i].id <<" ";
    cout <<endl;

    return 0;
}
