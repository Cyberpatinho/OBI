#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int a[205], b[205];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++){
        cin >>a[i]; b[a[i]]++;
    }

    int ans = 0;
    for(int i = 1; i<=100; i++){
        if(b[i] >= b[ans]){
            ans = i;
        }
    }

    cout <<ans <<endl;

    return 0;
}
