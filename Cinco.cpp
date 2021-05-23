#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e3+5;

int a[N];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    for(int i = 0; i<n; i++) cin >>a[i];

    bool swap1 = 0, swap2 = 0;
    for(int i = 0; i<n-1; i++){
        if((a[i] == 0 || a[i] == 5) && a[n-1] > a[i]){
            swap(a[i], a[n-1]);
            swap1 = 1; break;
        }
    }

    if(!swap1){
        for(int i = n-2; i>=0; i--){
            if(a[i] == 0 || a[i] == 5){
                swap(a[i], a[n-1]);
                swap2 = 1; break;
            }
        }
    }

    if(!swap1 && !swap2) cout <<-1 <<endl;
    else{
        for(int i = 0; i<n; i++) cout <<a[i] <<" ";
        cout <<endl;
    }

    return 0;
}
