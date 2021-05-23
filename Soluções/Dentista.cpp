#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct consulta{
    int ini, fim;
};

bool sortc(consulta a, consulta b){
    return a.fim < b.fim;
}

consulta arr[10050];

int main(){

    ios_base::sync_with_stdio(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++) cin >>arr[i].ini >>arr[i].fim;
    sort(arr, arr+n, sortc);

    int ans = 0, last = 0;
    for(int i = 0; i<n; i++){
        if(arr[i].ini >= last){
            last = arr[i].fim; ans++;
        }
    }

    cout <<ans <<endl;
    return 0;
}
