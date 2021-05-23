#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int LIS(const string &s){

    vector<char> st;
    for(int i = 0; s[i]; i++){
        vector<char> :: iterator it = upper_bound(st.begin(), st.end(), s[i]);
        if(it == st.end()) st.push_back(s[i]);
        else *it = s[i];
    }

    return st.size();
}

int main(){

    ios_base::sync_with_stdio(0);
    string s; cin >>s;

    int ans = LIS(s);

    cout <<ans <<endl;
    return 0;
}
