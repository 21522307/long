#include<bits/stdc++.h>

using namespace std;

bool isprime(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
        return true;
}
int main(){
    int n;
    cin >> n;
    int m = n;
    int s = 0;
    while (n > 0){
        s += n%10;
        n /=10;
    }   
    if (isprime(m) && isprime(s)){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}