#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int t;
vector<char> op;
vector<string> num;

int to_int(string s){
    int ret = 0, aux = 1;
    for(int i = s.size()-1; i>=0; i--){
        ret += (s[i]-'0')*aux;
        aux *= 10;
    }
    return ret;
}

int main(){

    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin >>n){
        if(!n) break;

        op.clear();
        num.clear();

        string s; cin >>s;
        string aux = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '+' || s[i] == '-'){
                op.push_back(s[i]);
                num.push_back(aux);
                aux = "";
            }
            else{
                aux += s[i];
                if(i == s.length()-1) num.push_back(aux);
            }
        }

        int ans = to_int(num[0]);
        for(int i = 1; i<num.size(); i++){
            if(op[i-1] == '+') ans += to_int(num[i]);
            else ans -= to_int(num[i]);
        }

        cout <<"Teste " <<++t <<endl <<ans <<endl <<endl;
    }

    return 0;
}
