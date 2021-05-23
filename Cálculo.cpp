#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

string sum(string s1, string s2){

    int len = s1.length();
    string ans = string(len, '0');

    int rem = 0;
    for(int i = len-1; i >= 0; i--){
        if(s1[i] == '0' && s2[i] == '0'){
            if(rem){
                ans[i] = '1';
                rem--;
            }
            else continue;
        }
        else if(s1[i] == '1' && s2[i] == '1'){
            if(rem){
                ans[i] = '1';
            }
            else rem++;
        }
        else{
            if(rem) continue;
            else ans[i] = '1';
        }
    }

    return ans;
}


int main(){

    ios_base::sync_with_stdio(0);
    int n, m; cin >>n >>m;
    string s1 = "", s2 = ""; char c;
    for(int i = 0; i<n; i++){
        cin >>c; s1 += c;
    }
    for(int i = 0; i<m; i++){
        cin >>c; s2 += c;
    }

    int len1 = s1.length(), len2 = s2.length();
    if(len2 > len1) s1 += string(len2-len1, '0');
    if(len1 > len2) s2 += string(len1-len2, '0');

    string ans = sum(s1, s2);

    int end = ans.length();
    for(int i = ans.length()-1; i >= 0; i--){
        if(ans[i] == '1') break;
        else end = i;
    }

    for(int i = 0; i < end; i++){
        cout <<ans[i] <<" ";
    }
    cout <<endl;
    return 0;
}
