#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define D 0
#define E 1
#define F 2

int arr[3];

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int i, n; cin >>i >>n;
    arr[D] = arr[E] = arr[F] = i;

    int val;
    char op, a, b;
    while(n--){
        cin >>op;
        if(op == 'A'){
            cin >>a >>b >>val;
            if(a == 'D') arr[D] += val;
            if(b == 'D') arr[D] -= val;
            if(a == 'E') arr[E] += val;
            if(b == 'E') arr[E] -= val;
            if(a == 'F') arr[F] += val;
            if(b == 'F') arr[F] -= val;
        }
        if(op == 'V'){
            cin >>a >>val;
            if(a == 'D') arr[D] += val;
            if(a == 'E') arr[E] += val;
            if(a == 'F') arr[F] += val;
        }
        if(op == 'C'){
            cin >>a >>val;
            if(a == 'D') arr[D] -= val;
            if(a == 'E') arr[E] -= val;
            if(a == 'F') arr[F] -= val;
        }
    }

    cout <<arr[D] <<" " <<arr[E] <<" " <<arr[F] <<endl;

    return 0;
}
