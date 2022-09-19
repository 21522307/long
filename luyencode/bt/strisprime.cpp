#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0){
            return false;
        }
    }
    return x >= 2;
}
int main(){
    int t;
    cin >> t;
    int a[26] = {0};
    string s;
    while(t--){
        cin >> s;
            for(int i = 0; i < (int)s.length(); ++i){
                a[s[i] - 'a']++;
            }
        bool check = true;
        int cnt = 0;
        for(int i = 0; i < 26; ++i){
            if(a[i]){
                cnt++;
                if(!isPrime(a[i])){
                    check = false;
                    break;
                }
            }
        }
        if(!isPrime(cnt)){
            check = false;
        }
        if(check){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
   }
return 0;
}