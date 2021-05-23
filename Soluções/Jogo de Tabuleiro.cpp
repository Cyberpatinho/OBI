#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int mat[105][105];

int main(){

    ios_base::sync_with_stdio(0);
    int n; cin >>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >>mat[i][j];
        }
    }

    int arr[2];
    for(int i = 2; i<=n; i++){

        arr[0] = arr[1] = 0;
        arr[mat[i-1][i-1]]++; arr[mat[i-1][i]]++; arr[mat[i][i-1]]++;
        mat[i][i] = (arr[0] > arr[1]);

        for(int j = i+1; j<=n; j++){
            arr[0] = arr[1] = 0;
            arr[mat[i-1][j-1]]++; arr[mat[i-1][j]]++; arr[mat[i][j-1]]++;
            mat[i][j] = (arr[0] > arr[1]);
        }

        for(int j = i+1; j<=n; j++){
            arr[0] = arr[1] = 0;
            arr[mat[j-1][i-1]]++; arr[mat[j-1][i]]++; arr[mat[j][i-1]]++;
            mat[j][i] = (arr[0] > arr[1]);
        }

    }

    /*
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cout <<mat[i][j] <<" ";
        }
        cout <<endl;
    }*/

    cout <<mat[n][n] <<endl;
    return 0;
}
