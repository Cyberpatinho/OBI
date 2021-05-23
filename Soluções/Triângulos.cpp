#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define endl '\n'

bool is_triangle(int a, int b, int c){

    int arr[3] = {a, b, c};
    sort(arr, arr+3);
    return ((arr[1] + arr[0]) > arr[2]);
}

int type(int a, int b, int c){

    long double a1 = acos(((pow(b, 2) + pow(c, 2) - pow(a, 2))/(2*b*c)))*(180.0/PI);
    long double a2 = acos(((pow(a, 2) + pow(c, 2) - pow(b, 2))/(2*a*c)))*(180.0/PI);
    long double a3 = acos(((pow(a, 2) + pow(b, 2) - pow(c, 2))/(2*a*b)))*(180.0/PI);

    //cout <<a1 <<" " <<a2 <<" " <<a3 <<endl;
    //cout <<abs(90.0 - a1) <<" " <<abs(90.0 - a2) <<" " <<abs(90.0 - a3) <<endl;

    if((abs(90.0 - a1) < 1e-6) || (abs(90.0 - a2) < 1e-6) || (abs(90.0 - a3) < 1e-6)) return 1;
    if((a1 - 90.0 > 1e-6) || ((a2 - 90.0) > 1e-6) || ((a3 - 90.0) > 1e-6)) return 2;
    return 3;
}

int main(){

    ios_base::sync_with_stdio(0);
    int a, b, c; cin >>a >>b >>c;
    if(!is_triangle(a, b, c)) cout <<'n' <<endl;
    else{
        int ans = type(a, b, c);
        if(ans == 1) cout <<'r' <<endl;
        if(ans == 2) cout <<'o' <<endl;
        if(ans == 3) cout <<'a' <<endl;
    }

    return 0;
}
