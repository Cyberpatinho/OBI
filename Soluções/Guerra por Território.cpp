#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int arr[100050];

int main(){

    ios_base::sync_with_stdio(0);
    int n, sum = 0; cin >>n;
    for(int i = 0; i<n; i++){
        cin >>arr[i]; sum += arr[i];
    }

    int k = 0, aux = 0;
    for(int i = 0; i<n; i++){
        aux += arr[i];
        if(aux == sum/2){
            k = i+1; break;
        }
    }

    cout <<k <<endl;
    return 0;
}
