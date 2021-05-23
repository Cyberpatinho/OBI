#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<string> dict;

int edit(string &s1, string &s2){

    int len1 = s1.length(), len2 = s2.length();
    int dp[len1+2][len2+2];

    for(int i = 0; i<len1; i++){
        for(int j = 0; j<len2; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min(1 + dp[i-1][j], 1 + dp[i][j-1]);
                dp[i][j] = min(dp[i][j], 1 + dp[i-1][j-1]);
            }
        }
    }

    return dp[len1-1][len2-1];
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    int n, m; cin >>n >>m;
    for(int i = 0; i<n; i++){
        cin >>s; dict.push_back('*' + s);
    }

    for(int i = 0; i<m; i++){
        cin >>s;
        s = '*' + s;
        for(int j = 0; j<dict.size(); j++){
            if(edit(s, dict[j]) <= 2) cout <<dict[j].substr(1) <<" ";
        }
        cout <<endl;
    }

    return 0;
}
